// Puzzle: https://www.codingame.com/ide/puzzle/mime-type

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

/**
 * @brief The program reads a list of MIME types and file names, and outputs
 * the MIME type of each file.
 */
int main() {
	int n, q;
	std::cin >> n >> q;
	std::cin.ignore();

	std::unordered_map<std::string, std::string> mime_types;
	mime_types.reserve(n);

	std::string ext, mt;
	for (int i = 0; i < n; i++) {
		std::cin >> ext >> mt;
		std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
		mime_types[ext] = mt;
	}
	std::cin.ignore();

	std::string file_name;
	for (int i = 0; i < q; i++) {
		std::getline(std::cin, file_name);

		const size_t pos = file_name.rfind('.');
		if (pos == std::string::npos) {
			std::cout << "UNKNOWN" << std::endl;
			continue;
		}

		std::string extension = file_name.substr(pos + 1);
		std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

		auto it = mime_types.find(extension);
		if (it != mime_types.end()) {
			std::cout << it->second << std::endl;
		} else {
			std::cout << "UNKNOWN" << std::endl;
		}
	}

	return 0;
}