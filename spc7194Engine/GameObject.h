#pragma once
#include <glm/glm.hpp>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

using glm::vec3;
using glm::vec2;

struct Vertex
{
	vec3 loc;
	vec2 uv;
};

struct Transform
{
	vec3 location, rotation, size;
	glm::mat4 objWorldTransform;
};

struct RigidBody
{
	vec3 velocity;
	vec3 force;
	float mass;
};

class GameObject
{
public:
	enum ColliderType
	{
		none,
		aabb,
		sphere
	};

	GameObject();
	~GameObject();
	GameObject(vec3 location, vec3 rotation, vec3 size, char* iTexture, float mass, ColliderType iCollider);

	bool collidesWith(const GameObject* other);

	Transform transform;
	char* texture;
	GLuint glTex;
	RigidBody rigidBody;
	ColliderType collider;
};

