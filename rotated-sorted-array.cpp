
#include <iostream>
#include <utility>
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

pair<int, int> getPivot(vector<int> &nums) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int i = (left + right) / 2;
    if (i > 0 && nums[i] < nums[i - 1])
      return {i, nums[i]};
    if (nums[i] > nums[right])
      left = i + 1;
    else
      right = i - 1;
  }
  return {-1, -1};
}

int main() {
  cout << "ROTATED SORTED ARRAY" << endl;
  cout << "It is an array that was originally sorted in order but then\n"
          "shifted (rotated) at some pivot point, so the order wraps around"
       << endl;
  vector<int> nums = {4, 5, 6, 7, 1, 2, 3};
  cout << "Example: " << arrayToString(nums) << endl;
  pair<int, int> pivot = getPivot(nums);
  cout << "Pivot Index: " << pivot.first << endl;
  cout << "Pivot Element: " << pivot.second << endl;
  return 0;
}
