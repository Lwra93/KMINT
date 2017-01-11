#include "bee.h"

//Bee::Bee()
//{
//	this->texture = mApplication->LoadTexture("bee.png");
//	this->SetTexture(texture);
//	this->SetSize(25, 21);
//}

Bee::Bee(SDL_Texture* img, FWApplication* app, Vector2D position, 
	double rotation, Vector2D velocity, double mass, 
		double max_force, double max_speed, double max_turn_rate, 
			double scale, std::string color) : ForceDrivenEntity(position,
				scale, velocity, max_speed, Vector2D(sin(rotation), -cos(rotation)),
				mass, Vector2D(scale, scale), max_turn_rate, max_force)
{
	_color = color;
	this->SetTexture(img);
	this->mApplication = app;
	this->mHeight = 21;
	this->mWidth = 25;
	app->AddRenderable(this);
}

Bee::~Bee()
{
}
