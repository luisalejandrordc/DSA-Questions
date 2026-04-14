#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // Binary Search in a Rotated Sorted Array
  int sol1(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int i = (left + right) / 2;
      if (nums[i] == target)
        return i;
      if (target > nums[i]) {
        if (target > nums[right])
          right = i - 1;
        else
          left = i + 1;
      } else {
        if (target < nums[left]) {
          left = i + 1;
        } else
          right = i - 1;
      }
    }
    return -1;
  }
};

int main() {
  cout << "QUESTION 4" << endl;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int sol1 = Solution().sol1(nums, 0);
  cout << "Solution 1: " << sol1 << endl;
  return 0;
}
