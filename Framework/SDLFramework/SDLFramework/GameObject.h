#pragma once

#include "IGameObject.h"
#include "IState.h"
#include "Vertex.h"
#include "Map.h"

class IState;

class GameObject : public IGameObject {
public:
	GameObject();
	~GameObject();
	void Update(float deltaTime);
	void chase(GameObject *object);
	void setLocation(Vertex* v);
	Vertex* getLocation() const;
	bool collides(GameObject *object) const;
	void setState(IState* state);
	IState* getState();
	void action(GameObject*, GameObject*, Map*) const;

protected:
	IState* state;
	SDL_Texture *texture;
	Vertex* location;
};