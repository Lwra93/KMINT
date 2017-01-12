#include "GameObject.h"
#include <SDL_render.h>
#include <ctime>
#include <queue>
#include "Map.h"
#include <map>
#include "Game.h"

GameObject::GameObject(Game* game)
{
	this->game = game;
}



GameObject::~GameObject() {
	SDL_DestroyTexture(texture);
}

void GameObject::Update(float deltaTime) {
	if(this->location != nullptr)
		SetOffset(location->x, location->y);
}

void GameObject::chase(GameObject *object)
{

}

void GameObject::setLocation(double x, double y)
{
	this->location = new Vector2D(x, y);

}

Vector2D* GameObject::getLocation() const
{
	return this->location;
}

void GameObject::setCurrentVertex(Vertex* vertex)
{
	this->curVertex = vertex;
	this->setLocation(vertex->getX(), vertex->getY());
}

Vertex* GameObject::getCurrentVertex()
{
	return this->curVertex;
}

void GameObject::setGoalVertex(Vertex* vertex)
{
	this->goalVertex = vertex;
}

Vertex* GameObject::getGoalVertex()
{
	return this->goalVertex;
}

bool GameObject::collides(GameObject *object) const
{



	return this->location->x == object->getLocation()->x && this->location->y == object->getLocation()->y;

}

void GameObject::setState(State* state)
{
	this->state = state;
}

State* GameObject::getState()
{
	return state;
}

void GameObject::action() const
{
	this->state->handle();
}

void GameObject::update() const
{
	this->state->update();
}
