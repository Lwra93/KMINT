#pragma once
#include <vector>
#include "FWApplication.h"
#include "vertex.h"
#include "edge.h"

class Map
{
public:

	Map();
	~Map();
	void addVertex(Vertex* v);
	void addEdge(Edge* e);
	void draw(FWApplication &application);
	void load();
	Vertex* randomVertex(Vertex* current) const;
	void resetCosts();

private:
	vector<Vertex*> vertexes;
	vector<Edge*> edges;
};

struct Heuristic
{

	bool operator()(const Vertex *v1, const Vertex *v2) const
	{
		return v1->getFScore() > v2->getFScore();
	}
	
};