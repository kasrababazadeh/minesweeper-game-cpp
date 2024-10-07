# Minesweeper Game

A simple text-based Minesweeper game implemented in C++. This game allows players to set up a customizable grid size and the number of mines. The objective is to reveal all non-mined tiles without triggering any mines.

## Table of Contents
- [Features](#features)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Future Enhancements](#future-enhancements)
- [License](#license)

## Features

- Customizable grid size (rows and columns).
- Customizable number of mines.
- Classic Minesweeper gameplay:
  - Reveal tiles and try to avoid mines.
  - Flag suspected mines.
  - Automatically reveal neighboring empty tiles.
- Clear win/loss conditions:
  - Win by revealing all non-mine tiles.
  - Lose by stepping on a mine.
- Ability to restart the game after it ends.

## How to Play

1. **Set up the game**:
   - When the game starts, you will be asked to choose the grid size (number of rows and columns) and the number of mines to be placed on the board.
   
2. **Gameplay**:
   - Enter row and column numbers to select a tile.
   - Choose an action:
     - `1`: Reveal the selected tile.
     - `2`: Flag the selected tile as a suspected mine.
     - `3`: Cancel the selection.
   - The game will update the display board after each move.
   
3. **Winning**:
   - Reveal all non-mine tiles to win the game.
   
4. **Losing**:
   - If you reveal a mine, the game will end, and the full board will be shown.

5. **Restart or Exit**:
   - After the game ends, you will have the option to either restart or exit.

## Installation

To run the Minesweeper game on your local machine:

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/minesweeper-game.git
   cd minesweeper-game

## Compile the Program

To compile the program, follow the instructions below:

2. For Windows (using a g++ compiler):
   ```bash
   g++ -o minesweeper minesweeper.cpp

- For Other Systems
You may need to modify the code slightly to remove the Windows-specific libraries like windows.h.

## Run the Compiled Game

3. To run the compiled game, use the following command:
   ```bash
   ./minesweeper

## Usage

Upon running the program, you will be prompted to enter the desired grid size (rows and columns) and the number of mines. Use the command line to interact with the game by entering the row and column of the tile you want to reveal or flag. Follow the game instructions to reveal tiles, flag suspected mines, and try to avoid stepping on a mine!

## Code Overview

The main components of the code are:

### Main Game Logic:
- **`main()`**: Initializes the game and prompts user input.
- **`mineSweeper()`**: Initializes the board and randomly places mines.
- **`mineCounter()`**: Populates the board with numbers indicating how many mines are nearby each tile.
- **`playGame()`**: The main game loop where the player interacts with the board.

### User Input:
- **`enterRow()`** and **`enterCol()`**: Prompts the user for valid row and column inputs.

### Display Functions:
- **`showGame()`**: Displays the current state of the board, either the player's view or the full game board.

### Game Logic:
- **`environsZero()`**: Automatically reveals neighboring empty tiles if the player uncovers a tile with no adjacent mines.
- **`checkGame()`**: Checks whether the player has successfully revealed all non-mine tiles.

### End Game:
- **`playAgain()`**: Asks the user if they want to restart the game or exit.

## Future Enhancements

Some potential improvements that could be made to this project:

- **Cross-Platform Compatibility**: Replace Windows-specific libraries like `windows.h` and `system("cls")` with more portable alternatives.
- **Graphical User Interface (GUI)**: Implement a graphical interface to replace the current text-based interaction.
- **Difficulty Levels**: Add predefined difficulty levels such as "Easy", "Medium", and "Hard".
- **Save/Load Game**: Implement a feature to save the current state of the game and load it later.

## License

This project is open-source and available under the [MIT License](LICENSE).

