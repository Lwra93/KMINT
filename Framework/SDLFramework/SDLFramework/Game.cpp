#include "Game.h"
#include "bee.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include "Util.h"
#undef DrawText


Bee* Game::createBee(Vector2D SpawnPos, double force, double detection, double speed)
{
	return new Bee(this,
	               SpawnPos, //initial position
	               100, //start rotation
	               Vector2D(50, 50), //velocity
	               1.0, //mass
	               force, //max force
	               speed, //max velocity
	               3.14159, //max turn rate
	               1.0,
	               detection);
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

	/*SDL_Texture* map = application->LoadTexture("map.png");
	application->DrawTexture(map, 0, 0);*/
	//application->DrawTexture(application->LoadTexture("map.png"), 0, 0);
	
	m_pCellSpace = new CellSpacePartition<Bee*>((double)application->getWidth(), (double)application->getHeight(), 7, 7, amountOfBees + 1);
	createBees();
	
	//vaste objecten
	beekeeper->setCurrentVertex(graph->randomVertex(beekeeper->getCurrentVertex()));
	powerup->setCurrentVertex(graph->randomVertex(powerup->getCurrentVertex()));
	base->setCurrentVertex(graph->getVertex(109));

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

			if(isnan(bee->GetPos().x) || isnan(bee->GetPos().y))
			{
				bee->SetPos(0, 0);
			}

			bee->Move((float)application->mDeltaTimeMS / 1000.0f);
		}

		beekeeper->Time(application->mTimeMS);
		beekeeper->action();
		beekeeper->update();

		application->DrawTexture(application->LoadTexture("map.png"), 0, 0);

		// Graph drawing
		graph->draw(*application);

		// stats TODO FIXEN
		application->SetColor(Color(255, 0, 0, 255));
		application->DrawText("Base chance: " + std::to_string(beekeeper->getBaseChance()), 510, 480);
		application->DrawText("Powerup chance: " + std::to_string(beekeeper->getPowerupChance()), 510, 495);
		application->DrawText("Panic chance: " + std::to_string(beekeeper->getPanicChance()), 510, 510);
		application->DrawText("Bijen in mijn net: " + to_string(beekeeper->getBees().size()), 510, 525);
		application->DrawText("Net grootte: " + to_string(beekeeper->getMaxBees()), 510, 540);
		application->DrawText("Huidige state: " + beekeeper->getState()->getStateName(), 510, 555);
		application->DrawText("Bijen in de hive: " + to_string(base->getBees().size()), 510, 570);
		application->DrawText("Snelheid Game: " + to_string(this->getSpeed()),510,585);



		//draw net around beekeeper
		int x = beekeeper->getLocation().x;
		int y = beekeeper->getLocation().y;
		application->SetColor(Color(0, 128, 255, 100));
		application->DrawCircle(x, y, beekeeper->getNetSize(), true);

		if(beekeeper->getBees().size() < beekeeper->getMaxBees() && (beekeeper->getState()->getStateName() == "ChaseState" || beekeeper->getState()->getStateName() == "SuperState"))
		{

			for (auto bee : bees)
			{
					if (bee->GetPos().Distance(beekeeper->getLocation()) <= beekeeper->getNetSize())
					{
						beekeeper->Catch(bee);
						bees.erase(std::find(bees.begin(), bees.end(), bee));
						application->RemoveRenderable(bee);
						break;
					}
			}
		}

		std::cout << std::to_string(bees.size()) << std::endl;

		if(bees.size() <= 40)
		{
			nextGen();
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

		double fDouble = Util::randomDouble(1.0, 1.2);
		double dDouble = Util::randomDouble(1.0, 1.2);
		double sDouble = Util::randomDouble(1.0, 1.2);
			
		auto bee = createBee(Vector2D(location->getX(), location->getY()), 400.0*fDouble ,100.0*dDouble, 160*sDouble);
		bees.emplace_back(bee);
		m_pCellSpace->AddEntity(bee);
	}

}

void Game::addBee(Bee*bee)
{
	bees.push_back(bee);
	app->AddRenderable(bee);
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

void Game::nextGen()
{

	//Selection
	std::sort(bees.begin(), bees.end(), [](Bee* b1, Bee* b2)
	{
		return b1->TimeElapsed() > b2->TimeElapsed();
	}
	);

	vector<Bee*> beez;
	vector<Bee*> newBees;

	for(auto i = 0; i < 10; i++)
	{
		beez.push_back(bees.at(i));
	}

	for(auto bee : beez)
	{
		
		for(auto i = 0; i < 5; i++)
		{

			int id = Util::randomInt(0, 9);
			auto mate = beez.at(id);
			if(mate == bee)
			{
				i--;
				continue;
			}

			//Crossover
			int split = Util::randomInt(0, 1);

			int f1 = 0;
			int f2 = 0;
			int d1 = 0;
			int d2 = 0;
			int m1 = 0;
			int m2 = 0;

			if(split == 0)
			{
				f1 = bee->getForce();
				d1 = mate->DetectionRadius();
				m1 = mate->getTopSpeed();

				f2 = mate->getForce();
				d2 = bee->DetectionRadius();
				m2 = bee->getTopSpeed();
			}
			else
			{
				f1 = mate->getForce();
				d1 = mate->DetectionRadius();
				m1 = bee->getTopSpeed();

				f2 = bee->getForce();
				d2 = bee->DetectionRadius();
				m2 = mate->getTopSpeed();
			}

			double f1Double = Util::randomDouble(1.0, 1.2);
			double d1Double = Util::randomDouble(1.0, 1.2);
			double m1Double = Util::randomDouble(1.0, 1.2);
			auto loc1 = graph->randomVertex(nullptr);

			double f2Double = Util::randomDouble(1.0, 1.2);
			double d2Double = Util::randomDouble(1.0, 1.2);
			double m2Double = Util::randomDouble(1.0, 1.2);
			auto loc2 = graph->randomVertex(nullptr);

			//Mutation
			int mutate1 = Util::randomInt(0, 999);
			int mutate2 = Util::randomInt(0, 999);

			if (mutate1 >= 500)
			{
				f1Double *= Util::randomDouble(1.0, 1.5);
				d1Double *= Util::randomDouble(1.0, 1.5);
				m1Double *= Util::randomDouble(1.0, 1.5);
				
			}
				
			if(mutate2 >= 500)
			{
				f2Double *= Util::randomDouble(1.0, 1.5);
				d2Double *= Util::randomDouble(1.0, 1.5);
				m2Double *= Util::randomDouble(1.0, 1.5);
			}

			newBees.push_back(createBee(Vector2D(loc1->getX(), loc1->getY()), f1 * f1Double, d1*d1Double, m1*m1Double));
			newBees.push_back(createBee(Vector2D(loc2->getX(), loc2->getY()), f2 * f2Double, d2*d2Double, m2*m2Double));

		}

	}

	for(auto bee : bees)
	{
		app->RemoveRenderable(bee);
		delete(bee);
	}

	bees.clear();
	bees = newBees;

	beekeeper->removeBees();

	
}
