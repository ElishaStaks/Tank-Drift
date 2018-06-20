#include "Matrix_Test_AppApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Background.h"
#include <imgui.h>
#include "AABB.h"
#include <Vector3.h>

typedef float dick;


Matrix_Test_AppApp::Matrix_Test_AppApp() 
{

}

Matrix_Test_AppApp::~Matrix_Test_AppApp() 
{
	
}

bool Matrix_Test_AppApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//Gui bool
	gui_controls = true;
	gui_nosMeter = true;
	//game bool
	nosActive = true;
	//tire bool flag
	tireActive = true;


	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_tank = new SpriteObject();
	m_turret = new SpriteObject();
	m_tracks = new SpriteObject();
	bg_warZone = new Background();

	m_tank->minimum = { 5.0f, 5.0f };
	m_tank->maximum = { 195.0f, 195.0f };

	// loads the sprites
	m_tank->load("../bin/textures/tank.png");
	m_turret->load("../bin/textures/GunTurret.png");
	// bg_warZone->load("../bin/textures/.png");

	//=========================== TIRE v TRACKS ================================//
	// cycles through 50 of the tracks and increments the tracks
	for (int i = 0; i < 50; i++)
	{
		//stored tracks get pushed to the back of the vector array 
		m_storedTrack.push_back(new Track());
		// this loads a texture for which every track is up next
		m_storedTrack[i]->load("../bin/textures/tracks.png");
	}
	//=========================== TIRE ^ TRACKS ================================//

	// attaches turret to the top of the tank
	m_tank->AddChild(m_turret);
	// centres the tank with the height and width of the screen 
	m_tank->SetPosition(100.0f, 100.0f); //I CHANGED THIS ELI
	m_tracks->SetPosition(100.0f, 100.0f); //AND THIS TOO
	width = m_tank->m_texture->getWidth() / 2;
	height = m_tank->m_texture->getHeight() / 2;
	return true;
}

void Matrix_Test_AppApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	// deletes the textures once program is shutdown
	delete m_tank;
	delete m_turret;
	delete m_tracks;
	delete bg_warZone;

	//=========================== TIRE v TRACKS ================================//
	// on shut down we are checking if there are still tracks in the storage
	// if the stored track is not empty THEN
	if (!m_storedTrack.empty())
	{
		// cycle through the amount of tracks in the storage 
		for (int i = 0; i < m_storedTrack.size(); i++)
		{
			// and delete each one 
			m_storedTrack[i] = nullptr;
			delete m_storedTrack[i];
		}
	}
	// then we clear the stored track by popping it out of the vector
	m_storedTrack.clear();

	// if the active track is not empty THEN
	if (!m_activeTrack.empty())
	{
		// cycle through the amount of tracks that are active THEN
		for (int i = 0; i < m_activeTrack.size(); i++)
		{
			// go through each one and delete them
			m_activeTrack[i] = nullptr;
			delete m_activeTrack[i];
		}
	}
	// then we clear the active track by popping it out of the vector
	m_activeTrack.clear();
	//=========================== TIRE ^ TRACKS ================================//
}

