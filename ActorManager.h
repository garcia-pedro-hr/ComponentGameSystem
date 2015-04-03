#pragma once

#include <map>
#include <assert.h>
#include "Actor.h"

class ActorManager
{
public:

    static const ActorID NULL_ACTOR_ID;

    // . . .
    ActorManager();
    ~ActorManager();

    ActorID CreateActor(const std::string & p_actorName);
    ActorSharedPointer CreateActorPointer(const std::string & p_actorname);

    void RemoveActor(const ActorID p_actorID);

    // Este método é usado somente se o subsistema necessitar que o ator seja sempre válido.
    ActorSharedPointer GetActor(const ActorID p_actorID);
    const unsigned int GetLastActorID() const;

    // Caso contrário, este é usado.
    // Para converter weak_ptr para shared_ptr:
    // ActorID actorID = 1; // Qualquer ator registrado.
    // ActorWeakPointer pWeakActor = actorManager.GetWeakActor(actorID);
    // ActorSharedPointer pActor = pWeakActor.lock();
    // assert(pActor != nullptr);
    // pActor->GetComponent<...>(...);
    // ...
    ActorWeakPointer GetWeakActor(ActorID actorID);

private:

    std::map<ActorID, ActorSharedPointer> m_actors;
    ActorID m_lastActorID;

};