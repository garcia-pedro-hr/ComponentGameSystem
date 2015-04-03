#pragma once

#include <algorithm>
#include <string>
#include <map>
#include <memory>	// para shared_ptr e weak_ptr

#include "Component.h"

class Actor;
typedef unsigned int ActorID;
typedef std::shared_ptr<Actor> ActorSharedPointer;
typedef std::weak_ptr<Actor> ActorWeakPointer;

class Actor 
{
public:
    
    Actor();
    Actor(std::string p_name, int p_ID);
    ~Actor();

    void Destroy();

    void SetName(const std::string p_name);
    void SetID(const int p_ID);

    void AddComponent(Component* p_component);

    const int GetActorID(void) const;
    const std::string GetName(void);
    Component* GetComponent(std::string p_componentName);

    // Variável de GetComponent() com template.
    template<class ComponentType> ComponentType* GetComponent(const std::string & p_componentName)
    {
        Component* pComponent = GetComponent(p_componentName);
        return dynamic_cast<ComponentType*>(pComponent);
    }

private:

    std::string m_name;
    std::map<std::string, Component*> m_components;
    int m_actorID;
};
