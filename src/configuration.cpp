#include "../include/index.hpp"

// void importBoardConfigData(std::string filename) {
//   // file handling for adaship_config.ini file
//   std::ifstream file;
//   file.open(filename); // open file
//   std::string line;
//   if (file) {
//     while (std::getline(file, line)) {
//       line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

//       if (line.find("Board") != -1) {
//         int startPointer = line.find(":") + 1;           // Initial pointer
//         int endPointer = line.find("x") + 1; // Secondary pointer
//         int diff = endPointer - startPointer;            // string difference
//         std::string height = line.substr(startPointer, diff - 1);
//         std::string width = line.substr(endPointer);
//         std::cout << "Board Height is " << height << " and width is " << width
//                   << std::endl;
//       }
//     }
//   }
//   else {
//     std::cout << "Could not find or open adaship_config.ini" << std::endl;
//   }
// };

// void importBoatConfigData(std::string filename) {
//   // file handling for adaship_config.ini file
//   std::ifstream file;
//   file.open(filename); // open file
//   std::string line;
//   if (file) {
//     while (std::getline(file, line)) {
//       line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

//       if (line.find("Boat") != -1) {
//         int startPointer = line.find(":") + 1;           // Initial pointer
//         int endPointer = line.find(",") + 1; // Secondary pointer
//         int diff = endPointer - startPointer;            // string difference
//         std::string boatType = line.substr(startPointer, diff - 1);
//         std::string boatName = line.substr(endPointer);
//         std::cout << boatType << " Health: " << boatName << std::endl;
//       }
//     }
//   }
//   else {
//     std::cout << "Could not find or open adaship_config.ini" << std::endl;
//   }
// };
