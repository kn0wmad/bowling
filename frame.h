#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <string>

// Frame class
class Frame {
    public:
        // Has a frame index, 2 rolls, and a total score for the frame
        int frame;
        int roll1;
        int roll2;
        int score;

        // Class method prototypes
        int calcScore(int roll1, int roll2);
        void printScore(int frame, int roll1, int roll2, int frameScore);
};

#endif
