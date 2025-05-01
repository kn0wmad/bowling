/*  David Croisant
    Bowling Scoring

    A system to produce bowling scores frame-by-frame
*/

#include <iostream>

// Function prototypes
void displayScoreTable(int frame, int roll1, int roll2, int score);

int main()
{
    // Variables
    const int MAX_ROLLS = 21;
    int frame;
    int roll[MAX_ROLLS] = {0};
    int score[10] = {0};

    // Iterate through frames
    for (frame = 1; frame <= 10; frame++){
        int frameRoll1 = (frame - 1) * 2;
        int frameRoll2 = frameRoll1 + 1;
        int totalScore;

        // Iterate through 1 or 2 rolls, depending on outcome, to get score for frame
            std::cin >> roll[frameRoll1];
            if (roll[frameRoll1] < 10) {
                std::cin >> roll[frameRoll2];
            } else if ((roll[frameRoll1] > 10) || (roll[frameRoll1] < 0)) { // Handle bad user input
                std::cout << "Invalid input, must be between 0 and 10 pins" << std::endl;
                break;
            } else {
                roll[frameRoll2] = 0;
            }

            if (roll[frameRoll1] + roll[frameRoll2] > 10) { // Handle bad user input
                std::cout << "Invalid input, must be 10 pins or less" << std::endl;
                break;
            }

            // Update the score
            score[frame] = (roll[frameRoll1] + roll[frameRoll2]);
            if (frame == 1) {
                totalScore = score[frame];
            } else {
                totalScore += score[frame];
            }

            // Output score table
            displayScoreTable(frame, roll[frameRoll1], roll[frameRoll2], totalScore);
    }

    return 0;
}

// Function definitions

// Print the table
void displayScoreTable(int frame, int roll1, int roll2, int totalScore) {
    std::cout << "Frame: " << frame << std::endl;
    std::cout << "Throw: " << roll1 << "  " << roll2 << std::endl;
    std::cout << "Score: " << totalScore << std::endl;
}
