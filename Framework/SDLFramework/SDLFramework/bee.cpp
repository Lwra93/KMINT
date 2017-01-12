#include "bee.h"
#include "Game.h"

//Bee::Bee()
//{
//	this->texture = mApplication->LoadTexture("bee.png");
//	this->SetTexture(texture);
//	this->SetSize(25, 21);
//}

Bee::Bee(const Game* game, Vector2D position,double rotation, Vector2D velocity, double mass, 
		double max_force, double max_speed, double max_turn_rate, 
			double scale, std::string color) : GameObject(game), ForceDrivenEntity(position,
				scale, velocity, max_speed, Vector2D(sin(rotation), -cos(rotation)),
				mass, Vector2D(scale, scale), max_turn_rate, max_force)
{
	_color = color;
	this->SetTexture(mApplication->LoadTexture("bee.png"));
	this->mHeight = 21;
	this->mWidth = 25;
	mApplication->AddRenderable(this);
}

Bee::~Bee()
{
}
