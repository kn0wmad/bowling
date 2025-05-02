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

        // Constructor declaration and inititialization
        Frame(int f = 0, int r1 = 0, int r2 = 0, int s = 0) : frame(f), roll1(r1), roll2(r2), score(s) {}

        // Class method prototypes
        int calcScore(int *roll1, int *roll2, int *nextRoll1, int *nextRoll2);
        void printScore(int frame, int roll1, int roll2, int frameScore);
};

#endif
