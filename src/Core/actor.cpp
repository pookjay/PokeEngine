#include "actor.h"

#include "actor_component.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::BeginPlay()
{
}

void Actor::Update(float deltaTime)
{
}

void Actor::UpdateActor(float deltaTime)
{
	UpdateComponents(deltaTime);

	Update(deltaTime);
}

void Actor::UpdateComponents(float deltaTime)
{
	for (ActorComponent* component : m_Components)
	{
		component->Update(deltaTime);
	}
}
