#include "../Header/Laser.h"

Laser::Laser()
{
	// Set Laser transform.
	laser.setSize(Vector2f(15, 60));
	laser.setOrigin(Vector2f(10, 40));
	laser.setFillColor(Color(150, 000, 000));

	laserSpeed = 20;
}

void Laser::Update()
{
	MoveLaser();
	CheckCollision();
}

void Laser::MoveLaser()
{
	laser.move(Vector2f(0, laserSpeed));
}

void Laser::CheckCollision()
{
}

void Laser::setPosition(float x, float y) {
	laser.setPosition(x, y);
}

// Rendering our Enemy.
void Laser::Draw(RenderWindow& window)
{
	window.draw(laser);
}

// Returns the bounds of our enemy laser.
FloatRect Laser::getLaserBounds() {
	RectangleShape* ptrLaser = &laser;
	return ptrLaser->getGlobalBounds();
}


Laser::~Laser()
{
}
