#include "Game.h"
#include "Raylib.h"
#include "Raygui.h"


	Game::Game()
	{
		isOver = false;
	}

	Game::~Game()
	{

	}

	void Game::IsOverTrue()
	{
		isOver = true;
	}

	bool Game::GetOver()
	{
		return isOver;
	}

	

	int Game::GetDirection(int p)
	{
		int d;

		if (IsKeyPressed(KEY_UP) && p != 3)
		{
			d = 1;

		}
		else if (IsKeyPressed(KEY_LEFT) && p != 4)
		{
			d = 2;

		}
		else if (IsKeyPressed(KEY_DOWN) && p != 1)
		{
			d = 3;

		}
		else if (IsKeyPressed(KEY_RIGHT) && p != 2)
		{
			d = 4;

		}
		else
		{
			d = p;
		}

		return d;
	}





	