#include "Fruit.h"
#include "Snake.h"
#include <random>
#include <vector>
#include <stdlib.h>
#include "Raylib.h"


	Fruit::Fruit()
	{

		fruitPosX = rand() % 18+1;
		fruitPosY = rand() % 18+1;

		// Ensuring the fruit is not spwaned on top of the snakes starting position
		while (fruitPosX == 9 && fruitPosY == 9)
		{
			fruitPosX = rand() % 18+1;
			fruitPosY = rand() % 18+1;
		}

	}

	Fruit::~Fruit()
	{

	}

	int Fruit::GetFruitPosX()
	{

		return fruitPosX;

	}

	int Fruit::GetFruitPosY()
	{

		return fruitPosY;

	}

	void Fruit::SetFruitPos(bool x, std::vector<int> snakeX, std::vector<int> snakeY, int size)
	{
		if (x)
		{
			bool valid = false;
			int posX = 0;
			int posY = 0;

			// Ensuring the randommly generated values for x and y do not lie on the snake
			while (valid == false)
			{
				valid = true;
				posX = rand() % 18+1;
				posY = rand() % 18+1;

				for (int x = 0; x < snakeX.size() - 1; x++)
				{
					for (int y = 0; y < snakeY.size() - 1; y++)
					{
						if (posX == snakeX[x] && posY == snakeY[y])
						{
							valid = false;
						}
					}

				}

			}
			fruitPosX = posX;
			fruitPosY = posY;
		}
		
	}

	void Fruit::DrawFruit()
	{

		DrawRectangle(fruitPosX * 40, fruitPosY * 40, 40, 40, RED);

	}

