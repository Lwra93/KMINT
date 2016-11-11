#pragma once
#include "Vertex.h"

Vertex::Vertex(int x, int y)
{
	this->x = x;
	this->y = y;
	resetCost();
}

int Vertex::getX() const
{
	return this->x;
}

int Vertex::getY() const
{
	return this->y;
}

void Vertex::addEdge(Edge* edge)
{
	this->edges.push_back(edge);
}

vector<Edge*> Vertex::getEdges() const
{
	return this->edges;
}

int Vertex::getCost() const
{
	return this->cost;
}

void Vertex::setCost(int cost)
{
	this->cost = cost;
}

void Vertex::resetCost()
{
	setCost(2147483647);
	setPrevious(nullptr);
}

Vertex* Vertex::getPrevious() const
{
	return this->previous;
}

void Vertex::setPrevious(Vertex* v)
{
	this->previous = v;
}
