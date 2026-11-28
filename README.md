# Snake Game

<img width="800" height="789" alt="SnakeGame" src="https://github.com/user-attachments/assets/68044b05-c006-4f6e-8cfe-605db5bc38be" />

A classic Snake game built in **C++** using **Raylib**.

Control the snake, collect fruit, grow longer, and try to fill the entire board without colliding with yourself or the walls.

## Features

- Grid-based movement
- Random fruit spawning
- Snake growth system
- Self-collision detection
- Wall collision detection
- Win condition when the board is filled
- Automatic restart after game over
- Built with Raylib

## Controls

| Key | Action |
|------|--------|
| ↑ | Move Up |
| ↓ | Move Down |
| ← | Move Left |
| → | Move Right |
| SHIFT | Fruit Tracker |

## Gameplay

- Collect fruit to grow the snake.
- Each fruit increases the snake's length by one segment.
- Hold Left-Shift to see the fastest route towards the fruit
- Avoid colliding with the walls.
- Avoid colliding with your own body.
- Fill the board to win the game.

## Requirements

- C++17 or newer
- Raylib

## Build Instructions

Clone the repository:

```bash
git clone https://github.com/yourusername/snake-game.git
```

Open the project in Visual Studio and build normally.

## Project Structure

```
.
├── Snake.cpp
├── Snake.h
├── Piece.h
├── Line.h
├── Resources/
└── README.md
```

## Technical Details

### Movement

The game uses grid-based movement with a fixed update interval for consistent gameplay regardless of frame rate.

### Fruit Generation

Fruit is spawned at a random unoccupied tile and cannot appear inside the snake's body.

### Game Over Conditions

The game ends when:

- The snake collides with a wall.
- The snake collides with itself.

### Win Condition

The player wins when the snake occupies every tile on the board.

## Future Improvements

- Score system
- High score saving
- Sound effects
- Pause menu
- Difficulty settings
- Mobile controls
- Animated transitions

## Built With

- C++
- Raylib

## License

This project is licensed under the MIT License.

Feel free to use, modify, and distribute the source code.
```
MIT License

Copyright (c) 2026

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files...
```

## Author

Made by [Divine Manome]
