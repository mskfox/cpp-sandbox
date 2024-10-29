// Puzzle: https://www.codingame.com/ide/puzzle/mars-lander-episode-1

#include <iostream>
#include <cmath>

// the gravitational acceleration on Mars (m/s^2)
constexpr double GRAVITY = 3.711;

/**
 * @brief Clamps a value between a minimum and maximum.
 *
 * If the value is less than the minimum, it returns the minimum. If the value
 * is greater than the maximum, it returns the maximum. Otherwise, it returns
 * the value.
 *
 * @param value The value to clamp.
 * @param min The minimum value.
 * @param max The maximum value.
 *
 * @return The clamped value.
 */
double clamp(const double value, const double min, const double max) {
	return std::max(min, std::min(value, max));
}

/**
 * @brief Calculates the required power to control the descent.
 *.
 * The function does not directly calculate the minimum power required to cancel
 * the acceleration, but rather provides a power level to control the descent
 * within the constraints of the lander's capabilities.
 *
 * @param net_acceleration The net acceleration of the Mars lander.
 *
 * @return The required power to control the descent (between 0 and 4).
 */
int calculate_required_power(const double net_acceleration) {
	return static_cast<int>(std::round(clamp(-net_acceleration / 10, 0, 4)));
}

/**
 * @brief The program reads the surface of Mars and controls the descent of the
 * Mars lander. The goal is to land the Mars lander safely on the surface.
 */
[[noreturn]] int main() {
	int surface_n;
	std::cin >> surface_n;
	for (int i = 0; i < surface_n; i++) {
		int land_x, land_y;
		std::cin >> land_x >> land_y;
	}

	while (true) {
		int x, y, x_velocity, y_velocity, fuel, rotate, power;
		std::cin >> x >> y >> x_velocity >> y_velocity >> fuel >> rotate >> power;

		const double net_acceleration = GRAVITY + y_velocity;
		const int required_power = calculate_required_power(net_acceleration);

		std::cout << "0 " << required_power << std::endl;
	}
}