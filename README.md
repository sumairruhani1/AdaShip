# Adaship

## The problem

I was tasked with creating a game called AdaShip which is a simple spinoff of the classical Battleship game.

In this project, I have implemented a simple terminal-based version of the classic board game BattleShips. Players take turns trying to sink each other's ships by guessing their positions on a grid. The first player to sink all of the opponent's ships wins the game. The program consists of three main classes: `Boat`, `Board`, and `Cell`. The `Boat` class represents a ship in the game, the `Board` class represents the game board, and the `cell` class represents the state of every cell in the board.

In implementing the program, I made effective use of advanced programming principles, such as object-oriented programming, dynamic memory allocation, templates, and exception handling. These principles helped to make the program more efficient, flexible, and robust.

There are a few areas in which the program could be improved, such as user input validation and adding more advanced game mechanics. However, overall the BattleShips program is a functional and enjoyable implementation of the classic board game.

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

## Challenge outline

I chose to create a battleship game using C++. This game would need to have an assortment of features for its MVP, and I have noted these down on my plan document (linked below).

### My Plan

[Link to my plan](https://docs.google.com/document/d/13UaV7jSU51CJ9lkhAKQ08gO38FP95F_x_0V8RdKht04/edit?usp=sharing)

I created a bullet pointed list of all of the features I needed to add to my Battleships game in order to bring it to a standard that I deemed acceptable.

Once I had implemented each feature in that list I would highlight it green and I could move on to the next feature.

I also created a very brief outline of my planned classes (Boat, Board, Cell) and what member functions/variables they would need to include. I placed any notes of my plans into this document.

There is a diagram of all the different states the game will go through while the user is playing, which was present to help me remember what was next in the game flow.

I opted for an agile approach while developing my program, so there is very little documentation available in my plan.

All epics were decomposed into features that were added into the bullet point list in my plan document, and I used this for tracking my progress on the games development. Once all the criteria in the game was fulfilled, then the game could be said to be in a working and functioning state. (Though this is not accounting for the quality of the implementation)

## Reflection

In designing and implementing the BattleShips program, I encountered several key design challenges and innovations.

One of the main challenges was organizing the game logic and managing the overall flow of the game. I had to consider how to structure the program in a way that would allow for the game to be played in a logical and intuitive manner, while also allowing for flexibility in terms of customizing the game's rules and settings. To solve this challenge, I divided the program into three main classes: `Boat`, `Board`, and `Game`. The `Boat` class handles the ship objects and their properties, the `Board` class handles the game board and the placement of ships, and the `Game` class handles the overall flow of the game and the interaction between the players.

Another challenge was handling user input and ensuring that the program could handle a wide range of possible inputs. To solve this challenge, I implemented functions such as `importBoardConfigData` and `importBoatConfigData` to read in configuration data from external files, and I used stringstreams to parse the input strings and extract the relevant data.

One innovation that I implemented in the program was the use of the `resetShips` function in the `Boat` class. This function allows for all of the ships to be reset between game rounds, so that players can start a new game with a fresh set of ships.

Overall, the design and implementation of the BattleShips program required careful planning and attention to detail, and solving the various challenges and innovations helped to create a functional and enjoyable game.

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

## Advanced Programming Principles

In implementing the BattleShips program, I made effective use of several advanced programming principles, including:

- Object-oriented programming (OOP): I used OOP principles, such as encapsulation, inheritance, and polymorphism, to design and implement the program. For example, the `Boat` class encapsulates the data and behavior of a ship in the game, the `Board` class inherits from the `Boat` class and adds additional functionality specific to the game board, and the `Game` class uses polymorphism to handle the interaction between different types of players (human or AI).

- Dynamic memory allocation: I used dynamic memory allocation, such as the `new` and `delete` operators, to allocate and deallocate memory for objects in the program. For example, in the `Game` class, I used dynamic memory allocation to create a new `Board` object for each game round.

- Templates: I used templates, such as the `std::vector` template, to create flexible data structures that can store objects of any type. For example, I used the `std::vector` template to create a dynamic array of `Boat` objects in the `Game` class, which allows for a variable number of ships to be used in the game.

- Exception handling: I used exception handling, such as the `try` and `catch` statements, to handle potential errors and exceptions in the program. For example, in the `plotShip` function of the `Board` class, I used exception handling to catch any errors that might occur when parsing the input string.

Overall, the effective use of these advanced programming principles helped to make the BattleShips program more efficient, flexible, and robust.

## Areas for Improvement

There are a few areas in which the BattleShips program could be improved:

- User input validation: Currently, the program does not validate user input very thoroughly, and it is possible for players to enter invalid or inappropriate input that could cause the program to crash or behave unexpectedly. Adding more robust input validation checks could help to prevent these issues.

- Game mechanics: The current implementation of the game mechanics is relatively simple and does not include features such as multiple types of ships with different sizes and properties, or more advanced strategies such as allowing players to place their ships on the board in different configurations. Adding these features could make the game more interesting and challenging.

- User interface: The current user interface is very basic and consists of simple text-based prompts and inputs. Improving the user interface, for example by using a more visually appealing layout or by adding support for graphical displays, could make the game more enjoyable to play.

- Code organization and modularity: The current code could be organized and structured more effectively, for example by separating the game logic from the user interface, or by breaking up large functions into smaller, more modular ones. This could make the code easier to understand and maintain.

I had developed my program with the intention of keeping the various different classes and features in separate header and code files, however various bugs had plagued my code before the assignment deadline, forcing me to keep my code in a monolithic structure with all of the code in main.cpp

## Potential Future Improvements

Here are some potential future improvements I could add if I get the opportunity to work on this program again:

- General robustness: Making the current program more robust by facilitating and handling erroneous inputs. Likewise, fixing all potential present bugs in the program.

- Player 2 opponent: Currently, the program only allows for one computer to play against a human. Adding an option for a player to play against another and make strategic guesses could make the game more challenging and exciting to play.

- Customizable board sizes: Allowing players to select the size of the game board could add an additional level of strategy to the game and make it more customizable.

- More advanced game mechanics: Adding more advanced game mechanics, such as special abilities or power-ups that can be used during play, could make the game more dynamic and varied.

- Improved user interface: Improving the user interface, for example by adding support for graphics or visual effects, could make the game more visually appealing and immersive.
