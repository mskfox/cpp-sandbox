// Puzzle: https://www.codingame.com/ide/puzzle/defibrillators

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

// the radius of the Earth (km)
constexpr double EARTH_RADIUS = 6371;

/**
 * @brief Converts degrees to radians.
 *
 * @param degree The angle in degrees.
 * @return The angle in radians.
 */
double degree_to_radian(const double degree) { return degree * M_PI / 180; }

/**
 * @brief Calculates the distance between two points on the Earth.
 *
 * @param lon_a The longitude of the first point.
 * @param lat_a The latitude of the first point.
 * @param lon_b The longitude of the second point.
 * @param lat_b The latitude of the second point.
 * @return The distance between the two points in kilometers.
 */
double calculate_distance(const double lon_a, const double lat_a, const double lon_b, const double lat_b) {
	const double x = (lon_b - lon_a) * std::cos((lat_a + lat_b) / 2);
	const double y = lat_b - lat_a;
	return std::sqrt(x * x + y * y) * EARTH_RADIUS;
}

/**
 * @brief The program reads the longitude and latitude of a point and prints the
 * closest defibrillator.
 */
int main() {
	std::string lon_str, lat_str;
	std::cin >> lon_str >> lat_str;

	std::replace(lon_str.begin(), lon_str.end(), ',', '.');
	std::replace(lat_str.begin(), lat_str.end(), ',', '.');

	double lon = std::stod(lon_str);
	double lat = std::stod(lat_str);

	lon = degree_to_radian(lon);
	lat = degree_to_radian(lat);

	int n;
	std::cin >> n;
	std::cin.ignore();

	std::string closest_defibrillator;
	double min_distance = std::numeric_limits<double>::max();

	for (int i = 0; i < n; i++) {
		std::string defibrillator;
		std::getline(std::cin, defibrillator);

		std::stringstream ss(defibrillator);
		std::string id, name, address, phone, lon_defibrillator_str, lat_defibrillator_str;

		std::getline(ss, id, ';');
		std::getline(ss, name, ';');
		std::getline(ss, address, ';');
		std::getline(ss, phone, ';');
		std::getline(ss, lon_defibrillator_str, ';');
		std::getline(ss, lat_defibrillator_str, ';');

		std::replace(lon_defibrillator_str.begin(), lon_defibrillator_str.end(), ',', '.');
		std::replace(lat_defibrillator_str.begin(), lat_defibrillator_str.end(), ',', '.');

		double lon_defibrillator = degree_to_radian(std::stod(lon_defibrillator_str));
		double lat_defibrillator = degree_to_radian(std::stod(lat_defibrillator_str));

		double distance = calculate_distance(lon, lat, lon_defibrillator, lat_defibrillator);
		if (distance < min_distance) {
			min_distance = distance;
			closest_defibrillator = name;
		}
	}

	std::cout << closest_defibrillator << std::endl;

	return 0;
}
