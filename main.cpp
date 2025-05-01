/*  David Croisant
    Bowling Scoring

    A system to produce bowling scores frame-by-frame
*/

#include <iostream>
#include <string>

// Global variables
const int MAX_ROLLS = 21;
int roll[MAX_ROLLS] = {0};
int score[10] = {0};

// Function prototypes
std::string calcFrameScore(int frame, int *roll1, int *roll2);
void displayScoreTable(int frame, int roll1, int roll2, std::string currentScore);

int main()
{
    // Iterate through frames
    for (int frame = 1; frame <= 10; frame++){
        int frameRoll1 = (frame - 1) * 2;
        int frameRoll2 = frameRoll1 + 1;
        std::string currentScore;

        // Iterate through 1 or 2 rolls, depending on outcome, to get score for frame
            std::cin >> roll[frameRoll1];
            if (roll[frameRoll1] < 10) {
                std::cin >> roll[frameRoll2];
            } else if ((roll[frameRoll1] > 10) || (roll[frameRoll1] < 0)) {     // Handle bad user input
                std::cout << "Invalid input, must be between 0 and 10 pins" << std::endl;
                break;
            }

            // Handle bad user input
            if (roll[frameRoll1] + roll[frameRoll2] > 10) {
                std::cout << "Invalid input, must be 10 pins or less" << std::endl;
                break;
            }

            // Get the frame score and store it in score[] array
            int totalScore = 0;
            currentScore = calcFrameScore(frame, &roll[frameRoll1], &roll[frameRoll2]);

            // if (currentScore == "X" || "/") {
            //     score[frame - 1] = 10;
            // } else if (currentScore == "0" || "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9") {
            //     score[frame - 1] = std::stoi(currentScore);
            // }

            totalScore += score[frame - 1];

            if (currentScore != "X" || "/") {
                currentScore = std::to_string(totalScore);
            }

            // Output score table
            displayScoreTable(frame, roll[frameRoll1], roll[frameRoll2], currentScore);
    }

    return 0;
}

// Function definitions

// Get the score for each frame, return as string to account for strikes ("X"), and spares ("/")
std::string calcFrameScore(int frame, int *roll1, int *roll2) {
    std::string frameScore = "";
    if (frame < 10) {
        if (*roll1 == 10) {     // Handle Strikes
            frameScore = "X";
            score[frame - 1] = 10 + ((*roll1 + 2) + (*roll2 + 2));
        } else if (*roll1 + *roll2 == 10) {    // Handle Spares
            frameScore = "/";
            score[frame - 1] = 10 + (roll[*roll1 + 2]);
        } else {
            frameScore = std::to_string(*roll1 + *roll2);
            score[frame - 1] = roll[*roll1] + roll[*roll2];
        }
    }
    return frameScore;
}

// Print the table
void displayScoreTable(int frame, int  roll1, int roll2, std::string currentScore) {
    std::cout << "Frame: " << frame << std::endl;
    std::cout << "Throw: " << roll1 << "  " << roll2 << std::endl;
    std::cout << "Score: " << currentScore << std::endl;
}
