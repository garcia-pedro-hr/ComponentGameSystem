#include "AudioSystem.h"

AudioSystem::AudioSystem()
{

}

void AudioSystem::AddActor(ActorWeakPointer pActor)
{      
    ActorSharedPointer pSharedActor = pActor.lock();
    assert(pSharedActor != nullptr);

    m_actors.insert(std::make_pair(pSharedActor->GetActorID(), pActor));
}

void AudioSystem::RemoveActor(const unsigned int p_actorID)
{
    auto& findIt = m_actors.find(p_actorID);
    if (findIt == m_actors.end())
    {
        return;
    }

    m_actors.erase(findIt);
}

void AudioSystem::PlayAll()
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

        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        // assert() é uma condição que deve ser válida para o funcionamento do código.
        // Elas servem para informar programadores sobre erros de lógica.
        // Caso a condição seja fala, o programa é travado no modo de debug.
        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->play();
    }
} //EOPlayAll


void AudioSystem::PauseAll()
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

        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        // assert() é uma condição que deve ser válida para o funcionamento do código.
        // Elas servem para informar programadores sobre erros de lógica.
        // Caso a condição seja fala, o programa é travado no modo de debug.
        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->pause();
    }
} //EOPauseAll


void AudioSystem::StopAll()
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

        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        // assert() é uma condição que deve ser válida para o funcionamento do código.
        // Elas servem para informar programadores sobre erros de lógica.
        // Caso a condição seja fala, o programa é travado no modo de debug.
        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->stop();
    }
} //EOStopAll


void AudioSystem::PlaySpec(const unsigned int p_actorID)
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
        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->play();
    }
} //EOPlay


void AudioSystem::PauseSpec(const unsigned int p_actorID)
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
        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->pause();
    }
} //EOPause


void AudioSystem::StopSpec(const unsigned int p_actorID)
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
        AudibleComponent* soundDataPointer = actorPointer->GetComponent<AudibleComponent>(AudibleComponent::g_name);

        assert(soundDataPointer != nullptr);		// O ator precisa ter um AudibleComponent.
        assert(soundDataPointer->IsLoaded());		// E este AudibleComponent precisa estar carregado.

        sf::Sound* soundPointer = soundDataPointer->GetSound();

        soundPointer->stop();
    }
} //EOStop