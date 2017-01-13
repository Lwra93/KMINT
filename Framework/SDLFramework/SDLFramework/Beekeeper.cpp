#pragma once
#include "Beekeeper.h"
#include "Game.h"

Beekeeper::Beekeeper(Game* game) : GameObject::GameObject(game)
{
	this->texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(50, 83);
	this->netSize = 30;
	this->maxBees = 10;
	this->panicChance = 33.3;
	this->powerupChance = 33.3;
	this->baseChance = 33.3;
}

void Beekeeper::changeTexture(string name)
{
	this->texture = mApplication->LoadTexture(name);
	this->SetTexture(texture);
}

string Beekeeper::getPrevState()
{
	return this->prevState;
}

void Beekeeper::increaseNetSize()
{
	this->netSize += 5;
}

void Beekeeper::resetNet()
{
	this->netSize = 30;
}

int Beekeeper::getNetSize()
{
	return this->netSize;
}

vector<Bee*> Beekeeper::getBees()
{
	return this->caughtBees;
}

void Beekeeper::removeBees()
{
	caughtBees.clear();
}

int Beekeeper::getMaxBees()
{
	return this->maxBees;
}

void Beekeeper::setMaxBees(int amount)
{
	this->maxBees = amount;
}

void Beekeeper::setPrevState(string state)
{
	this->prevState = state;
}

double Beekeeper::getPowerupChance()
{
	return powerupChance;
}

double Beekeeper::getPanicChance()
{
	return panicChance;
}

double Beekeeper::getBaseChance()
{
	return baseChance;
}

void Beekeeper::Catch(Bee* bee)
{	
	caughtBees.push_back(bee);
}

void Beekeeper::Release(Bee*bee)
{
	caughtBees.erase(std::find(caughtBees.begin(), caughtBees.end(), bee));
}

Beekeeper::~Beekeeper()
{
}
