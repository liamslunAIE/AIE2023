#pragma once
#include "Snake.h"


	class Fruit
	{

	private:

		int fruitPosX;
		int fruitPosY;

	public:

		Fruit();
		~Fruit();

		int GetFruitPosX();
		int GetFruitPosY();
		void SetFruitPos(bool x, std::vector<int> snakeX, std::vector<int> snakeY, int size);
		void DrawFruit();
	};


