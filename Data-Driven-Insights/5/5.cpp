#include <iostream>

using namespace std;

int maxSubArray(const vector<int> &nums) {
  int current_sum = nums[0];
  int max_sum = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    current_sum = max(nums[i], current_sum + nums[i]);
    max_sum = max(max_sum, current_sum);
  }

  return max_sum;
}

int main() {
  cout << maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 1});
  return 0;
}
