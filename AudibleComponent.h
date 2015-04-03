#pragma once 

#include <SFML/Audio.hpp>

#include "Component.h"

class AudibleComponent
	: public Component
{
public:

	static const char* g_name;

	void Init(std::string p_filename);

	void Play();
	void Pause();
	void Stop();

	void SetLoop(bool p_loopEnabled);
	void SetPitch(float p_pitch);

	sf::Sound* GetSound();
	virtual std::string GetName() override;

	const bool IsLoaded() const;

private:

	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;
	std::string m_filename;
	bool m_loopEnabled;
	bool m_isLoaded;

};