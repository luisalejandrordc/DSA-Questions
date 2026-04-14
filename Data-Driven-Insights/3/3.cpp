#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addToQueue(queue<int> &queue, int x) {
  if (queue.size() == 2)
    queue.pop();
  queue.push(x);
}

class Solution {
public:
  // Time complexity: O((m + n) / 2)
  double sol1(vector<int> &nums1, vector<int> &nums2) {
    queue<int> mediums;
    int m = nums1.size(), n = nums2.size();
    int limit = (m + n) / 2;
    int idx1 = 0, idx2 = 0;

    while (idx1 < nums1.size() && idx2 < nums2.size() && idx1 + idx2 <= limit) {
      if (nums1[idx1] <= nums2[idx2])
        addToQueue(mediums, nums1[idx1++]);
      else
        addToQueue(mediums, nums2[idx2++]);
    }
    while (idx1 < nums1.size() && idx1 + idx2 <= limit)
      addToQueue(mediums, nums1[idx1++]);
    while (idx2 < nums2.size() && idx1 + idx2 <= limit)
      addToQueue(mediums, nums2[idx2++]);

    return (m + n) % 2 == 0 ? (mediums.front() + mediums.back()) / 2.0
                            : mediums.back();
  }

  // Time complexity: O(log(min(m, n)))
  double sol2(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      return sol2(nums2, nums1);
    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;
    int half = (m + n) / 2;
    while (left <= right) {
      int i = (left + right) / 2;
      int j = half - i;
      int maxLeft1 = i - 1 < 0 ? INT_MIN : nums1[i - 1];
      int maxLeft2 = j - 1 < 0 ? INT_MIN : nums2[j - 1];
      int minRight1 = i == m ? INT_MAX : nums1[i];
      int minRight2 = j == n ? INT_MAX : nums2[j];
      if (minRight1 >= maxLeft2 && minRight2 >= maxLeft1)
        return (m + n) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
                   : min(minRight1, minRight2);
      if (minRight1 < maxLeft2)
        left = i + 1;
      else
        right = i - 1;
    }
    return 0.0;
  }
};

int main() {
  cout << "QUESTION 3" << endl;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  double sol1 = Solution().sol1(nums1, nums2);
  cout << "Solution 1: " << sol1 << endl;
  double sol2 = Solution().sol2(nums1, nums2);
  cout << "Solution 2: " << sol2 << endl;

  return 0;
}
