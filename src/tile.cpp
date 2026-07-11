#include "tile.hpp"

#include "color.hpp"
#include <cstdint>

Tile::Tile(uint8_t id, uint8_t type)
    : m_id(id), m_type(type), m_col(COLOR_VIOLET), m_x(0), m_y(0), m_dir(0), m_rot(0), m_currAvatarId(0), m_nextAvatarId(0)
{   
}
Tile::~Tile()
{
}

TileBlank::TileBlank(uint8_t id)
    : Tile(id, TILE_BLANK)
{
}
TileBlank::~TileBlank()
{
}

TileStart::TileStart(uint8_t id)
    : Tile(id, TILE_START)
{
}
TileStart::~TileStart()
{
}

TileEnd::TileEnd(uint8_t id)
    : Tile(id, TILE_END)
{
}
TileEnd::~TileEnd()
{
}

TileNormal::TileNormal(uint8_t id)
    : Tile(id, TILE_NORMAL)
{
}
TileNormal::~TileNormal()
{
}

TileSplit::TileSplit(uint8_t id)
    : Tile(id, TILE_SPLIT), m_splitDir(0)
{
}
TileSplit::~TileSplit()
{
}

TileAssign::TileAssign(uint8_t id)
    : Tile(id, TILE_ASSIGN), m_dynamic(false)
{
}
TileAssign::~TileAssign()
{
}

TileIncrement::TileIncrement(uint8_t id)
    : Tile(id, TILE_INCREMENT)
{
}
TileIncrement::~TileIncrement()
{
}

TileDecrement::TileDecrement(uint8_t id)
    : Tile(id, TILE_DECREMENT)
{
}
TileDecrement::~TileDecrement()
{
}

TileLock::TileLock(uint8_t id)
    : Tile(id, TILE_LOCK), m_keyId(0)
{
}
TileLock::~TileLock()
{
}

TileKey::TileKey(uint8_t id)
    : Tile(id, TILE_KEY), m_lockId(0)
{
}
TileKey::~TileKey()
{
}