// updates the objects everyd frame
void Matrix_Test_AppApp::update(float deltaTime) {

	// input example
	auto input = aie::Input::getInstance();

//================================= MOUSE MOVEMENT ===================================//
	Vector3 m_mouse = { (dick)input->getMouseX(), (dick)input->getMouseY(), 0 };
	Vector3 offSet = { m_mouse - m_turret->GetGlobalTransform()[2] };
	offSet.normalise();

	Vector3 tankForward = m_turret->GetGlobalTransform()[1];

	dick angle = m_turret->GetLocalTransform()[1].angleBetween({ 0, 1, 0 }, offSet);
	dick tankAngle = m_turret->GetLocalTransform()[1].angleBetween({ 0, 1, 0 }, tankForward);

	m_turret->Rotate(angle - tankAngle);

//================================= MOUSE MOVEMENT ===================================//

//=========================== GAME UPDATES ==========================================//

	// all child objects attahed to the tank updates every framedw
	m_tank->Update(deltaTime);
	// background texture updates everyframe
	bg_warZone->Update(deltaTime);

//=========================== GAME UPDATES ==========================================//

//=========================== TANK MOVEMENT UPDATES ==========================================================================//

	// rotate tank, using deltaTime as the rotation speed
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		// tank rotates left
		m_tank->Rotate(m_tankRot * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		// tank rotates right
		m_tank->Rotate(-m_tankRot * deltaTime);
	}

	//=========================== TIRE v TRACKS ================================//
	static int timer = 0;
	// timer will increase to 1
	timer++;
	// the next time that the game is updated the timer will equal 1
	// it will then increase to 2
	//=========================== TIRE ^ TRACKS ================================//

	// the position has all 3 dimentions such as x, y, z
	auto position = Vector3(0, 0, 0);
	// the position of where your tank is which is the global transform
	auto facing = m_tank->GetLocalTransform()[1];

	// Moves the tank forward
	 if (input->isKeyDown(aie::INPUT_KEY_W))
	 {
		 // adds more acceleration to the tank to move forward every frame
		 AddForce(facing * 180);
		 m_tank->minimum.m_y += m_velocity.m_y * deltaTime;
		 m_tank->maximum.m_y += m_velocity.m_y * deltaTime;

		 //=========================== TIRE v TRACKS ================================//
		 //if the timer for the tires are greater or equal to 12 
		 if (timer >= 12)
		 {
			 if (!m_storedTrack.empty())
			 {
				 m_activeTrack.push_back(m_storedTrack.back());
				 m_storedTrack.pop_back();
				 m_activeTrack.back()->SetLocal(m_tank->GetGlobalTransform());
				 timer = 0;
			 }
		 }
		 //=========================== TIRE ^ TRACKS ================================//

		 // if the velocity is greater than the max velocity while moving forward THEN
		 if (m_velocity.m_y >= m_maxVel)
		 {
			 // have the tasank move at a constant speed of the set value the max velocity is at
			 m_velocity.m_y = m_maxVel;
		 }
	 }
	 // gets the velocity of the tank and times it by -0.51 which updates every frame and slows it down
	 AddForce(m_velocity * -0.51f);
	 // accelerates the tank forward 
	 m_velocity += m_acceleration * deltaTime;
	 position = position + m_velocity * deltaTime;
	 // the position the tank is facing
	 m_tank->Translate(position.m_x, position.m_y);
	 // the tanks acceleration
	 m_acceleration = Vector3(0, 0, 0);

	 //=========================== TIRE TRACKS ================================//
	 if (!m_activeTrack.empty())
	 {
		 for (int i = 0; i < m_activeTrack.size(); i++)
		 {
			 m_activeTrack[i]->UpdateTrack();
		 }
	 }
	 
	 static int timer2 = 0;
	 timer2++;

	 if (timer2 >= 12)
	 {
		 if (!m_activeTrack.empty())
		 {
			 if (m_activeTrack[0]->GetTimer() > 300.0f)
			 {
				 m_activeTrack[0]->SetTimer(0);
				 m_storedTrack.push_back(m_activeTrack.front());
				 for (int i = 1; i < m_activeTrack.size(); i++)
				 {
					 m_activeTrack[i - 1] = m_activeTrack[i];
				 }
				 m_activeTrack.pop_back();
				 timer2 = 0;
			 }
		 }
	 }
	 //=========================== TIRE TRACKS ================================//

	// Moves the tank backwards
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		// decreases the acceleration to the tank to move backwards
		AddForce(facing * -130);
		m_tank->minimum.m_y += position.m_y * deltaTime;
		m_tank->maximum.m_y += position.m_y * deltaTime;

		//=========================== TIRE TRACKS ================================//
		if (timer >= 12)
		{
			if (!m_storedTrack.empty())
			{
				m_activeTrack.push_back(m_storedTrack.back());
				m_storedTrack.pop_back();
				m_activeTrack.back()->SetLocal(m_tank->GetGlobalTransform());
				timer = 0;
			}
		}
		//=========================== TIRE TRACKS ================================//
		
		// if the velocity is lesser than the negative max velocity while moving backwards THEN
		if (m_velocity.m_y <= -m_maxVel)
		{
			// have the tank move at a constant speed of the set value the negative max velocity is at
			m_velocity.m_y = -m_maxVel;
		}
	}

	AddForce(m_velocity * -0.51f);
	m_velocity += m_acceleration * deltaTime;
	position = position + m_velocity * deltaTime;
	m_tank->Translate(position.m_x, position.m_y);
	// tanks initial acceleration
	m_acceleration = Vector3(0, 0, 0);

	// tank boost 
	if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
	{
		// checks if the tank is moving and checks if nos is active
		if (m_velocity.m_y != 0.0f && nosActive == true)
		{
			// increases the speed of the tank
			AddForce(facing * 250);

			//=========================== TIRE TRACKS ================================//
			if (timer >= 5)
			{
				if (!m_storedTrack.empty())
				{
					m_activeTrack.push_back(m_storedTrack.back());
					m_storedTrack.pop_back();
					m_activeTrack.back()->SetLocal(m_tank->GetGlobalTransform());
					timer = 0;
				}
			}
			//=========================== TIRE TRACKS ================================//
			// nos decrements every time you press shift
			gui_nosAmount--;
			//checks if the nos has reached the 0 value and if it has THEN
			if (gui_nosAmount <= 0)
			{
				// make nos equal to 0
				gui_nosAmount = 0;
				// and have nos deactivate
				nosActive = false;
			}
		}
	}
	AddForce(m_velocity * -0.21f);
	m_velocity += m_acceleration * deltaTime;
	position = position + m_velocity * deltaTime;
	m_tank->Translate(position.m_x, position.m_y);
	// tanks initial acceleration
	m_acceleration = Vector3(0, 0, 0);


	//// rotating the tanks turret
	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//{
	//	m_turret->Rotate(m_turretRot * deltaTime);
	//}
	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//{
	//	m_turret->Rotate(-m_turretRot * deltaTime);
	//}

