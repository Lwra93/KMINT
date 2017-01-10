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
#include "PowerUpState.h"
#include "PowerUp.h"
#include "Base.h"
#include "BaseState.h"
#include "Game.h"


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

	Game g = Game(application, graph);
	
	delete(graph);
	delete(application);
	return EXIT_SUCCESS;
}
