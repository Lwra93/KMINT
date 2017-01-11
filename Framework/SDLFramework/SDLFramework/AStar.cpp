#include "AStar.h"

AStar::AStar(GameObject *beekeeper, Map *graph, GameObject *bee)
{
	
	auto start = beekeeper->getCurrentVertex();
	auto goal = graph->randomVertex(beekeeper->getCurrentVertex());
	std::map<Vertex*, int> mapNodeWeight;
	std::map<Vertex*, Vertex*> fromTo;

	for (auto p : graph->getVertexes()) {
		if (p->getX() == beekeeper->getLocation()->x && p->getY() == beekeeper->getLocation()->y)
			mapNodeWeight[p] = 0;
		else
			mapNodeWeight[p] = INT_MAX;
	}

	Algorithm(start, goal, fromTo, mapNodeWeight);

	Vertex *nextVertex = nullptr;

	while (goal != start)
	{
		nextVertex = goal;
		goal = fromTo.find(goal)->second;
	}
	if (nextVertex != nullptr)
	{
		beekeeper->setGoalVertex(nextVertex);
		
		//beekeeper->setCurrentVertex(nextVertex);
	}
}

void AStar::Algorithm(Vertex* start, Vertex* goal, map<Vertex*, Vertex*>& came_from, map<Vertex*, int>& cost_so_far)
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

int AStar::heuristic(Vertex* a, Vertex* b)
{
	return a->GetDistance(b);
}

AStar::~AStar()
{
}
