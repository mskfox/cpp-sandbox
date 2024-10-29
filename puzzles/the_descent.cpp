// Puzzle: https://www.codingame.com/ide/puzzle/the-descent

#include <iostream>

/**
 * @brief The program reads the height of 8 mountains and prints the index of
 * the highest mountain.
 */
[[noreturn]] int main() {
	while (true) {
		int highest_mountain_index = 0;
		int highest_mountain_height = 0;

		for (int i = 0; i < 8; i++) {
			int mountain_height;
			std::cin >> mountain_height;
			std::cin.ignore();

			if (mountain_height > highest_mountain_height) {
				highest_mountain_index = i;
				highest_mountain_height = mountain_height;
			}
		}

		std::cout << highest_mountain_index << std::endl;
	}
}