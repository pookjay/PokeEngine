#pragma once

class ActorComponent {

public:

	ActorComponent(class Actor* owner);

	virtual ~ActorComponent();

	virtual void BeginPlay();

	virtual void Update(float deltaTime);

private:

	class Actor* m_Owner;

};