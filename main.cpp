/*  David Croisant
    Bowling Scoring

    A system to produce bowling scores frame-by-frame
*/

#include <fstream>
#include <iostream>
#include <string>

// Global variables
const int MAX_ROLLS = 21;
int roll[MAX_ROLLS] = {0};
int score[10] = {0};
std::string frameScore = "";

int main() {
    // Get file from user
    std::string filename;
    std::cout << "Enter bowler file: " << std::endl;
    std::cin >> filename;

    // Open file and check that it opened successfully
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error reading file: " << filename << std::endl;
    }

    // Iterate through Frames 1-9
    for (int frame = 1; frame < 10; frame++) {
        // Frame variables
        int frameRoll1 = (frame - 1) * 2;
        int frameRoll2 = frameRoll1 + 1;

        // Input each file line to the first roll for this frame
        file >> roll[frameRoll1];

        // If the first roll is not a strike, roll again
        if (roll[frameRoll1] < 10) {
            file >> roll[frameRoll2];
        }

        // Output Frame data
        // std::cout << frameRoll1 << " " << frameRoll2 << std::endl;
        std::cout << roll[frameRoll1] << " " << roll[frameRoll2] << std::endl;
    }

    // Close user's file
    file.close();

    return 0;
}
