#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <string>

// Frame class
class Frame {
    public:
        int roll1;
        int roll2;

        // Constructor declaration and inititialization
        Frame(int r1 = 0, int r2 = 0) : roll1(r1), roll2(r2) {}

        // Class method prototypes
        bool isSpare();
        bool isStrike();
        std::string Score(int roll1, int roll2);
};
#endif
