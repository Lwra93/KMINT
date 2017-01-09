#pragma once
#include "IState.h"
#include <queue>
#include <map>

class ChaseState : public IState
{
public:
	ChaseState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void aStar();
	int heuristic(Vertex* a, Vertex* b);
	void aStar(Vertex *start, Vertex *goal, map<Vertex*, Vertex*>& came_from, map<Vertex*, int>& cost_so_far);

};

struct Heuristic
{

	bool operator()(const Vertex *v1, const Vertex *v2) const
	{
		return (v1->getCost() + v1->getPriority()) < (v2->getCost() + v2->getPriority());
	}

};

struct PriorityQueue {
	typedef std::pair<int, Vertex*> PQElement;
	priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement >> elements;

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