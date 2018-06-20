#pragma once
#include "SpriteObject.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Background.h"
#include "Track.h"
#include <vector>

class Matrix_Test_AppApp : public aie::Application {
public:

	Matrix_Test_AppApp();
	virtual ~Matrix_Test_AppApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	// the tanks force at which it is being pushed 
	void AddForce(Vector3 force);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	SpriteObject*       m_tank; 
	SpriteObject*       m_turret;
	SpriteObject*       m_tracks;
	SpriteObject*       t_array;
	Background*         bg_warZone;

	//Linear Motion set values
	Vector3 m_velocity = Vector3(0, 0, 0);
	Vector3 m_acceleration = Vector3(0, 0, 0);
	float m_maxVel = 600.0f;
	//Boost bool
	bool nosActive; 
	//Tank and turret rotation speeds
	float m_tankRot = 2.50f;
	float m_turretRot = 2.50f;
	//GUI
	int gui_nosAmount = 500;
	bool gui_controls;
	bool gui_nosMeter;
	//tire bool 
	bool tireActive;
	float width;
	float height;
	std::vector<Track*> m_activeTrack;
	std::vector<Track*> m_storedTrack;
};