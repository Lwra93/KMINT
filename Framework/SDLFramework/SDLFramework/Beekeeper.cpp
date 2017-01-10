#pragma once
#include "Beekeeper.h"

Beekeeper::Beekeeper() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(50, 83);
	this->netSize = 30;
}

void Beekeeper::increaseNetSize()
{
	this->netSize += 10;
}

int Beekeeper::getNetSize()
{
	return this->netSize;
}


Beekeeper::~Beekeeper()
{
}
