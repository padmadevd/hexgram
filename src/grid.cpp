#include "grid.hpp"
#include <cstdint>
#include <vector>

Grid::Grid()
{
    m_tilesBuffer.push_back(nullptr);
    m_lastTileId = 1;
}

Grid::~Grid()
{
    for(Tile *tile : m_tilesBuffer)
    {
        if(tile != nullptr) delete tile;
    }
}

void Grid::Clear()
{
    for(Tile *tile : m_tilesBuffer)
    {
        if(tile != nullptr) delete tile;
    }
    m_tilesBuffer.clear();

    m_tilesBuffer.push_back(nullptr);
    m_lastTileId = 1;

    m_unusedTileIds.clear();

    m_grid.clear();
}

uint16_t Grid::AddTile(Tile *src, uint16_t x, uint16_t y)
{
    if(!IsCellEmpty(x, y)) return 0;

    uint16_t id;
    if(!m_unusedTileIds.empty())
    {
        id = m_unusedTileIds.back();
        m_unusedTileIds.pop_back();
    }
    else
    {
        id = m_lastTileId;
        m_lastTileId++;

        m_tilesBuffer.push_back(nullptr);
    }

    if(src->m_type == TILE_BLANK)
    {
        m_tilesBuffer[id] = new TileBlank(*((TileBlank*)src));
    }
    else if(src->m_type == TILE_START)
    {
        m_tilesBuffer[id] = new TileStart(*((TileStart*)src));
    }
    else if(src->m_type == TILE_END)
    {
        m_tilesBuffer[id] = new TileEnd(*((TileEnd*)src));
    }
    else if(src->m_type == TILE_NORMAL)
    {
        m_tilesBuffer[id] = new TileNormal(*((TileNormal*)src));
    }
    else if(src->m_type == TILE_SPLIT)
    {
        m_tilesBuffer[id] = new TileSplit(*((TileSplit*)src));
    }
    else if(src->m_type == TILE_ASSIGN)
    {
        m_tilesBuffer[id] = new TileAssign(*((TileAssign*)src));
    }
    else if(src->m_type == TILE_INCREMENT)
    {
        m_tilesBuffer[id] = new TileIncrement(*((TileIncrement*)src));
    }
    else if(src->m_type == TILE_DECREMENT)
    {
        m_tilesBuffer[id] = new TileDecrement(*((TileDecrement*)src));
    }
    else if(src->m_type == TILE_LOCK)
    {
        m_tilesBuffer[id] = new TileLock(*((TileLock*)src));
    }
    else if(src->m_type == TILE_KEY)
    {
        m_tilesBuffer[id] = new TileKey(*((TileKey*)src));
    }
    m_tilesBuffer[id]->m_id = id;
    m_tilesBuffer[id]->m_x = x;
    m_tilesBuffer[id]->m_y = y;

    m_grid[x][y] = id;

    return id;
}
void Grid::DeleteTile(uint16_t id)
{
    if(id >= m_tilesBuffer.size()) return;
    if(m_tilesBuffer[id] == nullptr) return;

    uint16_t x = m_tilesBuffer[id]->m_x;
    uint16_t y = m_tilesBuffer[id]->m_y;
    m_grid[x][y] = 0;

    delete m_tilesBuffer[id];
    m_tilesBuffer[id] = nullptr;

    m_unusedTileIds.push_back(id);
}

Tile* Grid::GetTile(uint16_t id)
{
    return m_tilesBuffer[id];
}
Tile* Grid::GetTile(uint16_t x, uint16_t y)
{
    return m_tilesBuffer[m_grid[x][y]];
}
uint16_t Grid::GetTileId(uint16_t x, uint16_t y)
{
    return m_grid[x][y];
}
std::vector<uint16_t> Grid::GetAllTiles()
{
    std::vector<uint16_t> tiles;
    for(Tile* tile : m_tilesBuffer)
    {
        if(tile != nullptr) tiles.push_back(tile->m_id);
    }
    return tiles;
}

bool Grid::IsCellEmpty(uint16_t x, uint16_t y)
{
    if(m_grid.find(x) == m_grid.end() || m_grid[x].find(y) == m_grid[x].end()) return true;
    return m_grid[x][y] == 0;
}

void Grid::MoveTile(uint16_t id, uint16_t x, uint16_t y)
{
    if(id >= m_tilesBuffer.size()) return;
    if(m_tilesBuffer[id] == nullptr) return;

    if(!IsCellEmpty(x, y)) return;

    Tile *tile = m_tilesBuffer[id];
    m_grid[tile->m_x][tile->m_y] = 0;
    m_grid[x][y] = id;
    tile->m_x = x;
    tile->m_y = y;
}

uint16_t Grid::GetAdjTile(uint16_t id, uint8_t dir)
{
    if(id == 0) return 0;
    
    Tile *tile = m_tilesBuffer[id];
    uint16_t adjX = GetAdjX(tile->m_x, tile->m_y, dir);
    uint16_t adjY = GetAdjY(tile->m_x, tile->m_y, dir);

    if(!IsCellEmpty(adjX, adjY)) return m_grid[adjX][adjY];
    return 0;
}
uint16_t Grid::GetAdjX(uint16_t x, uint16_t y, uint8_t dir)
{
    if(dir == 0) return x;
    else if(dir == 1) return x+1;
    else if(dir == 2) return x+1;
    else if(dir == 3) return x;
    else if(dir == 4) return x-1;
    else return x-1;
}
uint16_t Grid::GetAdjY(uint16_t x, uint16_t y, uint8_t dir)
{
    if(dir == 0) return y+1;
    else if(dir == 1) return ((x%2 == 0)?y:y+1);
    else if(dir == 2) return ((x%2 == 0)?y-1:y);
    else if(dir == 3) return y-1;
    else if(dir == 4) return ((x%2 == 0)?y-1:y);
    else return ((x%2 == 0)?y:y+1);
}