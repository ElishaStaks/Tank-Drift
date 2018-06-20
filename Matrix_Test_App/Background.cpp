#include "Background.h"

void Background::SetPosX(float newPosX)
{
	posX = newPosX;
}

void Background::SetPosY(float newPosY)
{
	posY = newPosY;
}

float Background::GetPosX()
{
	return posX;
}

float Background::GetPosY()
{
	return posY;
}

void Background::DrawBG(aie::Renderer2D * renderer)
{
	renderer->drawSprite(bg_texture, posX, posY, 3850.0f, 2370.0f);
}
