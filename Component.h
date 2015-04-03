#pragma once

#include <string>

class Component
{
public:

	virtual ~Component();

	virtual void Init();

	virtual std::string Component::GetName() = 0;

private:

};