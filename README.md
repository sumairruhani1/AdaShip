# Battleship

This program implements a simple version of the classic board game Battleship. It consists of two classes: `Boat` and `Board`.

## Boat

The `Boat` class represents a boat in the game. It has three member variables:

- `length`: an integer representing the length of the boat
- `name`: a string representing the name of the boat
- `isPlaced`: a boolean indicating whether the boat has been placed on the game board

It also has a static member function `resetShips`, which takes a vector of `Boat` objects and sets the `isPlaced` member variable of each `Boat` object to `false`.

## Board

The `Board` class represents the game board. It has two static member variables:

- `boardHeight`: an integer representing the height of the game board
- `boardWidth`: an integer representing the width of the game board

It has a nested class `Cell`, which represents a cell on the game board. The `Cell` class has two member variables:

- `isShip`: a boolean indicating whether there is a ship at that cell
- `isHit`: a boolean indicating whether that cell has been hit by a shot

The `Board` class has a constructor that initializes a 2D vector of `Cell` objects to represent the game board, with all cells initially having `isShip` set to `false` and `isHit` set to `false`.

The `Board` class has several member functions:

- `isValidCell` takes two integers `x` and `y` and returns a boolean indicating whether the cell at position `(x, y)` is within the bounds of the game board.
- `canPlaceShip` takes four integers `x`, `y`, `length`, and `isVertical` and returns a boolean indicating whether it is possible to place a ship of length `length` on the game board, with the top-left cell of the ship at position `(x, y)` and orientation `isVertical`.
- `placeShip` takes four integers `x`, `y`, `length`, and `isVertical` and places a ship of length `length` on the game board, with the top-left cell of the ship at position `(x, y)` and orientation `isVertical`.
- `plotShip` takes a string representing the position of the top-left cell of the ship on the game board, a reference to a `Boat` object, and a boolean `isVertical` indicating the orientation of the ship. It attempts to place the ship on the game board at the specified position, and prints an error message if it is not possible to do so.
- `printBoard` prints the current state of the game board to the console.
- `shoot` takes a string representing the position of the cell on the game board that is being targeted, and returns a boolean indicating whether a ship was hit at that cell.
- `allShipsSunk` returns a boolean indicating whether all ships on the game board have been sunk.

## Good programming practices demonstrated in this program

- The code follows a consistent indentation style and uses descriptive variable names, making it easy to read and understand.
- The `Boat` and `Board` classes are separated into their own header and implementation files, with the implementation file `#include`ing