//=========================== TANK MOVEMENT UPDATES ==========================================================================//


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Matrix_Test_AppApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Gui Controls
	if (gui_controls)
	{
       ImGui::Begin("Controls");
       ImGui::Text("TANK");
       ImGui::Text("W: move forward");
       ImGui::Text("A: move left");
       ImGui::Text("S: move backwards");
       ImGui::Text("D: move right");
       ImGui::Text("LEFT SHIFT: boost speed");
       ImGui::Text("");
       ImGui::Text("TURRET");
       ImGui::Text("<-: move left");
       ImGui::Text("->: move right");
       ImGui::Text("");
	   // if player presses close
       if (ImGui::Button("close"))
       {
		   // control panel will disappear
       	   gui_controls = false;
       }
       ImGui::End();
	}
	// if the control panel has disappeared THEN	
	if (gui_nosMeter == true)
	{
		// show players boost meter
		ImGui::Begin("Boost");
		ImGui::SliderInt("Nos Meter", &gui_nosAmount, 0, 200);
		ImGui::End();
	}

	// draw your stuff here!
	bg_warZone->DrawBG(m_2dRenderer);
	
	// if the active tracks are not empty THEN
	if (!m_activeTrack.empty())
	{
		// cycle through the tracks and check how many there are and increment 
		for (int i = 0; i < m_activeTrack.size(); i++)
		{
			// the next track that is up draw onto the tanks position
			m_activeTrack[i]->Draw(m_2dRenderer);
		}
	}
	// draws the tanks sprite
	m_tank->Draw(m_2dRenderer);

	// draws a green solid box
	m_2dRenderer->setRenderColour(0, 1, 0);
	auto m_corners = m_tank->GetLocalTransform()[2];
	m_2dRenderer->drawLine(m_corners.m_x - m_tank->m_texture->getWidth() /2, m_corners.m_y - m_tank->m_texture->getHeight() / 2,
						   m_corners.m_x - m_tank->m_texture->getWidth() /2, m_corners.m_y + m_tank->m_texture->getHeight() / 2, 5);
	m_2dRenderer->drawLine(m_corners.m_x + m_tank->m_texture->getWidth() /2, m_corners.m_y + m_tank->m_texture->getHeight() / 2,
		                   m_corners.m_x - m_tank->m_texture->getWidth() /2, m_corners.m_y + m_tank->m_texture->getHeight() / 2, 5);
	m_2dRenderer->drawLine(m_corners.m_x + m_tank->m_texture->getWidth() /2, m_corners.m_y - m_tank->m_texture->getHeight() / 2,
		                   m_corners.m_x + m_tank->m_texture->getWidth() /2, m_corners.m_y + m_tank->m_texture->getHeight() / 2, 5);
	m_2dRenderer->drawLine(m_corners.m_x - m_tank->m_texture->getWidth() /2, m_corners.m_y - m_tank->m_texture->getHeight() / 2,
		                   m_corners.m_x + m_tank->m_texture->getWidth() /2, m_corners.m_y - m_tank->m_texture->getHeight() / 2, 5);


	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
// the tanks force thats being pushed on it
void Matrix_Test_AppApp::AddForce(Vector3 force)
{
	// the acceleration adds to the force as the tank increases in velocity
	m_acceleration += force;
}
