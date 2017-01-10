#include "AStar.h"



AStar::AStar(Vertex *start, Vertex *goal, map<Vertex*, Vertex*>& came_from, map<Vertex*, int>& cost_so_far)
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
