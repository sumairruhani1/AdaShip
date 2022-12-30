// #pragma once 

// #include "./index.hpp"

// // Board class
// class Board {
// public:
//   static int boardHeight; // height of the game board
//   static int boardWidth;  // width of the game board

//   // represent a cell on the game board
//   class Cell {
//   public:
//     Cell();
//     bool isShip; // whether there is a ship at this cell
//     bool isHit;  // whether this cell has been hit by a shot
//   };

//   // initialize the game board
//   Board();

//   // check if a cell is within the bounds of the game board
//   bool isValidCell(int x, int y);

//   bool canPlaceShip(int x, int y, int length, bool isVertical);

//   // place a ship on the game table
//   void placeShip(int x, int y, int length, bool isVertical);

//   // plot a ship on the game table
//   void plotShip(const std::string &position, Boat &boat, bool isVertical);

//   // print the game board
//   void printBoard();

//   // shoot at a cell on the game board
//   bool shoot(const std::string &position);

//   // check if all ships on the game board have been sunk
//   bool allShipsSunk();

//   // automatically plot remaining ships
//   void autoPlotShips(std::vector<Boat> &boats);

//   std::vector<std::vector<Cell>> gameBoard;
// };