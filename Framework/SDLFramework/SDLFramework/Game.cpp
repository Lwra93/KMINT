#include "Game.h"
#include "bee.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>


Bee* Game::createBee(Vector2D SpawnPos, std::string color)
{
	//return new Bee(this,
	//               SpawnPos, //initial position
	//               100, //start rotation
	//               Vector2D(160, 160), //velocity
	//               1.0, //mass
	//               400.0, //max force
	//               160.0, //max velocity
	//               3.14159, //max turn rate
	//               1.0, color);
	return nullptr;
}

Game::Game(FWApplication* application, Map *graph)
{	
	gameSpeed = 10;

	beekeeper = new Beekeeper(this);
	base = new Base(this);
	powerup = new PowerUp(this);
	this->bee = new Bee(this);
	this->graph = graph;
	
	//autospawnen TODO
	Vector2D SpawnPos = Vector2D(600, 400);
	std::string color = "";
	//this->bee = createBee(SpawnPos, color);

	//vaste objecten
	beekeeper->setCurrentVertex(graph->randomVertex(beekeeper->getCurrentVertex()));
	powerup->setCurrentVertex(graph->randomVertex(powerup->getCurrentVertex()));
	base->setCurrentVertex(graph->getVertex(0));
	bee->setCurrentVertex(graph->randomVertex(bee->getCurrentVertex()));

	application->AddRenderable(base);
	application->AddRenderable(bee);
	application->AddRenderable(beekeeper);
	application->AddRenderable(powerup);

	clock_t this_time = clock();
	clock_t last_time = this_time;
	double time_counter = 0;

	//startstate
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "ChaseState"));


	//while (true){}
	while (application->IsRunning())
	{
		this_time = clock();
		time_counter += static_cast<double>((this_time - last_time));
		last_time = this_time;

		if (time_counter > static_cast<double>(1 * CLOCKS_PER_SEC))
		{
			time_counter -= static_cast<double>(1 * CLOCKS_PER_SEC);
			beekeeper->increaseNetSize();
		}
		application->StartTick();

		beekeeper->action();
		beekeeper->update();

		// Graph drawing
		graph->draw(*application);

		// stats TODO FIXEN
		application->SetColor(Color(0, 0, 0, 255));
		//application->DrawText("Bijen in mijn net: " + to_string(beekeeper->getBees()), 510, 520);
		//application->DrawText("Net grootte: " + to_string(beekeeper->getMaxBees()), 510, 540);
		//application->DrawText("Huidige state: " + beekeeper->getState()->getStateName(), 510, 560);
		//application->DrawText("Bijen in de hive: " + to_string(base->getBees()), 510, 580);



		//draw net around beekeeper
		int x = beekeeper->getLocation()->x;
		int y = beekeeper->getLocation()->y;
		application->SetColor(Color(0, 128, 255, 100));
		application->DrawCircle(x, y, beekeeper->getNetSize(), true);

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	//delete states
	delete(base);
	delete(powerup);
	delete(beekeeper);
	delete(bee);
	
}



Game::~Game()
{
}

Map* Game::getGraph() const
{
	return this->graph;
}

Base* Game::getBase() const
{
	return this->base;
}

Bee* Game::getBee() const
{
	return this->bee;
}

PowerUp* Game::getPowerUp() const
{
	return this->powerup;
}

int Game::getSpeed() const
{
	return this->gameSpeed;
}

void Game::setSpeed(int amount)
{
	this->gameSpeed = amount;
}
