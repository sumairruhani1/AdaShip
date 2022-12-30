# Adaship

## The problem
I was tasked with creating a game called AdaShip which is a simple spinoff of the classical Battleship game.

My program consists of two classes: `Boat` and `Board`.

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

The `Board` class has a constructor that initializes a 2D vector of `Cell` objects to represent the game board, with all cells initially having `isShip` set to `false` and `isHit`

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
- The `Boat` and `Board` classes are separated into their own header and implementation files, with the implementation file `#include`ing the header file. This helps to organize the code and minimize dependencies between different parts of the program.
- The `Boat` and `Board` classes have clear and well-defined interfaces, with each class having a clear purpose and responsibility. This makes it easy to understand the role of each class in the overall program.
- The `Board` class uses a 2D vector to represent the game board, which is an efficient and flexible data structure for storing the state of the game board.
- The `plotShip` function takes a string representing the position of the top-left cell of the ship and parses it to extract the row and column indices. This allows the function to accept user input in a convenient and user-friendly format, while still being able to easily extract the necessary information.
- The `shoot` function takes a string representing the position of the targeted cell and parses it to extract the row and column indices. This allows the function to accept user input in a convenient and user-friendly format, while still being able to easily extract the necessary information.
- The `printBoard` function uses the `setw` function from the `iomanip` library to align the output and make it more visually appealing.
- The `main` function includes a loop that continues until all ships on the game board have been sunk, allowing the game to continue until one player wins.
- The program uses a `mt19937` random number generator from the `random` library to randomly place the ships on the game board, adding an element of chance to the game.

Overall, this program demonstrates good programming standards and practices by following a clear and organized structure, using appropriate data structures and algorithms, and handling user input in a user-friendly and flexible way.