/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 1000;
    int blockSize = 40;

    InitWindow(screenWidth, screenHeight, "SNAKE");

    Game game = Game();
    Snake snake = Snake();
    Fruit fruit = Fruit();
    int currentDirection = 0;
    float timer = 0;
    float timeDelay = 0.25;
    bool fruitEaten;
    bool gameEnding = false;
    
    

    

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
       //----------------------------------------------------------------------------------
        timer += GetFrameTime();
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Drawing the grid
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (i == 0 || i == 19 || j == 0 || j == 19)
                {
                    DrawRectangle(i * blockSize, j * blockSize, blockSize, blockSize, BLACK);
                }
                DrawRectangleLines(i * blockSize, j * blockSize, blockSize, blockSize, BLACK);
            }
        }

        // Drawing the snake
        snake.SnakeDraw();

        // Drawing the fruit
        fruit.DrawFruit();

        // Drawing the score
        DrawText(FormatText("Score: %i", (int)snake.GetScore()), 10, 900, 20, BLACK);


        
        
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        currentDirection = game.GetDirection(currentDirection);
        
        if (timer > (timeDelay) && !gameEnding)
        {
            snake.Move(currentDirection);           

            gameEnding = snake.GameOverCollisionCheck();
            fruitEaten = snake.FruitCollisionCheck(fruit.GetFruitPosX(), fruit.GetFruitPosY());
            fruit.SetFruitPos(fruitEaten, snake.GetSnakePosX(), snake.GetSnakePosY(), snake.GetSize());
            timer = 0;
        }
        
        // Changing the speed of the game

        if (snake.GetScore() == 5)
        {
            timeDelay = 0.2f;
        } else if (snake.GetScore() == 10)
        {
            timeDelay = 0.15f;
        }
        else if (snake.GetScore() == 15)
        {
            timeDelay = 0.1f;
        }
        else if (snake.GetScore() == 20)
        {
            timeDelay = 0.07f;
        }

        EndDrawing();

        // game over text
        if (gameEnding)
        {
            ClearBackground(RAYWHITE);
            DrawText(FormatText("Game Over, press the escape key to exit game"), 10, 850, 30, BLACK);
            
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
            EndDrawing();
        }
        //----------------------------------------------------------------------------------
    }

    // Game Over Screen
    
    // De-Initialization
    //--------------------------------------------------------------------------------------   

    CloseWindow();        // Close window and OpenGL context

    //--------------------------------------------------------------------------------------

    return 0;
}