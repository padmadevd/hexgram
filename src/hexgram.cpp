#include "hexgram.hpp"

Hexgram::Hexgram()
    : m_steps(0), m_updated(false), m_inputTile(0)
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

    m_inputTile = 0;
    m_outputTiles.clear();
}

void Hexgram::ProcessNextStep()
{
    
}
void Hexgram::ApplyNextStep()
{

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