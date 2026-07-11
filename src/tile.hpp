#ifndef TILE_HPP
#define TILE_HPP

#include <cstdint>
#include <queue>

#define TILE_BLANK 0
#define TILE_START 1
#define TILE_END 2
#define TILE_NORMAL 3
#define TILE_SPLIT 4
#define TILE_ASSIGN 5
#define TILE_INCREMENT 6
#define TILE_DECREMENT 7
#define TILE_LOCK 8
#define TILE_KEY 9

struct Tile
{
    Tile(uint8_t id, uint8_t type);

    uint16_t m_id;
    uint8_t m_type;

    uint8_t m_col;

    uint16_t m_x;
    uint16_t m_y;

    uint8_t m_rot;
    uint8_t m_dir;
};

struct TileBlank : Tile
{
    TileBlank(uint8_t id);
};

struct TileStart : Tile
{
    TileStart(uint8_t id);

    std::queue<uint8_t> m_inputQueue;
};

struct TileEnd : Tile
{
    TileEnd(uint8_t id);

    std::queue<uint8_t> m_outputQueue;
};

struct TileNormal : Tile
{
    TileNormal(uint8_t id);
};

struct TileSplit : Tile
{
    TileSplit(uint8_t id);

    uint8_t m_splitDir;
};

struct TileAssign : Tile
{
    TileAssign(uint8_t id);

    bool m_dynamic;
};

struct TileIncrement : Tile
{
    TileIncrement(uint8_t id);
};

struct TileDecrement : Tile
{
    TileDecrement(uint8_t id);
};

struct TileLock : Tile
{
    TileLock(uint8_t id);

    uint8_t m_keyId;
};

struct TileKey : Tile
{
    TileKey(uint8_t id);

    uint8_t m_lockId;
};

#endif