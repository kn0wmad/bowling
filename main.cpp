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
    for (int i = 0; i < TOTAL_FRAMES; ++i) {
        int currentFrame;                               // Current frame
        gameFrames[i].frame = i + 1;
        currentFrame = gameFrames[i].frame;

        file >> gameFrames[i].roll1;                    // Input first roll from file and assign to new var for reuse
        int frameRoll1 = gameFrames[i].roll1;
        int frameRoll2;

        int nextRoll1 = gameFrames[i + 1].roll1;
        int nextRoll2 = gameFrames[i + 1].roll2;

        if (frameRoll1 < 10) {                          // Take second roll from file, only if not a strike
            file >> gameFrames[i].roll2;
            frameRoll2 = gameFrames[i].roll2;
        } else if (frameRoll1 == 10) {
            gameFrames[i].score = gameFrames[i].calcScore(&frameRoll1, &frameRoll2, nextRoll1, nextRoll2);
            gameFrames[i].printScore(currentFrame, frameRoll1, frameRoll2, gameFrames[i].score);
            continue;
        }

        // Calculate frame score
        gameFrames[i].score = gameFrames[i].calcScore(&frameRoll1, &frameRoll2, nextRoll1, nextRoll2);

        // Print score table
        gameFrames[i].printScore(currentFrame, frameRoll1, frameRoll2, gameFrames[i].score);
    }

    // Close the filestream
    file.close();

    return 0;
}
