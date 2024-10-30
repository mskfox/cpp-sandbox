#include <limits>

constexpr int INT_MAX_DIV_10 = std::numeric_limits<int>::max() / 10;
constexpr int INT_MIN_DIV_10 = std::numeric_limits<int>::min() / 10;

class Solution {
public:
	static int reverse(int x) {
		int reversed = 0;
		while (x != 0) {
			if (reversed > INT_MAX_DIV_10 || reversed < INT_MIN_DIV_10) {
				return 0;
			}

			const int pop = x % 10;
			reversed = reversed * 10 + pop;
			x /= 10;
		}
		return reversed;
	}
};
