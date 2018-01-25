#include "../Header/Ball.h"
#include <iostream>

using namespace std;

Ball::Ball(float x, float y)
{
	// Load the textures.
	ballTextureSafe.loadFromFile("Assets/Sprites/blue_ball.png");
	ballTextureDanger.loadFromFile("Assets/Sprites/red_ball.png");
	ballSprite.setTexture(ballTextureDanger);

	ballSprite.setPosition(x, y);
	ballSprite.setScale(2, 2);
	ballSprite.setOrigin((float)ballSprite.getTextureRect().width / 2, (float)ballSprite.getTextureRect().height / 2);

	ballSpeed = 5;
	dir.x = 1;
	dir.y = 1;

	ballState = DANGEROUS;
}

// Update gets called every frame.
void Ball::Update()
{
	// Always move our ball.
	Move();

	// Checking to reset the ball.
	if (ballState == SAFE)
	{
		cdTime++;
		
		// Make our ball flikker when almost back in danger state.
		if (cdTime >= 50) {
			if (cdTime % 5 == 0) {
				ballSprite.setTexture(ballTextureDanger);
			}
			else if (cdTime % 5 == 3) {
				ballSprite.setTexture(ballTextureSafe);
			}
		}
		// Setting the ball to the danger state.
		if (cdTime >= 100) {
			cdTime = 0;

			// Make our ball dangerous again.
			ballState = DANGEROUS;
			ballSprite.setTexture(ballTextureDanger);
		}
	}
}

void Ball::CheckCollision(Player& player)
{
	// Reflector Collision with ball.
	if (player.isReflecting && ballState == DANGEROUS)
	{
		if (player.getReflectorBounds().intersects(getBallBounds()))
		{
			// Change the direction.
			float deltaX = ballSprite.getPosition().x - player.playerSprite.getPosition().x;
			float deltaY = ballSprite.getPosition().y - player.playerSprite.getPosition().y;
			if (abs(deltaX) > abs(deltaY)) {
				if (deltaX <= 0) {
					BallHit(-1, 0);
					cout << "Left" << endl;
				}
				else {
					BallHit(1, 0);
					cout << "Right" << endl;
				}
			}
			else {
				if (deltaY <= 0) {
					BallHit(0, -1);
					cout << "Top" << endl;
				}
				else {
					BallHit(0, 1);
					cout << "Bottom" << endl;
				}
			}
		}
	}

	// Player collision with ball.
	if (ballState == DANGEROUS)
	{
		// Player loses!
		if (player.getBounds().intersects(getBallBounds()))
		{
			player.PlayerHit();
		}
	}
}

void Ball::Move()
{
	// Constantly move our ball.
	ballSprite.move(Vector2f(dir.x * ballSpeed, dir.y * ballSpeed));

	// Bounce the ball inside game bounds.
	if (ballSprite.getPosition().x < 0) {
		ChangeDirX(1);
	}
	if (ballSprite.getPosition().x > 1280) {
		ChangeDirX(-1);
	} 
	if (ballSprite.getPosition().y < 0) {
		ChangeDirY(1);
	}
	if (ballSprite.getPosition().y > 600) {
		ChangeDirY(-1);
	}
}

// Called when the player reflects the ball.
void Ball::BallHit(float newDirX = 0, float newDirY = 0)
{
	// TODO: Might use a sleep later on to get a nicer hit feeling.
	sleep(milliseconds(20));

	// Make the ball safe for the player.
	ballState = SAFE;
	ballSprite.setTexture(ballTextureSafe);

	if (newDirX != 0) {
		ChangeDirX(newDirX);
	}
	if (newDirY != 0) {
		ChangeDirY(newDirY);
	}

	IncreaseBallSpeed();
}

// Change the X direction of the ball to either -1(left) or 1(right)
void Ball::ChangeDirX(float newDirX)
{
	dir.x = newDirX;
}

// Change the Y direction of the ball to either -1(up) or 1(down)
void Ball::ChangeDirY(float newDirY)
{
	dir.y = newDirY;
}

// Add speed to our ball.
void Ball::IncreaseBallSpeed()
{
	ballSpeed += 1; 
}

// Rendering our Ball.
void Ball::Draw(RenderWindow& window) 
{
	window.draw(ballSprite);
}

// Returns the bounds of our Ball.
FloatRect Ball::getBallBounds() {
	Sprite* ptrSprite = &ballSprite;
	return ptrSprite->getGlobalBounds();
}

Ball::~Ball()
{
}
