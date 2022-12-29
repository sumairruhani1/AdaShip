#include "../include/index.hpp"

// void tutorialInstructions() {
//   std::cout << "Welcome to AdaShip!" << std::endl <<std::endl;
//   std::cout 
//     << "AdaShip is a spinoff version of the classic battleships game and the rules are simple. \n"
//     << "Firstly, you and your opponent will tactically place ships on your boards. Following this you \n"
//     << "take turns firing torpedoes at your opponents ships with the intent of hitting all of theirs, \n"
//     << "while not getting hit yourself. \n\n"
//     << "If you destroy all your opponents ships before they can destroy yours then you have won." << std::endl << std::endl;
// }

// void menuOptions() {
//   int option;
//   std::cout << "Menu:" << std::endl;
//   std::cout << "1. One Player vs Computer" << std::endl;
//   std::cout << "2. Quit Game" << std::endl << std::endl;
//   std::cout << "Enter option: ";
//   std::cin >> option;

//   if (option == 1) {
//     importBoardConfigData("./adaship_config.ini");
//     importBoatConfigData("./adaship_config.ini");
//   } else if (option == 2) {
//     std::exit;
//   } else {
//     std::cout << ("You haven't entered a valid option");
//   }
// }