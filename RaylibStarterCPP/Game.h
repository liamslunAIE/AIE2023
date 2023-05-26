#pragma once
#include "Snake.h"
#include "Fruit.h"
#include <vector>


	class Game
	{

	private:

		int gridWidth = 20;
		int gridHeight = 20;
		bool isOver;

	public:
		Game();
		~Game();

		void IsOverTrue();
		bool GetOver();
		int GetDirection(int p);

	};

