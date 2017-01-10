#include "Game.h"
#include "Beekeeper.h"
#include "bee.h"
#include <SDL.h>
#include "ChaseState.h"
#include <iostream>
using namespace kmint;

namespace kmint
{
	extern Beekeeper* beekeeper = new Beekeeper();
	extern Base* base = new Base();
	extern PowerUp* powerup = new PowerUp();
}

Game::Game(FWApplication* application, Map *graph)
{	
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
	auto bee = new Bee();
	bee->setLocation(graph->randomVertex(bee->getLocation()));

	//vaste objecten
	beekeeper->setLocation(graph->randomVertex(beekeeper->getLocation()));
	powerup->setLocation(graph->randomVertex(powerup->getLocation()));
	base->setLocation(graph->getVertex(0));

	application->AddRenderable(base);
	application->AddRenderable(beekeeper);
	application->AddRenderable(bee);
	application->AddRenderable(powerup);

	//startstate
	ChaseState* chaseState = new ChaseState();
	beekeeper->setState(chaseState);
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
				case SDLK_UP:
					if (beekeeper->getState()->getStateName() == "PowerUpState")
						beekeeper->action(beekeeper, powerup, graph);
					else if (beekeeper->getState()->getStateName() == "ChaseState")
						beekeeper->action(beekeeper, bee, graph);
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

		if (beekeeper->collides(bee) && (beekeeper->getState()->getStateName() == "ChaseState" || beekeeper->getState()->getStateName() == "SuperState"))
		{
			bee->setLocation(graph->randomVertex(bee->getLocation()));
			beekeeper->getState()->changeState();
		}
		else if (beekeeper->collides(powerup) && beekeeper->getState()->getStateName() == "PowerUpState")
		{
			powerup->setLocation(graph->randomVertex(powerup->getLocation()));
			beekeeper->getState()->changeState();
		}
		else if (beekeeper->collides(base) && beekeeper->getState()->getStateName() == "BaseState")
		{
			beekeeper->getState()->changeState();
		}
		else if(beekeeper->getState()->getStateName() == "PanicState")
		{
			beekeeper->getState()->changeState();
			
		}


		// Graph drawing
		graph->draw(*application);

		//draw net around beekeeper
		int x = beekeeper->getLocation()->getX();
		int y = beekeeper->getLocation()->getY();
		application->SetColor(Color(242, 242, 242, 255));
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