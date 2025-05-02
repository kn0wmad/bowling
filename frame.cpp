#include "frame.h"
#include <iomanip>
#include <iostream>

// Method definitions
// Calculate score for each frame
int Frame::calcScore(int roll1, int roll2) {
    int frameScore;

    if (roll1 == 10) {
        frameScore = 10;
    } else if ((roll1 + roll2) == 10) {
        frameScore = 10;
    } else {
        frameScore = roll1 + roll2;
    }

    return frameScore;
}

// Print frame score table iteratively, to include each previous frame
void Frame::printScore(int frame, int roll1, int roll2, int frameScore) {
    // Frames
    std::cout << "Frame |";
    for (int i = 0; i < frame; i++) {          // Iterate frame index for each frame
        if (i < 9) {
            std::cout << std::setw(3) << (i + 1) <<  std::setw(3) << "|";
        } else {
            std::cout << std::setw(3) << (i + 1) <<  std::setw(2) << "|";
        }
    }
    std::cout << std::endl;

    // Throws
    std::cout << "Throw |";
    for (int j = 0; j < frame; j++) {           // Iterate throw for each frame
        std::cout << std::setw(2) << roll1 << " " << roll2 << std::setw(2) << "|";
    }
    std::cout << std::endl;

    // Scores
    std::cout << "Score |";
    for (int k = 0; k < frame; k++) {           // Iterate Score for each frame
        std::cout << std::setw(3) << frameScore <<  std::setw(3) << "|";
    }
    std::cout << std::endl << std::endl;
}
