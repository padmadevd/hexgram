#include "tile.hpp"

#include "color.hpp"
#include <cstdint>

Tile::Tile(uint8_t id, uint8_t type)
    : m_id(id), m_type(type), m_col(COLOR_VIOLET), m_x(0), m_y(0), m_dir(0), m_rot(0)
{   
}

TileBlank::TileBlank(uint8_t id)
    : Tile(id, TILE_BLANK)
{
}

TileStart::TileStart(uint8_t id)
    : Tile(id, TILE_START)
{
}

TileEnd::TileEnd(uint8_t id)
    : Tile(id, TILE_END)
{
}

TileNormal::TileNormal(uint8_t id)
    : Tile(id, TILE_NORMAL)
{
}

TileSplit::TileSplit(uint8_t id)
    : Tile(id, TILE_SPLIT), m_splitDir(0)
{
}

TileAssign::TileAssign(uint8_t id)
    : Tile(id, TILE_ASSIGN), m_dynamic(false)
{
}

TileIncrement::TileIncrement(uint8_t id)
    : Tile(id, TILE_INCREMENT)
{
}

TileDecrement::TileDecrement(uint8_t id)
    : Tile(id, TILE_DECREMENT)
{
}

TileLock::TileLock(uint8_t id)
    : Tile(id, TILE_LOCK), m_keyId(0)
{
}

TileKey::TileKey(uint8_t id)
    : Tile(id, TILE_KEY), m_lockId(0)
{
}