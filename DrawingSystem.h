#pragma once

#include <assert.h>
#include <memory>
#include "Actor.h"
#include "DrawableComponent.h"
#include "TransformableComponent.h"

class DrawingSystem
{
public:

    DrawingSystem();
    DrawingSystem(sf::RenderWindow & p_renderWindow);

    void SetRenderWindow(sf::RenderWindow & p_renderWindow);
    sf::RenderWindow* GetRenderWindow();

    void AddActor(ActorWeakPointer pActor);
    void RemoveActor(const unsigned int p_actorID);

    void DrawAll();
    void DrawSpec(const unsigned int p_actorID);

private:

    std::map<unsigned int, ActorWeakPointer> m_actors;	// Mapa de atores no sistema.
    sf::RenderWindow* m_renderWindow;					// Ponteiro para a janela ativa.

};