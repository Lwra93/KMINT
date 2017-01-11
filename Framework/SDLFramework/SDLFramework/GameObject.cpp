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
	Vector2D vector = Vector2D(deltaX, deltaY);
	vector.Normalize();

	while(!goalreached)
	{
		this->setLocation(this->location->x + (vector.x * 5), this->location->y + (vector.y * 5));

		app->UpdateGameObjects();
		app->RenderGameObjects();
		//werkt half, crasht nog wel is en is niet heel strak
		if (tempX >= x && tempY >= y)
			return true;
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

void GameObject::action(Beekeeper* obj1, GameObject* obj2, Map *graph) const
{
	this->state->handle(obj1, graph, obj2);
}