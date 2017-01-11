#include "Game.h"
#include "Beekeeper.h"
#include "bee.h"
#include <SDL.h>
#include "ChaseState.h"
#include <iostream>
#include <string>
#include <time.h>

Game::Game(FWApplication* application, Map *graph)
{	
	beekeeper = new Beekeeper();
	base = new Base();
	powerup = new PowerUp();

	//auto bee = new Bee(application->LoadTexture("bee.png"), application,
	//	Vector2D(300, 500),                 //initial position
	//	100,        //start rotation
	//	Vector2D(40, 40),            //velocity
	//	1.0,          //mass
	//	400.0,     //max force
	//	40.0,             //max velocity
	//	3.14159, //max turn rate
	//	1.0);
	
	//autospawnen TODO
	Vector2D SpawnPos = Vector2D(600, 400);
	std::string color = "";
	auto bee = new Bee(application->LoadTexture("bee.png"), application,
		SpawnPos,                 //initial position
		100,        //start rotation
		Vector2D(160, 160),            //velocity
		1.0,          //mass
		400.0,     //max force
		160.0,             //max velocity
		3.14159, //max turn rate
		1.0, color);
	//bee->setLocation(graph->randomVertex(bee->getLocation()));

	//vaste objecten
	beekeeper->setCurrentVertex(graph->randomVertex(beekeeper->getCurrentVertex()));
	powerup->setCurrentVertex(graph->randomVertex(powerup->getCurrentVertex()));
	base->setCurrentVertex(graph->getVertex(0));

	application->AddRenderable(base);
	application->AddRenderable(beekeeper);
	//application->AddRenderable(bee);
	application->AddRenderable(powerup);

	clock_t this_time = clock();
	clock_t last_time = this_time;
	double time_counter = 0;

	//startstate
	ChaseState* chaseState = new ChaseState();
	beekeeper->setState(chaseState);
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
				case SDLK_UP:
					if (beekeeper->getState()->getStateName() == "PowerUpState")
						beekeeper->action(beekeeper, powerup, graph);
					else if (beekeeper->getState()->getStateName() == "ChaseState")
					{
						beekeeper->action(beekeeper, bee, graph);
						if(beekeeper->moveTo(beekeeper->getGoalVertex()->getX(), beekeeper->getGoalVertex()->getY(), application))
							beekeeper->setCurrentVertex(beekeeper->getGoalVertex());
					}
					else if (beekeeper->getState()->getStateName() == "BaseState")
						beekeeper->action(beekeeper, base, graph);
					else if (beekeeper->getState()->getStateName() == "SuperState")
						beekeeper->action(beekeeper, bee, graph);
					else if (beekeeper->getState()->getStateName() == "PanicState")
						beekeeper->action(beekeeper, beekeeper, graph);

					graph->resetCosts();
					break;
				default:
					break;
				}
			}
		}

		if (beekeeper->collides(base/*eigenlijk bee!!!*/) && (beekeeper->getState()->getStateName() == "ChaseState" || beekeeper->getState()->getStateName() == "SuperState"))
		{
			bee->setCurrentVertex(graph->randomVertex(bee->getCurrentVertex()));
			beekeeper->getState()->changeState(beekeeper, base, powerup);
		}
		else if (beekeeper->collides(powerup) && beekeeper->getState()->getStateName() == "PowerUpState")
		{
			powerup->setCurrentVertex(graph->randomVertex(powerup->getCurrentVertex()));
			beekeeper->getState()->changeState(beekeeper, base, powerup);
		}
		else if (beekeeper->collides(base) && beekeeper->getState()->getStateName() == "BaseState")
		{
			beekeeper->getState()->changeState(beekeeper, base, powerup);
		}
		else if(beekeeper->getState()->getStateName() == "PanicState")
		{
			beekeeper->getState()->changeState(beekeeper, base, powerup);
			
		}


		// Graph drawing
		graph->draw(*application);

		// stats
		application->SetColor(Color(0, 0, 0, 255));
		/*application->DrawText("Bijen in mijn net: " + to_string(beekeeper->getBees()), 510, 520);
		application->DrawText("Net grootte: " + to_string(beekeeper->getMaxBees()), 510, 540);
		application->DrawText("Huidige state: " + beekeeper->getState()->getStateName(), 510, 560);
		application->DrawText("Bijen in de hive: " + to_string(base->getBees()), 510, 580);
*/
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
