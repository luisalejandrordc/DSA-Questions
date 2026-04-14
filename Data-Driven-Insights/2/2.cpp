#include <iostream>
#include <string>
#include <vector>

using namespace std;

string arrayToString(vector<int> &nums) {
  string s = "[";
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    s += to_string(nums[i]);
    if (i != len - 1)
      s += ", ";
  }
  s += "]";
  return s;
}

class Solution {
public:
  // Time complexity: O(n^2)
  vector<int> sol1(vector<int> &nums) {
    vector<int> ans;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int x = 1;
      for (int j = 0; j < len; j++)
        if (i != j)
          x *= nums[j];
      ans.push_back(x);
    }
    return ans;
  }

  // Time complexity: O(n)
  vector<int> sol2(vector<int> &nums) {
    vector<int> ans;
    int len = nums.size();
    int preffix = 1;
    for (int i = 0; i < len; i++) {
      ans.push_back(preffix);
      preffix *= nums[i];
    }
    int suffix = 1;
    for (int i = len - 1; i >= 0; i--) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }
    return ans;
  }
};

int main() {
  cout << "QUESTION 2" << endl;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> sol1 = Solution().sol1(nums);
  cout << "Solution 1: " << arrayToString(sol1) << endl;
  vector<int> sol2 = Solution().sol2(nums);
  cout << "Solution 2: " << arrayToString(sol2) << endl;
  return 0;
}
