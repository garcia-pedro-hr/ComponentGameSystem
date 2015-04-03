#include "TransformableComponent.h"

// Inicializando o nome do componente como "TransformableComponent", desta forma, todos os componentes desta natureza terão o mesmo nome.
const char* TransformableComponent::g_name = "TransformableComponent";


TransformableComponent::TransformableComponent() :
	m_position(sf::Vector2i(0, 0)), m_scale(sf::Vector2f(1.0f, 1.0f)), m_rotation(0.0f)
{
} //EOConstructor


void TransformableComponent::SetPosition(const sf::Vector2i p_positionVector)
{
	this->m_position = p_positionVector;
} //EOSetPosition (withVector)


void TransformableComponent::SetPosition(const int p_posX, const int p_posY)
{
	this->m_position = sf::Vector2i(p_posX, p_posY);
} //EOSetPosition (withCoordinates)


void TransformableComponent::SetScale(const sf::Vector2f p_scaleVector)
{
	this->m_scale = p_scaleVector;
} //EOSetScale (withVector)


void TransformableComponent::SetScale(const float p_scaleX, const float p_scaleY)
{
	this->m_scale = sf::Vector2f(p_scaleX, p_scaleY);
} //EOSetScale (withCoordinates)


void TransformableComponent::SetRotation(const float p_angle)
{
	this->m_rotation = p_angle;
} //EOSetRotation


const sf::Vector2i TransformableComponent::GetPosition(void) const
{
	return this->m_position;
} //EOGetPosition()


const sf::Vector2f TransformableComponent::GetScale(void) const
{
	return this->m_scale;
} //EOGetScale


const float TransformableComponent::GetRotation(void) const
{
	return this->m_rotation;
} //EOGetRotation


std::string TransformableComponent::GetName(void)
{
	return this->g_name;
} //EOGetName