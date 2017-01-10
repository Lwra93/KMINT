#include "PowerUp.h"



PowerUp::PowerUp()
{
	this->texture = mApplication->LoadTexture("pill2.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
}


PowerUp::~PowerUp()
{
}
