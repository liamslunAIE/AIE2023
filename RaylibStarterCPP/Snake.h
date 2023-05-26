#pragma once
#include <iostream>
#include <vector>
#include "Fruit.h"
#include "Game.h"
#include <stdlib.h>

const int snakeSize = 401;


	class Snake
	{
	private:

		std::vector<int> snakePosX;
		std::vector<int> snakePosY;
		int size;
		int headPosX;
		int headPosY;
		float score;

	public:

		Snake();
		~Snake();
		void Move(int d);
		std::vector<int> GetSnakePosX();
		std::vector<int> GetSnakePosY();
		int GetSize();
		void IncreaseSize();
		int GetHeadPosX();
		int GetHeadPosY();
		float GetScore();

		bool FruitCollisionCheck(int fPosX, int fPosY);
		bool GameOverCollisionCheck();
		void SnakeDraw();



	};


