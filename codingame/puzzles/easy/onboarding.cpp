// Puzzle: https://www.codingame.com/ide/puzzle/onboarding

#include <iostream>
#include <string>

/**
 * @brief The program reads the distance to two enemies and prints the name of
 * the closest one.
 */
[[noreturn]] int main() {
    std::string enemy1, enemy2;
    int dist1, dist2;

    while (true) {
        std::cin >> enemy1 >> dist1 >> enemy2 >> dist2;

        if (dist1 < dist2) {
            std::cout << enemy1 << std::endl;
        } else {
            std::cout << enemy2 << std::endl;
        }
    }
}