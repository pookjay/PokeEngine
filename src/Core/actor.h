#pragma once
#include <unordered_set>

#include <glm/glm.hpp>

class Actor {

public:

	Actor();

	~Actor();

	virtual void BeginPlay();
	virtual void Update(float deltaTime);

	void UpdateActor(float deltaTime);
	void UpdateComponents(float deltaTime);

private:

	std::unordered_set<class ActorComponent*> m_Components;

	glm::vec3 m_Position;
	float m_Rotation;
	float m_Scale;

	class Application* m_Application;

};