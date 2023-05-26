#include "Snake.h"
#include "Fruit.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include "Raylib.h"
#include "Raygui.h"


Snake::Snake()
{
	// Defining the starting point of the snake, negative numbers ensure the snake doesnt close in on itself before a movement is made
	headPosX = 9;
	snakePosX.push_back(-1);
	snakePosX.push_back(-2);
	headPosY = 9;
	snakePosY.push_back(-1);
	snakePosY.push_back(-2);
	size = 3;
	score = 1;
}

Snake::~Snake()
{

}

void Snake::Move(int d)
{
	
	// dont update if the snake has not started moving
	if (d == 0)
	{
		return;
	}

	// push the elements of the snake vectors back when the snake is moving
	int tempX = snakePosX[0];
	int tempY = snakePosY[0];
	int temp2X, temp2Y;

	snakePosX[0] = headPosX;
	snakePosY[0] = headPosY;

	for (int i = 0; i < size - 1; i++)
	{
		temp2X = snakePosX[i];
		temp2Y = snakePosY[i];
		snakePosX[i] = tempX;
		snakePosY[i] = tempY;
		tempX = temp2X;
		tempY = temp2Y;
	}

	// Updating the snake head's position
	
	if (d == 1)
	{
		headPosY--;
	}
	else if (d == 2)
	{
		headPosX--;
	}
	else if (d == 3)
	{
		headPosY++;
	}
	else if (d == 4)
	{
		headPosX++;
	}
		
	

}

std::vector<int> Snake::getSnakePosX()
{

	return snakePosX;

}

std::vector<int> Snake::getSnakePosY()
{

	return snakePosY;

}

int Snake::getSize()
{

	return size;

}

void Snake::increaseSize()
{
	size++;
}

int Snake::getHeadPosX()
{
	return headPosX;
}

int Snake::getHeadPosY()
{
	return headPosY;
}

float Snake::getScore()
{
	return score;
}

// Collision check when the snake head hits a fruit
bool Snake::FruitCollisionCheck(int fPosX, int fPosY)
{

	// checking is the snake position is equal to the fruit's position
	if (headPosX == fPosX && headPosY == fPosY)
	{
		// adding elements to the vectors
		snakePosX.push_back(headPosX);
		snakePosY.push_back(headPosY);
		increaseSize();
		score++;
		return true;
	}

	return false;

}

void Snake::SnakeDraw()
{

	// drawing the snake head in dark green and the body in green
	for (int i = 0; i < snakePosX.size(); i++)
	{
		DrawRectangle(snakePosX[i] * 40, snakePosY[i] * 40, 40, 40, GREEN);
	}
	DrawRectangle(headPosX * 40, headPosY * 40, 40, 40, DARKGREEN);
}
 
// Collision check when the game rules have been broken
bool Snake::GameOverCollisionCheck()
{

	// checking whether the head position isequal to the grid borders
	if (headPosX == 0 || headPosX == 19 || headPosY == 0 || headPosY == 19)
	{
		return true;
	}

	// checking whether any snake position comes in contact with the snakes head
	for (int i = 1; i < size-1; i++)
	{
		if (snakePosX[i] == headPosX && snakePosY[i] == headPosY)
		{
			return true;
		}
	}
	
	return false;
}

