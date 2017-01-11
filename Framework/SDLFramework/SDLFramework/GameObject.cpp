#include "GameObject.h"
#include <SDL_render.h>
#include <ctime>
#include <queue>
#include "Map.h"
#include <map>

GameObject::GameObject()
{
	
}



GameObject::~GameObject() {
	SDL_DestroyTexture(texture);
}

void GameObject::Update(float deltaTime) {
	SetOffset(location->getX(), location->getY());
}

void GameObject::chase(GameObject *object)
{

}

void GameObject::setLocation(Vertex* v)
{
	this->location = v;
}

Vertex* GameObject::getLocation() const
{
	return this->location;
}

bool GameObject::collides(GameObject *object) const
{

	return this->location == object->getLocation();

}

void GameObject::setState(IState* state)
{
	this->state = state;
}

IState* GameObject::getState()
{
	return state;
}

void GameObject::action(Beekeeper* obj1, GameObject* obj2, Map *graph) const
{
	this->state->handle(obj1, graph, obj2);
}