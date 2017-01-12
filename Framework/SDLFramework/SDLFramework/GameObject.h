#pragma once

#include "IGameObject.h"
#include "IState.h"
#include "Vertex.h"
#include "Map.h"
#include "Vector2D.h"
#include "State.h"

class Game;
//class Beekeeper;
class IState;
class State;

class GameObject : public IGameObject {
public:
	GameObject(Game* game);
	~GameObject();
	void Update(float deltaTime) override;
	void chase(GameObject *object);
	void setLocation(double x, double y);
	Vector2D* getLocation() const;
	void setCurrentVertex(Vertex* vertex);
	Vertex* getCurrentVertex();
	void setGoalVertex(Vertex* vertex);
	Vertex* getGoalVertex();
	bool collides(GameObject *object) const;
	void setState(State* state);
	State* getState();
	void action() const;
	void update() const;

protected:
	State* state;
	SDL_Texture *texture;
	Vector2D* location;
	Vector2D goalLocation;
	Game* game;
	Vertex* curVertex;
	Vertex* goalVertex;
};