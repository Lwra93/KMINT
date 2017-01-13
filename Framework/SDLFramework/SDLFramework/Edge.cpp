#pragma once
#include "Edge.h"

Edge::Edge(Vertex* v1, Vertex* v2)
{
	v1->addEdge(this);
	v2->addEdge(this);
	this->vertexes.push_back(v1);
	this->vertexes.push_back(v2);
	this->weight = weight;
}

EdgeWeight Edge::getWeight() const
{
	return this->weight;
}

vector<Vertex*> Edge::getVertexes() const
{
	return this->vertexes;
}

Vertex* Edge::getOther(Vertex* v) const
{

	for(auto vertex : vertexes)
	{
		if (vertex != v)
			return vertex;
	}

	return nullptr;

}
