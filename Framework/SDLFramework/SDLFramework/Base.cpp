#include "Base.h"

Base::Base()
{
	this->texture = mApplication->LoadTexture("beehive.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

void Base::emptyNet(int bees)
{
	this->bees += bees;
}

Base::~Base()
{
}