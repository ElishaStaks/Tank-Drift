#pragma once
#include <Texture.h>
#include <Renderer2D.h>

class Background
{
public:
	//default constructor assigns the positions of the backlground
	Background()
	{
		posX = 1920.0f;
		posY = 1080.0f;
	}
	//copy constructor
	Background(const char* fileName) 
	{ 
		load(fileName); 
	}
	//deconstructor 
	~Background()
	{
		delete bg_texture;
	}
	//updates the background every frame
	//is used in the app.h file 
	void Update(float deltaTime) {}

	//sets the positions x and y for the background
	void SetPosX(float newPosX);
	void SetPosY(float newPosY);
	//gets the x and y positions of the background
	float GetPosX();
	float GetPosY();

	//load function which takes in the file directory
	bool load(const char* fileName)
	{
		//deletes the texture
		delete bg_texture;
		//then makes the texture point to nothing 
		bg_texture = nullptr;
		//and dynamically allocates it onto the heap and creates a new texture
		bg_texture = new aie::Texture(fileName);
		//will always return a texture that doesnt equal nullptr
		return bg_texture != nullptr;
	}
	//draws the background texture
	void DrawBG(aie::Renderer2D* renderer);

protected:
	aie::Texture* bg_texture = nullptr;
	float posX;
	float posY;
};

