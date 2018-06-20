#include "SpriteObject.h"


void SpriteObject::OnDraw(aie::Renderer2D * renderer)
{

	//draws sprite with the global transformation
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
	
}
