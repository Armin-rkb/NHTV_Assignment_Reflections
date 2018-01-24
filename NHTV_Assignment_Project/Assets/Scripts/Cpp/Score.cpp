#include "../Header/Score.h"



Score::Score(float x, float y, int scoreSize)
{
	// Setting the text and font.
	scoreText.setCharacterSize(scoreSize);
	scoreText.setPosition(x, y);
	textFont.loadFromFile("Assets/Fonts/pixelFont.ttf");
	scoreText.setFont(textFont);
	UpdateScore();

	// Setting the background.
	scoreBackground.setFillColor(Color::Black);
	scoreBackground.setSize(Vector2f(scoreText.getLocalBounds().width * 1.5, scoreText.getLocalBounds().height * 2));
	scoreBackground.setPosition(scoreText.getPosition().x - 5, scoreText.getPosition().y);
}

// Rendering our Score.
void Score::Draw(RenderWindow& window) 
{
	window.draw(scoreBackground);
	window.draw(scoreText);
}

// Add score to our text and update it.
void Score::AddScore(int amount)
{
	scoreCount += amount;
	UpdateScore();
}

// Update our score text.
void Score::UpdateScore()
{
	ostringstream ssScore;
	ssScore << "Score: " << scoreCount;
	scoreText.setString(ssScore.str());
}

Score::~Score()
{
}
