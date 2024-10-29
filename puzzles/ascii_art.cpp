// Puzzle: https://www.codingame.com/ide/puzzle/ascii-art

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief This program reads ASCII art representations of letters and prints the
 * ASCII art for a given input string.
 *
 * @details
 * The ASCII art for each letter is stored in a vector of strings.
 * Each character in the input string is mapped to its corresponding ASCII art
 * by calculating its index.
 * Non-alphabetic characters are mapped to the last element in the ASCII art
 * vector.
 */
int main() {
	int l, h;
	std::cin >> l >> h;
	std::cin.ignore();

	std::string t;
	std::getline(std::cin, t);
	std::transform(t.begin(), t.end(), t.begin(), ::toupper);

	std::vector<std::string> ascii_art(h);
	for (int i = 0; i < h; i++) {
		std::getline(std::cin, ascii_art[i]);
	}

	for (int i = 0; i < h; i++) {
		for (const char c : t) {
			int index;
			if (c >= 'A' && c <= 'Z') {
				index = c - 'A';
			} else {
				index = 26;
			}
			std::cout << ascii_art[i].substr(index * l, l);
		}
		std::cout << std::endl;
	}

	return 0;
}
