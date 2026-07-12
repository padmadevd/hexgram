#include "avatar.hpp"
#include <cstdint>
#include <vector>

Avatar::Avatar(uint8_t id)
    : m_id(id), m_dir(0), m_nextDir(0), m_x(0), m_y(0), m_nextX(0), m_nextY(0), m_col(0), m_nextCol(0), m_willDie(false), m_willBorn(false), m_willReach(false)
{
}

Avatar::Avatar(uint8_t id, uint8_t dir, uint16_t x, uint16_t y, uint8_t col)
    : m_id(id), m_dir(dir), m_nextDir(dir), m_x(x), m_y(y), m_nextX(x), m_nextY(y), m_col(col), m_nextCol(col), m_willDie(false), m_willBorn(false), m_willReach(false)
{
}

AvatarList::AvatarList()
{
    m_buffer.push_back(nullptr);
    m_lastId = 1;
    m_avatarsCount = 0;
}

AvatarList::~AvatarList()
{
    for(Avatar *avatar : m_buffer)
    {
        if(avatar != nullptr) delete avatar;
    }
}

void AvatarList::Clear()
{
    for(Avatar *avatar : m_buffer)
    {
        if(avatar != nullptr) delete avatar;
    }
    m_buffer.clear();

    m_buffer.push_back(nullptr);
    m_lastId = 1;
    m_avatarsCount = 0;

    m_unusedIds.clear();
}

uint16_t AvatarList::AddAvatar()
{
    uint16_t id;
    if(!m_unusedIds.empty())
    {
        id = m_unusedIds.back();
        m_unusedIds.pop_back();
    }
    else
    {
        id = m_lastId;
        m_lastId++;
        m_buffer.push_back(nullptr);
    }

    m_buffer[id] = new Avatar(id);
    m_avatarsCount++;

    return id;
}
uint16_t AvatarList::AddAvatar(uint8_t dir, uint16_t x, uint16_t y, uint8_t col)
{
    uint16_t id;
    if(!m_unusedIds.empty())
    {
        id = m_unusedIds.back();
        m_unusedIds.pop_back();
    }
    else
    {
        id = m_lastId;
        m_lastId++;
        m_buffer.push_back(nullptr);
    }

    m_buffer[id] = new Avatar(id, dir, x, y, col);
    m_avatarsCount++;

    return id;
}

void AvatarList::DeleteAvatar(uint16_t id)
{
    if(id >= m_buffer.size()) return;
    if(m_buffer[id] == nullptr) return;

    m_unusedIds.push_back(id);
    delete m_buffer[id];
    m_buffer[id] = nullptr;

    m_avatarsCount--;
}

Avatar* AvatarList::GetAvatar(uint16_t id)
{
    return m_buffer[id];
}

std::vector<uint16_t> AvatarList::GetAllAvatars()
{
    std::vector<uint16_t> avatars;
    for(Avatar *ref : m_buffer)
    {
        if(ref != nullptr) avatars.push_back(ref->m_id);
    }
    return avatars;
}