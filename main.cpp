/*  David Croisant
    Bowling Scoreboard

    A system to produce bowling scores frame-by-frame
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "frame.h"

// Constants
const int TOTAL_FRAMES = 11;

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

    // Create an array of Frame objects
    Frame gameFrames[TOTAL_FRAMES];

    // Iterate through each frame, giving array of objects individual states
    for (int i = 0; i < TOTAL_FRAMES; i++) {

        // Set rolls in each frame
        file >> gameFrames[i].roll1;                // Input first roll from file and assign to object's roll1
        if (gameFrames[i].roll1 != 10) {
            file >> gameFrames[i].roll2;            // Input second roll from file and assign to object's roll2
        }

        std::cout << "Frame |" << " |" << std::endl;
        std::cout << "Throw |" << " |" << std::endl;
        std::cout << "Score |" << " |" << std::endl;

        for (int j = 0; j < i; j++) {
            std::cout << std::setw(2) << i + 1 << std::setw(2);
            if (gameFrames[j].roll1 != 10) {
                std::cout << gameFrames[j].roll1 << gameFrames[j].roll2;
                std::cout << gameFrames[j].Score(gameFrames[j].roll1, gameFrames[j].roll2) << " | ";
            } else {
                std::cout << gameFrames[j].roll1 << " | ";
                std::cout << " X | ";
            }
        }
    }

    // Close the filestream
    file.close();

    return 0;
}
