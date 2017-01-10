#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Map.h"
#include "Edge.h"
#include "ChaseState.h"
#include "Beekeeper.h"
#include "bee.h"


int main(int args[])
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();

	auto graph = new Map();
	graph->load();

	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 255, 255, 255));


	
	

	auto beekeeper = new Beekeeper();
	beekeeper->setLocation(graph->randomVertex(beekeeper->getLocation()));

	ChaseState* state = new ChaseState();
	beekeeper->setState(state);

	//auto bee = new Bee(application->LoadTexture("bee.png"), application,
	//	Vector2D(300, 500),                 //initial position
	//	100,        //start rotation
	//	Vector2D(40, 40),            //velocity
	//	1.0,          //mass
	//	400.0,     //max force
	//	40.0,             //max velocity
	//	3.14159, //max turn rate
	//	1.0);
	auto bee = new Bee();
	bee->setLocation(graph->randomVertex(bee->getLocation()));

	application->AddRenderable(beekeeper);
	application->AddRenderable(bee);

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
				switch (event.key.keysym.sym){
				case SDLK_UP:
					beekeeper->action(beekeeper, bee, graph);
					graph->resetCosts();
					break;
				default:
					break;
				}
			}
		}

		if (beekeeper->collides(bee))
			bee->setLocation(graph->randomVertex(bee->getLocation()));
		
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

	delete(state);
	delete(beekeeper);
	delete(bee);
	delete(graph);
	delete(application);
		
	return EXIT_SUCCESS;
}
