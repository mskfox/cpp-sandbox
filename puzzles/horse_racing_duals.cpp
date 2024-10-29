// Puzzle: https://www.codingame.com/training/easy/horse-racing-duals

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief The program reads the power of horses and calculates the minimum
 * difference between the power of two horses.
 */
int main() {
	int n;
	std::cin >> n;

	std::vector<int> powers(n);
	for (int i = 0; i < n; i++) {
		std::cin >> powers[i];
	}

	std::sort(powers.begin(), powers.end());

	int min_delta = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		const int delta = powers[i] - powers[i - 1];
		if (delta < min_delta) {
			min_delta = delta;
		}
	}

	std::cout << min_delta << std::endl;

	return 0;
}