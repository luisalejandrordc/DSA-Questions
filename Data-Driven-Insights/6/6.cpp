#include <iostream>
#include <vector>

using namespace std;

// Brute-Force Method (Time Complexity O(n^2 / 2))
// int maxProfit(const vector<int> &prices) {
//   int maxPro = 0;
//   for (int i = 0; i < prices.size() - 1; i++)
//     for (int j = i + 1; j < prices.size(); j++)
//       maxPro = max(maxPro, prices[j] - prices[i]);
//   return maxPro;
// }

// Clever Method (Time Complexity O(n))
int maxProfit(const vector<int> &prices) {
  int p = 0;
  int maxPro = 0;
  for (int i = 1; i < prices.size(); i++) {
    int pro = prices[i] - prices[p];
    if (pro < 0)
      p = i;
    else
      maxPro = max(maxPro, pro);
  }
  return maxPro;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << "Solution: " << maxProfit(prices) << endl;
  return 0;
}
