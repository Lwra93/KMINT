#pragma once
#include "Pill.h"

Pill::Pill() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("pill2.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}
