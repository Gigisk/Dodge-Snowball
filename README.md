# Dodge Snowball

**A fun 2D game where the player controls a penguin and must dodge falling snowballs to survive.**

## Project Overview

This project was created in 2023 during my senior year of high school. It is a simple 2D game developed in C++ using the SFML library (version 2.5.1). The objective of the game is to control a penguin character that must dodge falling snowballs. The game speeds up over time, and more snowballs spawn, increasing the difficulty. The penguin has 3 hearts, and when all hearts are lost, the game ends.

## Features

- **Penguin Character**  
  - The player controls a penguin that must dodge falling snowballs.
  - The penguin has 3 hearts, and each time it gets hit by a snowball, a heart is lost.

- **Game Mechanics**  
  - The game speeds up as time progresses, with more snowballs spawning on the screen.
  - The game ends when the penguin loses all 3 hearts.

- **SFML (Simple and Fast Multimedia Library)**  
  - The game is built using the SFML library (version 2.5.1) for handling graphics, window management, and game mechanics.

## How It Works

Upon running the game, the player controls the penguin to dodge the snowballs that fall from the top of the screen. The game keeps track of the number of hearts left. As time passes, the game speeds up, and more snowballs appear, making it more challenging. If the penguin gets hit by a snowball, a heart is lost. When all hearts are lost, the game ends.

## How to Run the Program

To run the game, follow these steps:

1. **Open VS Code** and launch the terminal.

2. **Compile the code** using `make`:
   ```bash
   make

3. **Run the compiled program** using `./app`:
   ```bash
   ./app
