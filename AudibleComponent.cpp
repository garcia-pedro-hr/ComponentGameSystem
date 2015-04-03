#include "AudibleComponent.h"

#include <cassert>

// Inicializando o nome do componente como "AudibleComponent", desta forma, todos os componentes desta natureza terão o mesmo nome.
const char* AudibleComponent::g_name = "AudibleComponent";

void AudibleComponent::Init(const std::string p_filename)
{
    if (this->m_buffer.loadFromFile(p_filename) == false)
    {
        this->m_filename = "";
        this->m_isLoaded = false;

        assert(0 && std::string("Error loading the sound: " + p_filename).c_str());
    }
    else
    {
        this->m_filename = p_filename;
        this->m_sound.setBuffer(this->m_buffer);
        this->m_loopEnabled = false;
        this->m_isLoaded = true;
    }
}

void AudibleComponent::Play()
{
    this->m_sound.play();
}

void AudibleComponent::Stop()
{
    this->m_sound.stop();
}

void AudibleComponent::Pause()
{
    this->m_sound.pause();
}

void AudibleComponent::SetLoop(const bool p_loopEnabled)
{
    this->m_loopEnabled = p_loopEnabled;
    this->m_sound.setLoop(this->m_loopEnabled);
}

void AudibleComponent::SetPitch(const float p_pitch)
{
    this->m_sound.setPitch(p_pitch);
}

sf::Sound* AudibleComponent::GetSound()
{
    return &this->m_sound;
}

std::string AudibleComponent::GetName()
{
    return this->g_name;
}

const bool AudibleComponent::IsLoaded() const
{
    return this->m_isLoaded;
}