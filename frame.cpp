#include "frame.h"
#include <iostream>
#include <string>

// Method definitions
// Calculate score for each frame
int Frame::calcScore(int roll1, int roll2) {
    int frameScore;

    if (roll1 == 10) {

    } else {
        frameScore = roll1 + roll2;
    }

    return frameScore;
}

// Print frame score table iteratively, to include each previous frame
void Frame::printScore(int frame, int roll1, int roll2, int frameScore) {
    // Frames
    std::cout << "Frame | ";

    for (int i = 0; i < frame; i++) {          // Iterate frame index for each frame
        std::cout << frame << " | ";
    }
    std::cout << std::endl;

    // Throws
    std::cout << "Throw | ";                    // Iterate throw for each frame
    for (int j = 0; j < frame; j++) {
        std::cout << roll1 << " " << roll2 << " | ";
    }
    std::cout << std::endl;

    // Scores
    std::cout << "Score | ";                    // Iterate Score for each frame
    for (int k = 0; k < frame; k++) {
        std::cout << frameScore << " | ";
    }
    std::cout << std::endl << std::endl;
}
