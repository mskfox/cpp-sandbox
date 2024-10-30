#include <string>

class Solution {
public:
	static std::string longestPalindrome(const std::string& s) {
		std::string result;

		for (int i = 0; i < s.size(); i++) {
			const std::string &odd = expand(i, i, s);
			if (odd.size() > result.size()) {
				result = odd;
			}

			const std::string &even = expand(i, i + 1, s);
			if (even.size() > result.size()) {
				result = even;
			}
		}

		return result;
	}

	static std::string expand(const int i, const int j, const std::string &s) {
		int left = i, right = j;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
		}
		return s.substr(left + 1, right - left - 1);
	}
};
