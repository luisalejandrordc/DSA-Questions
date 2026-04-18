#include <iostream>
#include <vector>

using namespace std;

// int maxSubarray(const vector<int> &nums) {
//   int current_sum = nums[0];
//   int max_sum = nums[0];
//   for (int i = 1; i < nums.size(); i++) {
//     current_sum = max(nums[i], current_sum + nums[i]);
//     max_sum = max(max_sum, current_sum);
//   }
//   return max_sum;
// }

int maxSubarray(const vector<int> &nums) {
  int curSum = nums[0];
  int maxSum = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    curSum = curSum > 0 ? curSum + nums[i] : nums[i];
    maxSum = max(maxSum, curSum);
  }
  return maxSum;
}

int main() {
  cout << "Solution: " << maxSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 1}) << endl;
  return 0;
}
