#pragma once
#include "Vertex.h"
#include <map>
#include <functional>
#include <queue>
#include "GameObject.h"

class Map;

class AStar
{
public:
	AStar(GameObject *beekeeper, Map *graph, Vertex* goal);
	void Algorithm(Vertex *start, Vertex *goal, map<Vertex*, Vertex*>& came_from, map<Vertex*, int>& cost_so_far);
	int heuristic(Vertex* a, Vertex* b);
	~AStar();
};

struct PriorityQueue {
	typedef std::pair<int, Vertex*> PQElement;
	priority_queue<PQElement, std::vector<PQElement>, greater<PQElement >> elements;

	bool empty() { return elements.empty(); }

	void put(Vertex* item, int priority) {
		elements.emplace(priority, item);
	}

	Vertex* get() {
		Vertex* best_item = elements.top().second;
		elements.pop();
		return best_item;
	}

};