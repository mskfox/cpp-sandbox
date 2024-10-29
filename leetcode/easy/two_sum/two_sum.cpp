#include <unordered_map>
#include <vector>

class Solution {
public:
	static std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			if (int complement = target - nums[i]; map.find(complement) != map.end()) {
				return {map[complement], i};
			}
			map[nums[i]] = i;
		}
		return {};
	}
};
