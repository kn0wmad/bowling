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

        std::cout << "Frame |";         // Print frames

        for (int j = 0; j <= i; j++) {
            gameFrames[i].frame += 1;
            std::cout << std::setw(3) << gameFrames[i].frame << std::setw(3) << " |" << std::setw(1);
        }

        std::cout << std::endl;
        std::cout << "Throw |";         // Print rolls

        for (int k = 0; k <= i; k++) {
            gameFrames[k].isStrike(gameFrames[k - 1].roll1);
            gameFrames[k].isSpare(gameFrames[k - 1].roll1, gameFrames[k].roll2);
            std::cout << std::setw(2) << gameFrames[k].roll1 << " " << gameFrames[k].roll2 << std::setw(2) << " |";
        }

        std::cout << std::endl;
        std::cout << "Score |";         // Print scores

        for (int l = 0; l <= i; l++) {
            std::cout << std::setw(3) << gameFrames[l].Score(gameFrames[l].roll1, gameFrames[l].roll2, gameFrames[l].bonus) << std::setw(3) << " |" << std::setw(1);
            // } else {
            //     std::cout << std::setw(3) << gameFrames[l].Score(gameFrames[l].roll1, gameFrames[l].roll2) + gameFrames[l - 1].Score(gameFrames[l - 1].roll1, gameFrames[l - 1].roll2) << std::setw(3) << " |" << std::setw(1);
            // }
        }

        std::cout << std::endl << std::endl;
    }

    // Close the filestream
    file.close();

    return 0;
}
