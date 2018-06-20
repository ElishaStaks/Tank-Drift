#pragma once
#include "SpriteObject.h"

class Track : public SpriteObject
{
public:
	void UpdateTrack()
	{
		++m_timer;
	}

	void SetTimer(float timer)
	{
		m_timer = timer;
	}
	float GetTimer()
	{
		return m_timer;
	}

private:
	float m_timer = 0.0f;
};