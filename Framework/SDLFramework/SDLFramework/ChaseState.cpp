#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>

ChaseState::ChaseState()
{
}

void ChaseState::handle(GameObject *object1, GameObject *object2)
{
	
	auto chaser = object1;
	auto chased = object2;

	list<Vertex*> closed;
	priority_queue<Vertex*, vector<Vertex*>, Heuristic> open;
	chaser->getLocation()->setCost(0);
	open.push(chaser->getLocation());

	while(!open.empty())
	{
		auto current = open.top();
		open.pop();

		if (current == chased->getLocation())
			break;

		for(auto edge : current->getEdges())
		{
			
			auto next = edge->getOther(current);

			if(std::find(closed.begin(), closed.end(), next) == closed.end())
			{
				
				if(next->getCost() > (current->getCost() + edge->getWeight()))
				{
					
					auto xExp = (next->getX() - chased->getLocation()->getX());
					auto yExp = (next->getY() - chased->getLocation()->getY());
					auto cExp = xExp*xExp + yExp*yExp;

					next->setCost(current->getCost() + edge->getWeight());
					next->setPriority(sqrt(cExp));
					next->setPrevious(current);
					open.push(next);

				}
			}
		}

		closed.push_back(current);
	
	}

	auto node = chased->getLocation();

	while (node->getPrevious() != chaser->getLocation())
		node = node->getPrevious();

	chaser->setLocation(node);

}