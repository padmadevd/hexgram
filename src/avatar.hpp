#ifndef AVATAR_HPP
#define AVATAR_HPP

#include <cstdint>
#include <vector>

struct Avatar
{
    Avatar(uint8_t id);
    Avatar(uint8_t id, uint8_t dir, uint16_t x, uint16_t y, uint8_t col);

    uint16_t m_id;

    uint8_t m_dir;
    uint8_t m_nextDir;

    uint16_t m_x;
    uint16_t m_y;
    uint16_t m_nextX;
    uint16_t m_nextY;

    uint8_t m_col;
    uint8_t m_nextCol;

    bool m_willBorn;
    bool m_willReach;
    bool m_willDie;
};

struct AvatarList
{
    AvatarList();
    ~AvatarList();

    void Clear();

    uint16_t AddAvatar();
    uint16_t AddAvatar(uint8_t dir, uint16_t x, uint16_t y, uint8_t col);
    void DeleteAvatar(uint16_t id);

    Avatar* GetAvatar(uint16_t id);
    std::vector<uint16_t> GetAllAvatars();

    uint16_t m_avatarsCount;

    uint16_t m_lastId;
    std::vector<Avatar*> m_buffer;
    std::vector<uint16_t> m_unusedIds;
};

#endif