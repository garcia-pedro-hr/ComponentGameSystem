#include "DrawableComponent.h"

#include <cassert>

// Inicializando o nome do componente como "DrawableComponent", desta forma, todos os componentes desta natureza terão o mesmo nome.
const char* DrawableComponent::g_name = "DrawableComponent";


void DrawableComponent::Init(const std::string filename)
{
	if (this->m_texture.loadFromFile(filename) == false)
	{
		this->m_filename = "";
		this->m_isLoaded = false;

        assert(0 && std::string("Could not load the image from: " + filename).c_str());
	}
	else 
	{
		this->m_filename = filename;
		this->m_sprite.setTexture(this->m_texture);
		this->m_isLoaded = true;
	}
} // EOInit


const int DrawableComponent::GetHeight(void)
{
	return this->m_texture.getSize().y;
} //EOGetHeight


const int DrawableComponent::GetWidth(void)
{
	return this->m_texture.getSize().x;
} //EOGetWidth


sf::Sprite* DrawableComponent::GetSprite()
{
	return &this->m_sprite;
} // EOGetSprite


std::string DrawableComponent::GetName()
{
	return this->g_name;
} // EOGetName


const bool DrawableComponent::IsLoaded() const
{
	return this->m_isLoaded;
} // EOIsLoaded