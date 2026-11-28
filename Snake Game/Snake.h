#pragma once
#include "raylib.h"
#include "raymath.h"

#include <utility>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

class Snake
{
public:

#define TILE_SIZE 100

	static const int screenWidth = 800;
	static const int screenHeight = 800;
	static const int numberOfTiles = 64; // change this according to the screen Width & Height

	Vector2 borderGap = Vector2{ screenWidth % TILE_SIZE, screenHeight % TILE_SIZE };

	int maxRow = (int)(screenWidth / TILE_SIZE) - 1;
	int maxCol = (int)(screenHeight / TILE_SIZE) - 1;

	Vector2 min = Vector2{ borderGap.x / 2, borderGap.y / 2 };
	Vector2 max = Vector2{ screenWidth - borderGap.x / 2, screenHeight - borderGap.y / 2 };


	Vector2 indexToScreen(bool random = false, int r = -1, int c = -1)
	{
		if (player.size() >= numberOfTiles) { return {-1,-1}; }
		tuple <int, int> rowCol{ 0, 0 };
		float x = 0;
		float y = 0;
		// int (row, col);
		if (random)
		{
			while (true)
			{
				bool isNew = true;
				get<0>(rowCol) = GetRandomValue(0, maxRow);
				get<1>(rowCol) = GetRandomValue(0, maxCol);

				x = min.x + get<0>(rowCol) * TILE_SIZE;
				y = min.y + get<1>(rowCol) * TILE_SIZE;

				for (int i = 0; i < player.size(); i++)
				{
					if (player[i].position == Vector2{ x,y })
					{
						isNew = false;
						break;
					}
				}
				if (isNew) { break; }
			}
		}
		else
		{
			get<0>(rowCol) = r;
			get<1>(rowCol) = c;

			x = min.x + get<0>(rowCol) * TILE_SIZE;
			y = min.y + get<1>(rowCol) * TILE_SIZE;
		}


		if (get<0>(rowCol) > maxRow || get<1>(rowCol) > maxCol || get<1>(rowCol) < 0 || get<1>(rowCol) < 0)
			return Vector2{ 0, 0 };

		return Vector2{ x, y };
	}



	struct Line
	{
		Vector2 start, end;

		Line(Vector2 s, Vector2 e)
		{
			this->start = s;
			this->end = e;
		}

		void Draw()
		{
			DrawLineV(start, end, GRAY);
		}
	};

	vector<Line> grid;

	struct Piece
	{
		Vector2 position; // top left
		Vector2 size = Vector2{ TILE_SIZE, TILE_SIZE };
		Color color;

		void Draw()
		{
			DrawRectangleV(position, size, color);
		}
	};

	vector<Piece> player;
	Vector2 speed = Vector2{ TILE_SIZE, 0 };
	int frameCount = 0;
	float gameEndTimer = 2.0f; // how long you want to wait until the new game starts
	bool gameEnded = false;

	Vector2 nextSpeed = speed;

	Piece fruit;

	void Main(); // the Raylib stuff
	void Start(); // where starting stuff goes
	void Update(); // frame by frame calculation
	void Restart();
	void DrawLineToFruit();
};