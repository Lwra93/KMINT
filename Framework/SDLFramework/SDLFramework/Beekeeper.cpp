#pragma once
#include "Beekeeper.h"
#include "Game.h"

Beekeeper::Beekeeper(const Game* game) : GameObject::GameObject(game)
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

void Beekeeper::addBee()
{
	this->beesInNet++;
}

void Beekeeper::removeBee()
{
	this->beesInNet--;
}

int Beekeeper::getBees()
{
	return this->beesInNet;
}

int Beekeeper::removeBees()
{
	auto bees = this->beesInNet;
	this->beesInNet = 0;
	return bees;
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

Beekeeper::~Beekeeper()
{
}

const Game* Beekeeper::getGame()
{
	return this->game;
}
