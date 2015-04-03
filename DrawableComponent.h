#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"

class DrawableComponent
	: public Component
{
public:

	static const char* g_name;

	void Init(std::string filename);

	const int GetHeight();
	const int GetWidth();
	sf::Sprite* GetSprite();
	virtual std::string GetName() override;

	const bool IsLoaded() const;

private:

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::string m_filename;
	bool m_isLoaded;

};