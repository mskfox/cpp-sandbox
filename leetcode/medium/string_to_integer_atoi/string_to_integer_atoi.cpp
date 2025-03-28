#include <climits>
#include <string>

class Solution {
public:
	int myAtoi(std::string s) {
		int index = 0;

		const int length = s.size();

		int sign = 1;
		int result = 0;

		while (index < length && s[index] == ' ') {
			++index;
		}

		if (index < length && (s[index] == '+' || s[index] == '-')) {
			sign = (s[index] == '-') ? -1 : 1;
			++index;
		}

		while (index < length && s[index] == '0') {
            ++index;
        }

		while (index < length && std::isdigit(s[index])) {
			int digit = s[index] - '0';

			if (result > (std::numeric_limits<int>::max() - digit) / 10) {
				return (sign == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
			}

			result = result * 10 + digit;
			++index;
		}

		return result * sign;
	}
};