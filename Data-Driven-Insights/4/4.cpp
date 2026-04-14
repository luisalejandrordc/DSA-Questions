#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int sol1(vector<int> &nums) { return 0; }
};

int main() {
  cout << "QUESTION 4" << endl;
  vector<int> nums = {4, 5, 6, 7, 1, 2, 3};
  int sol1 = Solution().sol1(nums);
  cout << "Solution 1: " << sol1 << endl;
  return 0;
}
