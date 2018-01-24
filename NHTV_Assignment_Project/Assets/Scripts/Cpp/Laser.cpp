#include "../Header/Laser.h"

Laser::Laser()
{
	// Set Laser transform.
	laser.setSize(Vector2f(15, 60));
	laser.setOrigin(Vector2f(7.5, 30));
	laser.setFillColor(Color(150, 000, 000));

	laserSpeed = 20;
}

void Laser::Update(Player* player)
{
	MoveLaser();
	CheckCollision(player);
}

void Laser::MoveLaser()
{
	laser.move(Vector2f(0, laserSpeed));
}

// Checking if the laser hits the player.
void Laser::CheckCollision(Player* player)
{
	if (getLaserBounds().intersects(player->getBounds())) {
		player->PlayerHit();
	}
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
