#include "PowerUp.h"

PowerUp::PowerUp(Game* game): GameObject(game)
{
	this->texture = mApplication->LoadTexture("pill2.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
}


PowerUp::~PowerUp()
{
}
