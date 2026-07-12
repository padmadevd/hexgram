#include "hexgram.hpp"
#include "avatar.hpp"
#include "color.hpp"
#include "tile.hpp"
#include <cstdint>
#include <vector>

Hexgram::Hexgram()
    : m_steps(0), m_updated(false), m_startTile(0)
{
}

void Hexgram::Load()
{
}
void Hexgram::Save()
{
}

void Hexgram::Clear()
{
    m_avatars.Clear();
    m_grid.Clear();

    m_steps = 0;
    m_updated = false;

    m_startTile = 0;
    m_endTiles.clear();
}

void Hexgram::ProcessNextStep()
{
    m_updated = false;

    if(m_startTile)
    {
        TileStart *tile = (TileStart*)m_grid.GetTile(m_startTile);
        if(tile->m_currAvatarId == 0 && !tile->m_inputQueue.empty())
        {
            uint8_t col = tile->m_inputQueue.front();
            tile->m_inputQueue.pop();

            uint8_t dir = tile->m_dir + tile->m_rot;

            Avatar *avatar = m_avatars.GetAvatar(m_avatars.AddAvatar(dir, tile->m_x, tile->m_y, col));
            avatar->m_willBorn = true;

            tile->m_nextAvatarId = avatar->m_id;

            m_updated = true;
        }
    }

    std::vector<uint16_t> avatarIds = m_avatars.GetAllAvatars();
    for(uint16_t avatarId : avatarIds)
    {
        Avatar *avatar = m_avatars.GetAvatar(avatarId);

        if(avatar->m_willBorn) continue;

        uint16_t x = avatar->m_x;
        uint16_t y = avatar->m_y;

        Tile *tile = m_grid.GetTile(x, y);

        if(tile->m_type == TILE_END)
        {
            if(tile->m_col == COLOR_ALL || tile->m_col == avatar->m_col)
            {
                avatar->m_willReach = true;

                tile->m_nextAvatarId = 0;

                m_updated = true;
            }
        }
        else
        {
            int dir = 0;
            if(tile->m_type == TILE_SPLIT)
            {
                if(avatar->m_col == tile->m_col)
                {
                    dir = tile->m_rot + ((TileSplit*)tile)->m_splitDir;
                }
                else
                {
                    dir = tile->m_rot + tile->m_dir;
                }
            }
            else
            {
                dir = tile->m_rot + tile->m_dir;
            }

            uint16_t nextX = m_grid.GetAdjX(x, y, dir);
            uint16_t nextY = m_grid.GetAdjY(x, y, dir);

            if(m_grid.IsCellEmpty(nextX, nextY))
            {
                avatar->m_nextX = nextX;
                avatar->m_nextY = nextY;
                avatar->m_nextDir = dir;
                avatar->m_willDie = true;

                tile->m_nextAvatarId = 0;

                m_updated = true;
            }
            else
            {
                Tile *nextTile = m_grid.GetTile(x, y);
                if(nextTile->m_currAvatarId == 0 && nextTile->m_nextAvatarId == 0)
                {
                    if(nextTile->m_type != TILE_BLANK && nextTile->m_type != TILE_LOCK)
                    {
                        avatar->m_nextX = nextX;
                        avatar->m_nextY = nextY;
                        avatar->m_nextDir = dir;

                        if(nextTile->m_type == TILE_ASSIGN)
                        {
                            TileAssign *tileAssign = (TileAssign*)nextTile;
                            avatar->m_nextCol = tileAssign->m_col;
                            if(tileAssign->m_dynamic) tileAssign->m_col = (tileAssign->m_col+1)%COLOR_ALL;
                        }
                        else if(nextTile->m_type == TILE_INCREMENT)
                        {
                            avatar->m_nextCol = (avatar->m_col+1)%COLOR_ALL;
                        }
                        else if(nextTile->m_type == TILE_DECREMENT)
                        {
                            avatar->m_nextCol = (avatar->m_col+COLOR_ALL-1)%COLOR_ALL;
                        }

                        tile->m_nextAvatarId = 0;
                        nextTile->m_nextAvatarId = avatarId;

                        m_updated = true;
                    }
                    else if(nextTile->m_type == TILE_LOCK)
                    {
                        uint16_t keyId = ((TileLock*)nextTile)->m_keyId;
                        if(keyId != 0)
                        {
                            TileKey *tileKey = (TileKey*)m_grid.GetTile(keyId);
                            if(tileKey->m_currAvatarId != 0)
                            {
                                avatar->m_nextX = nextX;
                                avatar->m_nextY = nextY;
                                avatar->m_nextDir = dir;

                                tile->m_nextAvatarId = 0;
                                nextTile->m_nextAvatarId = avatarId;

                                m_updated = true;
                            }
                        }
                    }
                }
            }
        }
    }
}
void Hexgram::ApplyNextStep()
{
    if(!m_updated) return;

    std::vector<uint16_t> tileIds = m_grid.GetAllTiles();
    for(uint16_t tileId : tileIds)
    {
        Tile *tile = m_grid.GetTile(tileId);

        tile->m_currAvatarId = tile->m_nextAvatarId;
        tile->m_nextAvatarId = 0;
    }

    std::vector<uint16_t> avatarIds = m_avatars.GetAllAvatars();
    for(uint16_t avatarId : avatarIds)
    {
        Avatar *avatar = m_avatars.GetAvatar(avatarId);

        if(avatar->m_willBorn)
        {
            avatar->m_willBorn = false;
        }
        else if(avatar->m_willReach)
        {
            TileEnd *tileEnd = (TileEnd*)m_grid.GetTile(avatar->m_x, avatar->m_y);
            tileEnd->m_outputQueue.push(avatar->m_col);
        }
        else
        {
            avatar->m_x = avatar->m_nextX;
            avatar->m_y = avatar->m_nextY;

            avatar->m_dir = avatar->m_nextDir;

            avatar->m_col = avatar->m_nextCol;
        }

        if(avatar->m_willReach || avatar->m_willDie)
        {
            m_avatars.DeleteAvatar(avatarId);
        }
    }

    m_steps++;
}

void Hexgram::Reset()
{
    m_steps = 0;
    m_updated = false;
    m_avatars.Clear();
}

bool Hexgram::IsFinished()
{
    if(m_avatars.m_avatarsCount == 0) return true;
    return !m_updated;
}

Avatar* Hexgram::GetAvatar(uint16_t x, uint16_t y)
{
    return m_avatars.m_buffer[m_grid.GetTile(x, y)->m_currAvatarId];
}
uint16_t Hexgram::GetAvatarId(uint16_t x, uint16_t y)
{
    return m_grid.GetTile(x, y)->m_currAvatarId;
}

bool Hexgram::IsAvatarIn(uint16_t x, uint16_t y)
{
    if(m_grid.IsCellEmpty(x, y)) return false;
    return m_grid.GetTile(x, y)->m_currAvatarId != 0;
}