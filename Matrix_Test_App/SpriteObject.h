#pragma once
#include <Texture.h>
#include <Renderer2D.h>
#include "SceneObject.h"
#include <vector>
#include "AABB.h"

class SpriteObject : public SceneObject, public AABB
{
public:
	SpriteObject() 
	{
		m_texture = nullptr;
	}
	//copy constructor that loads in the filename
	SpriteObject(const char* fileName) 
	{ 
		load(fileName); 
	}
	//deconstructor 
	virtual ~SpriteObject()
	{
		delete m_texture; 
	}
	//load function which takes in the file directory
	bool load(const char* fileName)
	{
		//deletes the texture
		delete m_texture;
		//then makes the texture point to nothing 
		m_texture = nullptr;
		//and dynamically allocates it onto the heap and creates a new texture
		m_texture = new aie::Texture(fileName);
		//will always return a texture that doesnt equal nullptr
		return m_texture != nullptr;
	}
	//draw function for sprite
	virtual void OnDraw(aie::Renderer2D* renderer);

	//texture
	aie::Texture* m_texture = nullptr;
protected:
};

