// Puzzle: https://www.codingame.com/ide/puzzle/temperatures

#include <iostream>
#include <limits>
#include <sstream>

/**
 * @brief Find the temperature closest to zero.
 *
 * @details Given a list of temperatures, find the temperature closest to zero.
 * If two numbers are equally close to zero, consider the positive number as
 * closest to zero. The list of temperatures is a string of space-separated
 * integers.
 *
 * @param temperatures A string of space-separated integers.
 * @return The temperature closest to zero.
 */
int find_closest_to_zero(const std::string& temperatures) {
	std::istringstream iss(temperatures);

	int closest_to_zero = std::numeric_limits<int>::max();
	int temperature;

	while (iss >> temperature) {
		const bool is_abs_smaller = abs(temperature) < abs(closest_to_zero);
		const bool is_abs_equal = abs(temperature) == abs(closest_to_zero);
		const bool is_positive = temperature > 0;

		if (is_abs_smaller || (is_abs_equal && is_positive)) {
			closest_to_zero = temperature;
		}
	}

	return closest_to_zero;
}

/**
 * @brief The program reads a list of temperatures between -273 and 5526 then
 * prints the temperature closest to zero.
 */
int main() {
	int n;
	std::cin >> n;
	std::cin.ignore();

	if (n == 0) {
		std::cout << "0" << std::endl;
		return 0;
	}

	std::string temperatures;
	std::getline(std::cin, temperatures);

	const int closest_to_zero = find_closest_to_zero(temperatures);
	std::cout << closest_to_zero << std::endl;

	return 0;
}