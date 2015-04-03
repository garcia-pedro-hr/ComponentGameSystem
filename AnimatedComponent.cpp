#include "stdafx.h"
#include "AnimatedComponent.h"

void AnimatedComponent::Init(const std::string p_filename)
{
	if (this->m_spriteSheet.loadFromFile(p_filename) == false)
	{
		this->m_filename = "";
		this->m_isLoaded = false;
	}
	else
	{
		this->m_filename = p_filename;
		this->m_isLoaded = true;
	}
}

void AnimatedComponent::Draw(sf::RenderWindow & p_renderWindow)
{
	if (this->IsLoaded())
	{
		p_renderWindow.draw(this->m_animatedSprite);
	}
}

void AnimatedComponent::AddAnimation(const std::string p_animationName, Animation* p_animationPointer)
{
	p_animationPointer->setSpriteSheet(this->m_spriteSheet);

	this->m_animations.insert(std::pair<std::string, Animation*>(p_animationName, p_animationPointer));
}

void AnimatedComponent::AddAnimationFrame(const std::string p_animationName, sf::IntRect p_rect)
{
	Animation* animationPointer = new Animation();

	std::map<std::string, Animation*>::const_iterator results = this->m_animations.find(p_animationName);
	if(results != this->m_animations.end())
	{
		animationPointer = results->second;
		animationPointer->addFrame(p_rect);
	}
}

void AnimatedComponent::Play(const Animation & p_animation)
{
	this->m_animatedSprite.play(p_animation);
}

void AnimatedComponent::SetCurrentAnimation(std::string p_animationName)
{
	std::map<std::string, Animation*>::const_iterator results = this->m_animations.find(p_animationName);
	if(results != this->m_animations.end())
	{
		this->m_currentAnimation = results->second;
	}
}

const bool AnimatedComponent::IsLooping(void) const
{
	return this->m_loopEnabled;
}

const bool AnimatedComponent::IsLoaded(void) const
{
	return this->m_isLoaded;
}