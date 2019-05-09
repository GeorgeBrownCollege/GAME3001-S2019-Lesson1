#include "Ship.h"
#include "Game.h"


Ship::Ship()
{
	TheTextureManager::Instance()->load("../Assets/textures/ship.png",
		"ship", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ship");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0, 3));
	m_reset();
	setIsColliding(false);
	setType(GameObjectType::SHIP);

	/*
	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg",
		"yay", sound_type::SOUND_SFX);
	*/
}


Ship::~Ship()
{
}

void Ship::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("ship", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void Ship::update()
{
	m_move();
	m_checkBounds();
}

void Ship::clean()
{
}

void Ship::m_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Ship::m_checkBounds()
{
	if (getPosition().y > 480 + getHeight()) {
		m_reset();
	}
}

void Ship::m_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}
