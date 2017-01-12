#include "Base.h"

Base::Base(const Game* game): GameObject(game)
{
	this->texture = mApplication->LoadTexture("beehive.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

void Base::emptyNet(int bees)
{
	this->bees += bees;
}

int Base::getBees()
{
	return this->bees;
}

Base::~Base()
{
}
