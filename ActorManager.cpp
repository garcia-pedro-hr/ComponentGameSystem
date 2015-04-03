#include "ActorManager.h"

// Define NULL_ACTOR_ID
const ActorID ActorManager::NULL_ACTOR_ID = 0u;

ActorManager::ActorManager()
    : m_lastActorID(ActorManager::NULL_ACTOR_ID)
{
} // EOConstructor


ActorManager::~ActorManager()
{

}

ActorID ActorManager::CreateActor(const std::string & p_actorName)
{
    ActorSharedPointer pActor = CreateActorPointer(p_actorName);

    return pActor->GetActorID();
} // EOCreateActor


ActorSharedPointer ActorManager::CreateActorPointer(const std::string & p_actorName)
{
    ++this->m_lastActorID; // Primeiro valor válido: 1
    assert(this->m_lastActorID != ActorManager::NULL_ACTOR_ID);

    ActorSharedPointer pActor(new Actor(p_actorName, m_lastActorID));
    assert(pActor != nullptr);

    m_actors.insert(std::make_pair(m_lastActorID, pActor));

    return pActor;
} // EOCreateActorPointer


void ActorManager::RemoveActor(const ActorID p_actorID)
{
    std::map<ActorID, ActorSharedPointer>::iterator results = this->m_actors.find(p_actorID);

    if(results != this->m_actors.end())
    {
        results->second.reset();
        this->m_actors.erase(results);
    }
} // EORemoveActor


ActorSharedPointer ActorManager::GetActor(const ActorID p_actorID)
{
    const auto& findIt = this->m_actors.find(p_actorID);
    assert(findIt->first);

    if (findIt->first)
    {
        return findIt->second;
    }
    else
    {
        return ActorSharedPointer();
    }
} // EOGetActor


const unsigned int ActorManager::GetLastActorID(void) const
{
    return this->m_lastActorID;
} // EOGetLastActorID


ActorWeakPointer ActorManager::GetWeakActor(ActorID p_actorID)
{
    return ActorWeakPointer(GetActor(p_actorID));
} // EOGetWeakActor
