#include "frame.h"
#include <iostream>
#include <string>

// Method definitions
int Frame::calcScore(int roll1, int roll2) {        // Calculate the score for this frame
    int frameScore;
    // std::cout << roll1 << " " << roll2 << std::endl;
    frameScore = roll1 + roll2;
    // std::cout << frameScore << std::endl;
    return frameScore;
}

void Frame::printScore(int frame, int roll1, int roll2, int frameScore) {                          // Print the score table for this frame
    std::cout << "Frame | " << frame << " | " << std::endl;
    std::cout << "Throw | " << roll1 << " " << roll2 << " | " << std::endl;
    std::cout << "Score | " << frameScore << " | " << std::endl;
}
