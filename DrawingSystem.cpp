#include "DrawingSystem.h"

DrawingSystem::DrawingSystem() :
    m_renderWindow(NULL)
{
} // EOConstructor


DrawingSystem::DrawingSystem(sf::RenderWindow & p_renderWindow) :
    m_renderWindow(&p_renderWindow)
{
} // EOConstructor


void DrawingSystem::SetRenderWindow(sf::RenderWindow & p_renderWindow)
{
    this->m_renderWindow = &p_renderWindow;
} // EOSetRenderWindow

void DrawingSystem::AddActor(ActorWeakPointer pActor)
{      
	// Transforma pActor em um shared_ptr
    ActorSharedPointer pSharedActor = pActor.lock();
    assert(pSharedActor != nullptr);

	// Insere o ponteiro no mapa de atores do subsistema.
    m_actors.insert(std::make_pair(pSharedActor->GetActorID(), pActor));
}

void DrawingSystem::RemoveActor(const unsigned int p_actorID)
{
    auto& findIt = m_actors.find(p_actorID);
    if (findIt == m_actors.end())
    {
        return;
    }

    m_actors.erase(findIt);
}

sf::RenderWindow* DrawingSystem::GetRenderWindow()
{
    return this->m_renderWindow;
} // EOGetRenderWindow


void DrawingSystem::DrawAll()
{
    for (auto& actorIterator : m_actors)
    {
        ActorWeakPointer pWeakActor = actorIterator.second;
        std::shared_ptr<Actor> actorPointer = pWeakActor.lock();
        if (actorPointer == nullptr)
        {
            // Opcionalmente, este ator poderia ser removido.
            continue;
        }

        DrawableComponent* renderDataPointer = actorPointer->GetComponent<DrawableComponent>(DrawableComponent::g_name);
        TransformableComponent* transformPointer = actorPointer->GetComponent<TransformableComponent>(TransformableComponent::g_name);

        // assert() é uma condição que deve ser válida para o funcionamento do código.
        // Elas servem para informar programadores sobre erros de lógica.
        // Caso a condição seja fala, o programa é travado no modo de debug.
        assert(renderDataPointer != nullptr);		// O ator precisa ter um DrawableComponent.
        assert(renderDataPointer->IsLoaded());		// E este DrawableComponent precisa estar carregado.

        sf::Sprite* spritePointer = renderDataPointer->GetSprite();
        // Aplica as transformações na Sprite caso o ator tenha um componente de transformação.
        if (transformPointer != nullptr)
        {
            spritePointer->setPosition(transformPointer->GetPosition().x, transformPointer->GetPosition().y);
            spritePointer->setScale(transformPointer->GetScale().x, transformPointer->GetScale().y);
            spritePointer->setRotation(transformPointer->GetRotation());
        }

        // Desenha a sprite.
        this->m_renderWindow->draw(*spritePointer);
    }
} //EODrawAll


void DrawingSystem::DrawSpec(const unsigned int p_actorID)
{
    auto& findIt = m_actors.find(p_actorID);
    if (findIt == m_actors.end())
    {
        return;
    }

    ActorWeakPointer pWeakActor = findIt->second;
    std::shared_ptr<Actor> actorPointer = pWeakActor.lock();
    if (actorPointer == nullptr)
    {
        // Opcionalmente, este ator poderia ser removido.
        return;
    }

    if (actorPointer != nullptr)
    {
        DrawableComponent* renderDataPointer = actorPointer->GetComponent<DrawableComponent>(DrawableComponent::g_name);
        TransformableComponent* transformPointer = actorPointer->GetComponent<TransformableComponent>(TransformableComponent::g_name);

        // assert() é uma condição que deve ser válida para o funcionamento do código.
        // Elas servem para informar programadores sobre erros de lógica.
        // Caso a condição seja fala, o programa é travado no modo de debug.
        assert(renderDataPointer != nullptr);		// O ator precisa ter um DrawableComponent.
        assert(renderDataPointer->IsLoaded());		// E este DrawableComponent precisa estar carregado.

        sf::Sprite* spritePointer = renderDataPointer->GetSprite();
        // Aplica as transformações na Sprite caso o ator tenha um componente de transformação.
        if (transformPointer != nullptr)
        {
            spritePointer->setPosition(transformPointer->GetPosition().x, transformPointer->GetPosition().y);
            spritePointer->setScale(transformPointer->GetScale().x, transformPointer->GetScale().y);
            spritePointer->setRotation(transformPointer->GetRotation());
        }

        // Desenha a sprite.
        this->m_renderWindow->draw(*spritePointer);
    }
}