#ifndef HEXGRAM_HPP
#define HEXGRAM_HPP

#include <cstdint>
#include <vector>

#include "avatar.hpp"
#include "grid.hpp"

struct Hexgram
{
    Hexgram();

    void Load();
    void Save();

    void Clear();

    void ProcessNextStep();
    void ApplyNextStep();
    void Reset();

    bool IsFinished();

    Avatar* GetAvatar(uint16_t x, uint16_t y);
    uint16_t GetAvatarId(uint16_t x, uint16_t y);

    bool IsAvatarIn(uint16_t x, uint16_t y);

    AvatarList m_avatars;
    Grid m_grid;

    uint32_t m_steps;
    bool m_updated;

    uint16_t m_startTile;
    std::vector<uint16_t> m_endTiles;
};

#endif