#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Component.h"
#include "animation\AnimatedSprite.hpp"

class AnimatedComponent
	: public Component
{
public:

	void Init(std::string p_filename);
	void Draw(sf::RenderWindow & p_renderWindow);

	void AddAnimation(const std::string p_animationName, Animation* p_animationPointer);
	void AddAnimationFrame(std::string p_animationName, sf::IntRect p_rect);
	
	void Play(const Animation & p_animation);

	void SetCurrentAnimation(std::string p_animationName);
	void SetLoop(bool p_loopEnabled);

	const bool IsLooping() const;
	const bool IsLoaded() const;

private:

	std::string m_filename;
	sf::Texture m_spriteSheet;
	std::map<std::string, Animation*> m_animations;
	AnimatedSprite m_animatedSprite;
	Animation* m_currentAnimation;
	sf::Time m_frameTime;
	bool m_loopEnabled;
	bool m_isLoaded;

};