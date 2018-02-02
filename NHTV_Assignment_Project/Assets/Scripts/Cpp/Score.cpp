#include "../Header/Score.h"

Score::Score(float x, float y, int scoreSize)
{
	// Setting the text and font
	scoreText = new UIText(x, y, "Score: ", scoreSize, "Assets/Fonts/pixelFont.ttf");
	UpdateScore();

	// Setting the background.
	scoreBackground.setFillColor(Color::Black);
	FloatRect textBounds = scoreText->GetBounds();
	scoreBackground.setSize(Vector2f(textBounds.width * 1.4, textBounds.height * 1.35));
	scoreBackground.setOrigin(textBounds.width / 2, textBounds.height / 2);
	scoreBackground.setPosition(x, y + textBounds.height * 0.45);
}

// Rendering our Score.
void Score::Draw(RenderWindow& window) 
{
	window.draw(scoreBackground);
	scoreText->Draw(window);
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
	scoreText->SetText("Score: " + to_string(scoreCount));
}

// Reset our score.
void Score::Clear()
{
	scoreCount = 0;
	UpdateScore();
}

int Score::GetScore() {
	return scoreCount;
}

Score::~Score()
{
}
