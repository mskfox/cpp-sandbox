#include <limits>
#include <vector>

class Solution {
public:
	static double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
		int m = nums1.size();
		int n = nums2.size();

		if (m > n) { std::swap(nums1, nums2); std::swap(m, n); }

		int left = 0;
		int right = m;

		int half_len = (m + n + 1) / 2;

		while (left <= right) {
			int mid_a = (left + right) / 2;
			int mid_b = half_len - mid_a;

			int left_a = mid_a == 0 ? std::numeric_limits<int>::min() : nums1[mid_a - 1];
			int right_a = mid_a == m ? std::numeric_limits<int>::max() : nums1[mid_a];
			int left_b = mid_b == 0 ? std::numeric_limits<int>::min() : nums2[mid_b - 1];
			int right_b = mid_b == n ? std::numeric_limits<int>::max() : nums2[mid_b];

			if (left_a <= right_b && left_b <= right_a) {
				if ((m + n) % 2 == 0) {
					return (std::max(left_a, left_b) + std::min(right_a, right_b)) / 2.0;
				}
				return std::max(left_a, left_b);
			}

			if (left_a > right_b) { right = mid_a - 1; }
			else { left = mid_a + 1; }
		}

		return 0;
	}
};
