#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>
#include <map>
#include "AStar.h"

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

	AStar(start, goal, fromTo, mapNodeWeight);
	
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
