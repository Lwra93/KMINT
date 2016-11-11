#pragma once
#include "Rabbit.h"

Rabbit::Rabbit() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("rabbit-3.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}
