#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/UIText.h"
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
	void Clear();

public:
	int GetScore();

private:
	void UpdateScore();

private:
	int scoreCount = 0;
	UIText* scoreText;
	RectangleShape scoreBackground;
};
