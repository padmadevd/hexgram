#include "avatar.hpp"
#include <cstdint>
#include <vector>

Avatar::Avatar(uint8_t id)
    : m_id(id), m_dir(0), m_nextDir(0), m_x(0), m_y(0), m_nextX(0), m_nextY(0), m_col(0), m_nextCol(0), m_willDie(false), m_willBorn(false)
{
}

AvatarList::AvatarList()
{
    m_buffer.push_back(nullptr);
    m_lastId = 1;
    m_avatarsCount = 0;
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
void AvatarList::DeleteAvatar(uint16_t id)
{
    if(id >= m_buffer.size()) return;
    if(m_buffer[id] == nullptr) return;

    m_unusedIds.push_back(id);
    m_buffer[id] = nullptr;
    delete m_buffer[id];

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