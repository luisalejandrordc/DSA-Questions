#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void printVector(vector<int> &nums) {
  int len = nums.size();
  cout << "[";
  for (int i = 0; i < len; i++) {
    cout << nums[i];
    if (i != len - 1)
      cout << "\t";
  }
  cout << "]" << endl;
}

void sortVector(vector<int> &nums) {
  int i = 0;
  while (i < nums.size() - 1) {
    if (nums[i] > nums[i + 1]) {
      int temp = nums[i];
      nums[i] = nums[i + 1];
      nums[i + 1] = temp;
      i--;
    } else
      i++;
  }
}

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> ans;
  unordered_set<int> set;
  int len = nums.size();
  sortVector(nums);
  for (int i = 0; i < len - 2; i++) {
    if (set.count(nums[i]))
      continue;
    set.insert(nums[i]);
    int l = i + 1, r = len - 1;
    while (l < r) {
      if (l == i)
        l++;
      else if (r == i)
        r--;
      else {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.push_back({nums[i], nums[l], nums[r]});
          l++;
        } else if (sum < 0)
          l++;
        else
          r--;
      }
    }
  }
  return ans;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = threeSum(nums);
  for (vector<int> v : ans)
    printVector(v);
  return 0;
}
