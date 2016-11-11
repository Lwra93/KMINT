#pragma once
#include "Cow.h"

Cow::Cow() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("lemmling_Cartoon_cow.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}
