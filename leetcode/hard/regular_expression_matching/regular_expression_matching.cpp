#include <string>
#include <vector>

class Solution {
public:
	/**
     * @brief Determines if a string matches a given pattern
     * @param s The input string to match
     * @param p The pattern to match against
     * @return whether the string matches the pattern
     *
     * Pattern rules:
     * '.' Matches any single character
     * '*' Matches zero or more of the preceding element
     */
	bool isMatch(std::string s, std::string p) {
		int s_length = s.size();
		int p_length = p.size();

		// dp[i][j] represents if text[0..i-1] matches pattern[0..j-1]
		std::vector<std::vector<bool>> dp(s_length + 1, std::vector<bool>(p_length + 1, false));

		dp[0][0] = true;

		// handle patterns with leading wildcards (e.g., "a*", ".*")
		for (int j = 2; j <= p_length; ++j) {
			if (p[j - 1] == '*') {
				dp[0][j] = dp[0][j - 2];
			}
		}

		for (size_t i = 1; i <= s_length; ++i) {
            for (size_t j = 1; j <= p_length; ++j) {
                const char current_pattern = p[j - 1];
                const char current_text = s[i - 1];

                if (current_pattern == '.' || current_pattern == current_text) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
				else if (current_pattern == '*') {
                    const char preceding_pattern = p[j - 2];
                    const bool matches_zero = dp[i][j - 2];
                    const bool matches_more = dp[i - 1][j] &&
						(current_text == preceding_pattern || preceding_pattern == '.');

                    dp[i][j] = matches_zero || matches_more;
                }
            }
        }

		return dp[s_length][p_length];
	}
};