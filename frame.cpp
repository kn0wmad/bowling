#include "frame.h"
#include <iostream>
#include <string>

// Method definitions
int Frame::calcScore(int roll1, int roll2) {        // Calculate the score for this frame
    int frameScore;
    std::cout << roll1 << " " << roll2 << std::endl;
    frameScore = roll1 + roll2;
    std::cout << frameScore << std::endl;
    return frameScore;
}

void Frame::printScore() {                          // Print the score table for this frame
    std::cout << "Frame score table" << std::endl;
}
