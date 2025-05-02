/*  David Croisant
    Bowling Scoring

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

    // Iterate through each frame
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        gameFrames[i].frame = i;                                                // Current frame
        file >> gameFrames[i].roll1;                                            // Input first roll from file
        file >> gameFrames[i].roll2;                                            // Input second roll from file
        gameFrames[i].score =                                                   // Calculate frame score
            gameFrames[i].calcScore(gameFrames[i].roll1, gameFrames[i].roll2);

        gameFrames[i].printScore();                                             // Print frame score table
    }

    // Close the filestream
    file.close();

    return 0;
}
