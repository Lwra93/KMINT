#include "Game.h"
#include "bee.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>
#undef DrawText


Bee* Game::createBee(Vector2D SpawnPos)
{
	return new Bee(this,
	               SpawnPos, //initial position
	               100, //start rotation
	               Vector2D(50, 50), //velocity
	               1.0, //mass
	               400.0, //max force
	               160.0, //max velocity
	               3.14159, //max turn rate
	               1.0);
}

Game::Game(FWApplication* application, Map *graph)
{	
	this->app = application;
	gameSpeed = 2;
	int amountOfBees = 100;

	beekeeper = new Beekeeper(this);
	base = new Base(this);
	powerup = new PowerUp(this);
	this->graph = graph;
	
	m_pCellSpace = new CellSpacePartition<Bee*>((double)application->getWidth(), (double)application->getHeight(), 7, 7, amountOfBees + 1);
	createBees();
	
	//vaste objecten
	beekeeper->setCurrentVertex(graph->randomVertex(beekeeper->getCurrentVertex()));
	powerup->setCurrentVertex(graph->randomVertex(powerup->getCurrentVertex()));
	base->setCurrentVertex(graph->getVertex(0));

	application->AddRenderable(base);
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

		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_RETURN:
					if(gameSpeed * 10 <= 60)
						gameSpeed *= 10;
					break;
				case SDLK_SPACE:
					if(gameSpeed / 10 >= 2)
						gameSpeed /= 10;
					break;
				default:
					break;
				}
			}
		}

		this_time = clock();
		time_counter += static_cast<double>((this_time - last_time));
		last_time = this_time;

		if (time_counter > static_cast<double>(1 * CLOCKS_PER_SEC))
		{
			time_counter -= static_cast<double>(1 * CLOCKS_PER_SEC);
			beekeeper->increaseNetSize();
		}

		for(auto bee : bees)
		{
			bee->Move((float)application->mDeltaTimeMS / 1000.0f);
		}

		beekeeper->Time(application->mTimeMS);
		beekeeper->action();
		beekeeper->update();

		// Graph drawing
		graph->draw(*application);

		// stats TODO FIXEN
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Base chance: " + std::to_string(beekeeper->getBaseChance()), 510, 520);
		application->DrawText("Powerup chance: " + std::to_string(beekeeper->getPowerupChance()), 510, 540);
		application->DrawText("Panic chance: " + std::to_string(beekeeper->getPanicChance()), 510, 560);
		/*application->DrawText("Bijen in mijn net: " + to_string(beekeeper->getBees()), 510, 520);
		application->DrawText("Net grootte: " + to_string(beekeeper->getMaxBees()), 510, 540);*/
		application->DrawText("Huidige state: " + beekeeper->getState()->getStateName(), 510, 580);
		/*application->DrawText("Bijen in de hive: " + to_string(base->getBees()), 510, 580);
		application->DrawText("Snelheid Game: " + to_string(this->getSpeed()),510,500);*/



		//draw net around beekeeper
		int x = beekeeper->getLocation().x;
		int y = beekeeper->getLocation().y;
		application->SetColor(Color(0, 128, 255, 100));
		application->DrawCircle(x, y, beekeeper->getNetSize(), true);

		if(beekeeper->getBees() < beekeeper->getMaxBees() && (beekeeper->getState()->getStateName() == "ChaseState" || beekeeper->getState()->getStateName() == "SuperState"))
		{
			for (auto bee : bees)
			{
				if (!bee->isCaught())
				{
					if (bee->GetPos().Distance(beekeeper->getLocation()) <= beekeeper->getNetSize())
					{
						bee->Catch();
						application->RemoveRenderable(bee);
						beekeeper->addBee();
						if (beekeeper->getBees() == beekeeper->getMaxBees()) break;
					}
				}
			}
		}
		
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

	for (auto bee : bees)
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

vector<Bee*> Game::getBees() const
{
	return this->bees;
}

Beekeeper* Game::getBeekeeper() const
{
	return this->beekeeper;
}



void Game::createBees()
{

	for(auto i = 0; i < 100; i++)
	{
		auto location = graph->randomVertex(nullptr);
		auto bee = createBee(Vector2D(location->getX(), location->getY()));
		bee->SetDetectionRadius(100);
		bees.emplace_back(bee);
		m_pCellSpace->AddEntity(bee);
	}

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
