#include "frame.h"
#include <string>

// Method definitions

// Calculate score for each frame
std::string Frame::Score(int roll1, int roll2) {
    std::string frameScore;

    // TODO bonus logic

    frameScore = std::to_string(roll1 + roll2);
    return frameScore;
}
