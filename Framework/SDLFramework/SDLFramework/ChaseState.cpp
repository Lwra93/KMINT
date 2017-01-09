#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>
#include <map>

ChaseState::ChaseState()
{
}

void ChaseState::handle(GameObject *beekeeper, Map *graph, GameObject *bee)
{
	auto start = beekeeper->getLocation();
	auto goal = bee->getLocation();
	std::map<Vertex*, int> mapNodeWeight;
	std::map<Vertex*, Vertex*> fromTo;

	for (auto p : graph->getVertexes()) {
		if (p == beekeeper->getLocation())
			mapNodeWeight[p] = 0;
		else
			mapNodeWeight[p] = INT_MAX;
	}

	aStar(start, goal, fromTo, mapNodeWeight);

	Vertex *nextVertex = nullptr;

	while(goal != start)
	{
		nextVertex = goal;
		goal = fromTo.find(goal)->second;
	}
	if(nextVertex != nullptr)
	{
		beekeeper->setLocation(nextVertex);
	}
	
}

int ChaseState::heuristic(Vertex* a, Vertex* b) {
	return a->GetDistance(b);
}

void ChaseState::aStar(Vertex *start, Vertex *goal, map<Vertex*, Vertex*>& came_from, std::map<Vertex*, int>& cost_so_far)
{
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
}