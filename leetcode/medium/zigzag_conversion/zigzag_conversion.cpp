#include <string>
#include <vector>

class Solution {
public:
	static std::string convert(const std::string &s, const int num_rows) {
		if (num_rows == 1) { return s; }

		std::vector<std::string> rows(num_rows);

		int current_row = 0;
		bool going_down = false;

		for (const char c : s) {
			rows[current_row] += c;
			if (current_row == 0 || current_row == num_rows - 1) { going_down = !going_down; }
			current_row += going_down ? 1 : -1;
		}

		std::string result;
		for (const std::string &row : rows) { result += row; }

		return result;
	}
};
