#pragma once
#include "SFML\Graphics.hpp"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;
class Score
{
public:
	Score(float x, float y, int scoreSize = 30);
	~Score();

public:
	void Draw(RenderWindow& window);
	void AddScore(int amount);

private:
	void UpdateScore();

private:
	int scoreCount = 0;
	Text scoreText;
	Font textFont;
	RectangleShape scoreBackground;
};
