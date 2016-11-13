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
	int getFScore() const;
	void setFScore(int f);
	
	int getHeuristic(Vertex* g) const;

private:
	int x, y;
	int cost;
	int f;
	vector<Edge*> edges;
	Vertex* previous;
};
