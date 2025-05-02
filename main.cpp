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
    Frame gameFrames[TOTAL_FRAMES];

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        gameFrames[i].frame = 1;
        gameFrames[i].roll1 = 0;
        gameFrames[i].roll2 = 0;
        gameFrames[i].score = 0;

        gameFrames[i].calcScore();
        gameFrames[i].printScore();
    }

    return 0;
}
