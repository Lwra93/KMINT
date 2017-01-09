#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>
#include <map>

ChaseState::ChaseState()
{
}

void ChaseState::handle(GameObject *object1, Map *graph, GameObject *object2)
{
	std::map<Vertex*, int> mapNodeWeight;
	std::map<Vertex*, Vertex*> fromTo;

	for (auto p : graph->getVertexes()) {
		if (p == object1->getLocation())
			mapNodeWeight[p] = 0;
		else
			mapNodeWeight[p] = INT_MAX;
	}

	aStar(object1, object2, fromTo, mapNodeWeight);
	
	/*auto chaser = object1;
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

	chaser->setLocation(node);*/

}

int ChaseState::heuristic(Vertex* a, Vertex* b) {
	return a->GetDistance(b);
}

void ChaseState::aStar(GameObject *object1, GameObject *object2, map<Vertex*, Vertex*>& came_from, std::map<Vertex*, int>& cost_so_far)
{
	auto start = object1->getLocation();
	auto goal = object2->getLocation();
	PriorityQueue frontier;

	frontier.put(start, 0);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		Vertex* current = frontier.get();

		if (current == goal) {
			break;
		}

		for (auto next : current->getConnections()) {
			int new_cost = cost_so_far[current] + current->GetDistance(next);
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				int priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
	
	//somehow een aanliggende vertex kiezen met laagste cost
	if(!frontier.empty())
		object1->setLocation(frontier.get());
}