#include "GameObject.h"
#include <SDL_render.h>
#include <ctime>
#include <queue>
#include "Map.h"
#include <map>
#include "Game.h"

GameObject::GameObject(const Game* game)
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

bool GameObject::moveTo(double x, double y, FWApplication* app)
{
	goalLocation = Vector2D(x, y);

	bool goalreached = false;
	double tempX = this->location->x;
	double tempY = this->location->y;

	double deltaX = x - tempX;
	double deltaY = y - tempY;

	bool moveUp = deltaY >= 0 ? true : false;
	bool moveRight = deltaX >= 0 ? true : false;

	Vector2D vector = Vector2D(deltaX, deltaY);
	vector.Normalize();

	while(!goalreached)
	{
		tempX += (vector.x);
		tempY += (vector.y);
		this->setLocation(tempX, tempY);

		this->Draw();
		
		//werkt half, crasht nog wel is en is niet heel strak
		if (moveUp && moveRight)
		{
			if (tempX >= x && tempY >= y)
				return true;
		}
		else if(!moveUp && !moveRight)
		{
			if (tempX <= x && tempY <= y)
				return true;
		}
		else if (moveUp && !moveRight)
		{
			if (tempX <= x && tempY >= y)
				return true;
		}
		else if (!moveUp && moveRight)
		{
			if (tempX >= x && tempY <= y)
				return true;
		}

			//goalreached = true;
	}
	
	
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

void GameObject::action() const
{
	this->state->handle();
}