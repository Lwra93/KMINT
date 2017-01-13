#pragma once
#include "vector"
#include "Vertex.h"

using namespace std;
class Vertex;


enum EdgeWeight
{
	NORMAL = 1,
	WATER = 3,
	LANE = 2
};

class Edge
{
public:
	Edge(Vertex* v1, Vertex* v2);
	EdgeWeight getWeight() const;
	vector<Vertex*> getVertexes() const;
	Vertex* getOther(Vertex* v) const;

private:
	vector<Vertex*> vertexes;
	EdgeWeight weight;
};