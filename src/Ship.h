#pragma once
#ifndef __Ship__
#define __Ship__

#include "GameObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class Ship : public GameObject
{
public:
	Ship();
	~Ship();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
private:
	void m_move();

	void m_checkBounds();

	void m_reset();
};

#endif /* defined (__Ship__) */

