// Puzzle: https://www.codingame.com/ide/puzzle/six-degrees-of-kevin-bacon

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief Calculates the Bacon number for a given actor.
 *
 * The Bacon number is the number of degrees of separation an actor has from
 * Kevin Bacon, based on the movies they have appeared in together.
 *
 * @param actor_name Name of the actor whose Bacon number is to be calculated.
 * @param movie_casts Vector of strings, where each string represents a movie.
 * @return The Bacon number of the actor, or -1 if the actor is not connected to
 * Kevin Bacon.
 */
int calculate_bacon_number(const std::string& actor_name, const std::vector<std::string>& movie_casts) {
	std::unordered_map<std::string, std::unordered_set<std::string>> graph;

	// build the graph of actors
	for (const std::string& movie_cast : movie_casts) {
		size_t colon_pos = movie_cast.find(':');
		std::string actors_str = movie_cast.substr(colon_pos + 1);

		std::istringstream iss(actors_str);
		std::vector<std::string> actors;

		std::string actor;
		while (std::getline(iss, actor, ',')) {
			// remove leading whitespace
			actor = actor.substr(1);
			actors.push_back(actor);
		}

		for (size_t i = 0; i < actors.size(); ++i) {
			for (size_t j = i + 1; j < actors.size(); ++j) {
				graph[actors[i]].insert(actors[j]);
				graph[actors[j]].insert(actors[i]);
			}
		}
	}

	std::queue<std::pair<std::string, int>> queue;
	std::unordered_set<std::string> visited;

	queue.emplace(actor_name, 0);
	visited.insert(actor_name);

	// perform Breadth-First Search to find the Bacon number
	while (!queue.empty()) {
		auto [current_actor, distance] = queue.front();
		queue.pop();

		if (current_actor == "Kevin Bacon") {
			return distance;
		}

		for (const std::string& neighbor : graph[current_actor]) {
			if (visited.find(neighbor) == visited.end()) {
				queue.emplace(neighbor, distance + 1);
				visited.insert(neighbor);
			}
		}
	}

	return -1;
}

/**
 * @brief The program reads the name of an actor and the list of movies and
 * it calculates the Bacon number of the actor.
 */
int main() {
	std::string actor_name;
	std::getline(std::cin, actor_name);

	int n;
	std::cin >> n;
	std::cin.ignore();

	std::vector<std::string> movie_casts(n);
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, movie_casts[i]);
	}

	std::cout << calculate_bacon_number(actor_name, movie_casts) << std::endl;
}