#include <algorithm>
#include <string>

class Solution {
public:
	static int lengthOfLongestSubstring(std::string s) {
		if (s.empty()) { return 0; }

		int char_index[128];
		int max_length = 0;
		int start = 0;

		for (int end = 0; end < s.size(); end++) {
			const char current_char = s.at(end);
			start = std::max(char_index[current_char], start);
			max_length = std::max(max_length, end - start + 1);
			char_index[current_char] = end + 1;
		}

		return max_length;
	}
};
