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
	Vertex* getVertex(int location) const;
	void resetCosts();
	vector<Vertex*> getVertexes();
	void addConnectionsVertexes();

private:
	vector<Vertex*> vertexes;
	vector<Edge*> edges;
};