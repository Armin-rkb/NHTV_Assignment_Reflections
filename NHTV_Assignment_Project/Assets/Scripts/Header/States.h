#pragma once

enum GameStates {
	STARTSCREEN,
	GAME,
	GAMEOVER
};

static void ChangeState(GameStates newState);
static void ChangeState(GameStates newState)
{
	extern GameStates currentState;
	currentState = newState;
}
