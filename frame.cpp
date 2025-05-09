#include "frame.h"
#include <string>

// Method definitions

// Calculate score for each frame
std::string Frame::Score(int roll1, int roll2, int &bonus) {
    std::string frameScore;

    if (isStrike(roll1) == true) {
        bonus = 10;
        return frameScore = "X";
    } else if (isSpare(roll1, roll2) == true) {
        bonus = 10;
        return frameScore = "/";
    } else {
        frameScore = std::to_string(roll1 + roll2);
        return frameScore;
    }
}

// Track spares and strikes
bool Frame::isSpare(int roll1, int roll2) {
    return (roll1 + roll2) == 10;
}

bool Frame::isStrike(int roll1) {
    return roll1 == 10;
}
