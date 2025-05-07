/*  David Croisant
    Bowling Scoreboard

    A system to produce bowling scores frame-by-frame
*/

#include <fstream>
#include <iostream>
#include <string>
#include "frame.h"

// Constants
const int TOTAL_FRAMES = 10;
const int MAX_ROLLS = 21;

int main() {
    // Get file from user
    std::string bowlerFile;
    std::cout << "Enter bowler file: " << std::endl;
    std::cin >> bowlerFile;

    // Open file to stream and verify it opened correctly
    std::ifstream file(bowlerFile);
    if (!file.is_open()) {
        std::cout << "Error reading file: " << bowlerFile << std::endl;
    }

    // Create an array of Frame objects for the full game
    Frame gameFrames[TOTAL_FRAMES];

    // Iterate through each frame, giving array of objects individual states
    for (int i = 0; i < TOTAL_FRAMES; ++i) {

        // Set rolls in each frame
        file >> gameFrames[i].roll1;                 // Input first roll from file and assign to new var for reuse

    }

    // Close the filestream
    file.close();

    return 0;
}
