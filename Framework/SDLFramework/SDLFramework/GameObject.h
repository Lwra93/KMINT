#pragma once

#include "IGameObject.h"
#include "IState.h"
#include "Vertex.h"
#include "Map.h"
#include "Vector2D.h"

class Game;
class Beekeeper;
class IState;

class GameObject : public IGameObject {
public:
	GameObject(const Game* game);
	~GameObject();
	void Update(float deltaTime);
	void chase(GameObject *object);
	void setLocation(double x, double y);
	bool moveTo(double x, double y, FWApplication* app);
	Vector2D* getLocation() const;
	void setCurrentVertex(Vertex* vertex);
	Vertex* getCurrentVertex();
	void setGoalVertex(Vertex* vertex);
	Vertex* getGoalVertex();
	bool collides(GameObject *object) const;
	void setState(IState* state);
	IState* getState();
	void action() const;

protected:
	IState* state;
	SDL_Texture *texture;
	Vector2D* location;
	Vector2D goalLocation;
	const Game* game;
	Vertex* curVertex;
	Vertex* goalVertex;
};