#pragma once
#include "Beekeeper.h"

Beekeeper::Beekeeper() : GameObject::GameObject()
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

void Beekeeper::increaseNetSize()
{
	this->netSize += 10;
}

int Beekeeper::getNetSize()
{
	return this->netSize;
}

void Beekeeper::addBee()
{
	this->beesInNet++;
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
