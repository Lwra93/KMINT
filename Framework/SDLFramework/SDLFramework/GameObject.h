#pragma once

#include "IGameObject.h"
#include "Vertex.h"

class GameObject : public IGameObject {
public:
	GameObject();
	~GameObject();
	void Update(float deltaTime);
	void chase(GameObject *object);
	void setLocation(Vertex* v);
	Vertex* getLocation() const;
	bool collides(GameObject *object) const;

protected:
	SDL_Texture *texture;
	Vertex* location;
};