// Puzzle: https://www.codingame.com/ide/puzzle/power-of-thor-episode-1

#include <iostream>
#include <string>

/**
 * @brief The program reads the position of Thor and the light and prints the
 * direction in which Thor should move.
 *
 * @details
 * Thor moves in 8 directions: N, NE, E, SE, S, SW, W, NW.
 * The goal is to reach the light.
 */
[[noreturn]] int main()
{
	int light_x, light_y, thor_x, thor_y;
    std::cin >> light_x >> light_y >> thor_x >> thor_y;
	std::cin.ignore();

    while (true) {
        int remaining_turns;
        std::cin >> remaining_turns;
		std::cin.ignore();

		std::string direction;

		if (thor_y < light_y) {
			direction += "S";
			thor_y++;
		} else if (thor_y > light_y) {
			direction += "N";
			thor_y--;
		}

		if (thor_x < light_x) {
			direction += "E";
			thor_x++;
		} else if (thor_x > light_x) {
			direction += "W";
			thor_x--;
		}

        std::cout << direction << std::endl;
    }
}