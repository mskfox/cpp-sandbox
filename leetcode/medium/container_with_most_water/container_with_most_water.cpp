#include <vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int max_area = 0;

		int left = 0;
		int right = height.size() - 1;

		while (left < right) {
			int width = right - left;
			int min_height = std::min(height[left], height[right]);
			int area = width * min_height;

			max_area = std::max(max_area, area);

			if (height[left] < height[right]) {
				++left;
			} else {
				--right;
			}
		}

		return max_area;
	}
};