#include "Base.h"

Base::Base(Game* game): GameObject(game)
{
	this->texture = mApplication->LoadTexture("beehive.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

void Base::emptyNet(int bees)
{
	this->bees += bees;
}

vector<Bee*> Base::getBees()
{
	return this->beesInBase;
}

Base::~Base()
{
}

void Base::AddBee(Bee* bee)
{
	beesInBase.push_back(bee);
}

void Base::RemoveAll()
{
	beesInBase.clear();
}
