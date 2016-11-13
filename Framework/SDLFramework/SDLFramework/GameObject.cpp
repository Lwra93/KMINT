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

	priority_queue<Vertex*, vector<Vertex*>, Heuristic> toVisit;
	location->setCost(0);
	auto f = location->getHeuristic(object->getLocation());
	location->setFScore(f);
	
	toVisit.push(location);

	auto foundRabbit = false;

	while(!toVisit.empty())
	{
		
		auto loc = toVisit.top();
		toVisit.pop();

		vector<Vertex*> nexts;
		for (auto edge : loc->getEdges())
			nexts.push_back(edge->getOther(loc));

		for(auto vertex : nexts)
		{
			if (vertex == object->getLocation())
			{
				object->getLocation()->setPrevious(loc);
				foundRabbit = true;
				break;
			}
				
		}

		if (foundRabbit)
			break;

		for(auto edge : loc->getEdges())
		{
			auto next = edge->getOther(loc);
			if(next->getCost() > (loc->getCost() + static_cast<int>(edge->getWeight())))
			{
				next->setCost(loc->getCost() + edge->getWeight());
				f = next->getHeuristic(object->getLocation());
				next->setFScore(f);
				next->setPrevious(loc);
				toVisit.push(next);
			}
		}

	}

	auto current = object->getLocation();

	while(true)
	{
		if (current->getPrevious() != nullptr && current->getPrevious()->getPrevious() == nullptr)
			break;
		else
			current = current->getPrevious();
	}

	this->location = current;

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
