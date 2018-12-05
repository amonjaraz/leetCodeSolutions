#include "vector"
#include "iostream"
//Two Sum
static class Solution1 {
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> indexes = {};
		for (int i = 0; i<nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i != j) {
					if ((nums[i] + nums[j]) == target) {
						indexes.push_back(i);
						indexes.push_back(j);
						return indexes;
					}
				}
			}
		}
		return indexes;
	}

	static void solveProblem() {
		std::vector<int> nums = { 2, 7, 11, 15 };
		std::vector<int> indexes = {};
		int target = 9;

		indexes = twoSum(nums, target);
		std::cout << "Solution 1" << "\n";
		std::cout << "Indexes Found:" << "\n";
		for (int i = 0; i < indexes.size(); i++) {
			std::cout << indexes[i] << "\n";
		}
	}
};