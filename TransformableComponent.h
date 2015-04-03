#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"

class TransformableComponent
	: public Component
{
public:

	static const char* g_name;

	TransformableComponent();

	void SetPosition(const sf::Vector2i p_positionVector);
	void SetPosition(const int p_posX, const int p_posY);
	void SetScale(const sf::Vector2f p_scale);
	void SetScale(const float p_scaleX, const float p_scaleY);
	void SetRotation(const float p_angle);

	const sf::Vector2i GetPosition() const;
	const sf::Vector2f GetScale() const;
	const float GetRotation() const;
	virtual std::string GetName() override;

private:

	sf::Vector2i m_position;
	sf::Vector2f m_scale;
	float m_rotation;

};