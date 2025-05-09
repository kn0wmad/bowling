#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <string>

// Frame class
class Frame {
    public:
        int frame;
        int roll1;
        int roll2;
        int bonus;

        // Constructor declaration and inititialization
        Frame(int f = 0, int r1 = 0, int r2 = 0, int b = 0) : frame(f), roll1(r1), roll2(r2), bonus(b) {}

        // Class method prototypes
        std::string Score(int roll1, int roll2, int &bonus);
        bool isSpare(int roll1, int roll2);
        bool isStrike(int roll1);
};
#endif
