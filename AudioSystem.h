#pragma once

#include <assert.h>
#include <memory.h>

#include "Actor.h"
#include "AudibleComponent.h"

class AudioSystem
{
public:
    AudioSystem();

    void AddActor(ActorWeakPointer pActor);
    void RemoveActor(const unsigned int p_actorID);

    void PlayAll();
    void PauseAll();
    void StopAll();

    void PlaySpec(const unsigned int p_actorID);
    void PauseSpec(const unsigned int p_actorID);
    void StopSpec(const unsigned int p_actorID);

private:

    std::map<unsigned int, ActorWeakPointer> m_actors;	// Mapa dos atores no sistema.

};