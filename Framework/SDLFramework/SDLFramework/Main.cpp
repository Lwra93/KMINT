#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Cow.h"
#include "Rabbit.h"
#include "Map.h"
#include "Edge.h"


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
	application->SetColor(Color(255, 10, 40, 255));

	auto cow = new Cow();
	cow->setLocation(graph->randomVertex(cow->getLocation()));
	auto rabbit = new Rabbit();
	rabbit->setLocation(graph->randomVertex(rabbit->getLocation()));

	application->AddRenderable(cow);
	application->AddRenderable(rabbit);
	
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
					cow->chase(rabbit);
					graph->resetCosts();
					break;
				default:
					break;
				}
			}
		}

		if (cow->collides(rabbit))
			rabbit->setLocation(graph->randomVertex(rabbit->getLocation()));

		// Text drawing
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to KMint", 400, 300);
		
		// Graph drawing
		graph->draw(*application);

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	delete(cow);
	delete(rabbit);
	delete(graph);
	delete(application);
		
	return EXIT_SUCCESS;
}