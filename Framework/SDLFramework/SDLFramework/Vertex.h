#pragma once
#include <vector>
#include "Edge.h"

using namespace std;
class Edge;


class Vertex
{
public:
	Vertex(int x, int y);
	int getX() const;
	int getY() const;
	void addEdge(Edge* edge);
	vector<Edge*> getEdges() const;
	int getCost() const;
	void setCost(int cost);
	void resetCost();
	Vertex* getPrevious() const;
	void setPrevious(Vertex* v);
	double getPriority() const;
	void setPriority(double d);
	int GetDistance(Vertex* node);
	vector<Vertex*> getConnections() { return connections; };
	vector<Vertex*> connections;

private:
	int x, y;
	int cost;
	double priority;
	vector<Edge*> edges;
	Vertex* previous;
	
};
