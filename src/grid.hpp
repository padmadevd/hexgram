#ifndef GRID_HPP
#define GRID_HPP

#include <cstdint>
#include <vector>
#include <map>

#include "tile.hpp"

struct Grid
{
    Grid();
    ~Grid();

    void Clear();

    uint16_t AddTile(Tile *src, uint16_t x, uint16_t y);
    void DeleteTile(uint16_t id);

    Tile* GetTile(uint16_t id);
    Tile* GetTile(uint16_t x, uint16_t y);
    uint16_t GetTileId(uint16_t x, uint16_t y);

    std::vector<uint16_t> GetAllTiles();

    bool IsCellEmpty(uint16_t x, uint16_t y);

    void MoveTile(uint16_t id, uint16_t x, uint16_t y);

    uint16_t GetAdjTile(uint16_t id, uint8_t dir);
    uint16_t GetAdjX(uint16_t x, uint16_t y, uint8_t dir);
    uint16_t GetAdjY(uint16_t x, uint16_t y, uint8_t dir);

    uint16_t m_lastTileId;
    std::vector<Tile*> m_tilesBuffer;
    std::vector<uint16_t> m_unusedTileIds;

    std::map<uint16_t, std::map<uint16_t, uint16_t>> m_grid;
};

#endif