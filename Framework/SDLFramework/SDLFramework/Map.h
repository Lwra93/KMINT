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