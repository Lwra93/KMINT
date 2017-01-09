#include "bee.h"

Bee::Bee() : GameObject::GameObject()
{
	this->texture = mApplication->LoadTexture("bee.png");
	this->SetTexture(texture);
	this->SetSize(25, 21);
}


Bee::~Bee()
{
}
