#pragma once

enum GameStates {
	STARTSCREEN,
	TUTORIAL,
	GAME,
	GAMEOVER
};

static void ChangeState(GameStates newState);
static void ChangeState(GameStates newState)
{
	extern GameStates currentState;
	currentState = newState;
}
