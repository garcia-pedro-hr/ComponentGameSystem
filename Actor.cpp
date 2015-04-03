#include "Actor.h"

#include <cassert>

Actor::Actor()
{
} // EOConstructor


Actor::Actor(std::string p_name, int p_ID ) :
    m_name(p_name), m_actorID(p_ID)
{
} // EOConstructor


Actor::~Actor(void)
{
    Destroy();
} // EODestructor


void Actor::Destroy(void)
{
    // Nunca chame explicitamente o destrutor.
    for (auto& componentIt : m_components)
    {
        Component* pComponent = componentIt.second;

        if (pComponent != nullptr)
        {
            delete pComponent;
            pComponent = nullptr;
        }
    }
} // EODestroy


void Actor::SetName(const std::string p_name)
{
    this->m_name = p_name;
} // EOSetName


void Actor::SetID(const int p_ID)
{
    this->m_actorID = p_ID;
} // EOSetID


const int Actor::GetActorID(void) const
{
    return this->m_actorID;
} // EOGetActorID


const std::string Actor::GetName(void)
{
    return this->m_name;
} // EOGetName


void Actor::AddComponent(Component* p_component)
{
    assert(p_component != nullptr);

    this->m_components.insert(std::pair<std::string, Component*>(p_component->GetName(), p_component));
} // EOAddComponent


Component* Actor::GetComponent(std::string p_componentName)
{
    std::map<std::string, Component*>::const_iterator results = this->m_components.find(p_componentName);
    if(results == this->m_components.end())
        return NULL;
    return results->second;
} // EOGetComponent