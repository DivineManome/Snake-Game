#include "Snake.h"
#include "raylib.h"
#include <ctime>
#include <string>

void Snake::Main()
{
	srand((unsigned int)time(nullptr));
	Start();
	InitWindow(screenWidth, screenHeight, "Snake Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GREEN);
		Update();
		EndDrawing();
	}

	CloseWindow();
}

void Snake::Start()
{
	// Vertical lines
	for (int i = 0; i < screenWidth / TILE_SIZE + 1; i++)
	{
		float x = min.x + TILE_SIZE * i;
		Vector2 s = Vector2{ x, min.y };
		Vector2 e = Vector2{ x, max.y };
		Line line = Line(s, e);
		grid.push_back(line);
	}

	// Horizontal lines
	for (int i = 0; i < screenHeight / TILE_SIZE + 1; i++)
	{
		float y = min.y + TILE_SIZE * i;
		Vector2 s = Vector2{ min.x, y };
		Vector2 e = Vector2{ max.x, y };
		Line line = Line(s, e);
		grid.push_back(line);
	}

	// Player
	Piece head;
	head.color = DARKBLUE;

	Vector2 randomPosition = indexToScreen(false, 1, 3);

	head.position = randomPosition;
	player.push_back(head);

	fruit.color = RED;
	fruit.position = indexToScreen(false, 6, 3); // it shouldn't be where the head or any pieces of the tale are

	speed = Vector2{ TILE_SIZE, 0 };
	nextSpeed = Vector2{TILE_SIZE, 0};
}
void Snake::Update()
{
	frameCount++;
	if (player.size() >= numberOfTiles) // win
	{ 
		gameEnded = true; 
		player[0].color = WHITE; 
		for (int i = 1; i < player.size(); i++)
		{
			player[i].color = LIME;
		}
	}
	if (gameEnded == false)
	{
		if (IsKeyPressed((KEY_DOWN)) && speed.y == 0)
		{
			nextSpeed = Vector2{ 0, TILE_SIZE };

		}
		if (IsKeyPressed((KEY_UP)) && speed.y == 0)
		{
			nextSpeed = Vector2{ 0, -TILE_SIZE };
		}
		if (IsKeyPressed((KEY_RIGHT)) && speed.x == 0)
		{
			nextSpeed = Vector2{ TILE_SIZE, 0 };
		}
		if (IsKeyPressed((KEY_LEFT)) && speed.x == 0)
		{
			nextSpeed = Vector2{ -TILE_SIZE, 0 };
		}

		if (frameCount % 20 == 0)
		{
			speed = nextSpeed;
			if (player.size() >= 2)
			{
				for (int i = 2; i < player.size(); i++)
				{
					if (player[0].position == player[i].position)
					{
						gameEnded = true;
						break;
					}
				}
			}
			if (player[0].position.x < 0 || player[0].position.x > screenWidth || player[0].position.y > screenHeight || player[0].position.y < 0)
			{
				gameEnded = true;
			}
			for (int i = player.size() - 1; i > 0; i--)
			{
				player[i].position = player[i - 1].position;
			}
			// moved the head
			player[0].position += speed;

			if (player[0].position == fruit.position) // ran into a fruit
			{
				Piece tail;
				tail.color = BLUE;
				tail.position = player[player.size() - 1].position;
				player.push_back(tail);
				fruit.position = indexToScreen(true); // it shouldn't be where the head or any pieces of the tale are
			}
		}
	}
	else
	{
		Restart();
	}

	for (Piece p : player)
		p.Draw();

	fruit.Draw();

	for (Line l : grid)
		l.Draw();
}

void Snake::Restart()
{
	if (gameEndTimer >= 0.0f)
	{
		gameEndTimer -= GetFrameTime();
	}
	else
	{
		gameEndTimer = 2.0f;
		gameEnded = false;
		player.clear();
		Start();
	}
}
