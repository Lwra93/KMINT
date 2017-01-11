#include "bee.h"

Bee::Bee()
{
<<<<<<< HEAD
	this->texture = mApplication->LoadTexture("bee.png");
	this->SetTexture(texture);
	this->SetSize(25, 21);
=======
	_color = color;
	this->SetTexture(img);
	this->mApplication = app;
	this->mHeight = 50;
	this->mWidth = 50;
	app->AddRenderable(this);
>>>>>>> parent of fb4881e... size bee
}


Bee::~Bee()
{
}
