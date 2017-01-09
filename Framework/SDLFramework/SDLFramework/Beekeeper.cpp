#pragma once
#include "Beekeeper.h"

Beekeeper::Beekeeper() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(50, 83);
}


Beekeeper::~Beekeeper()
{
}
