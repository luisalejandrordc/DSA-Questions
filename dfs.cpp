// Leetcode Problem 980: Unique Paths III

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Constants
const int DIRECTIONS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int OBSTACLE = -1;
const int EMPTY = 0;
const int START = 1;
const int END = 2;

pair<int, int> findStart(vector<vector<int>> &grid, pair<int, int> &size) {
  for (int i = 0; i < size.first; i++)
    for (int j = 0; j < size.second; j++)
      if (grid[i][j] == START)
        return {i, j};
  return {-1, -1};
}

int countEmptyCells(vector<vector<int>> &grid, pair<int, int> &size) {
  int rem = 0;
  for (int i = 0; i < size.first; i++)
    for (int j = 0; j < size.second; j++)
      if (grid[i][j] == EMPTY)
        rem++;
  return rem;
}

// dfs -> Depth First Search
void dfs(vector<vector<int>> &grid, pair<int, int> &size, pair<int, int> cell,
         int rem, int &cnt) {
  for (int k = 0; k < 4; k++) {
    int row = cell.first + DIRECTIONS[k][0];
    int col = cell.second + DIRECTIONS[k][1];
    if ((row >= 0 && row < size.first) && (col >= 0 && col < size.second)) {
      if (grid[row][col] == START || grid[row][col] == OBSTACLE)
        continue;
      if (grid[row][col] == END && rem == 0)
        cnt++;
      if (grid[row][col] == EMPTY) {
        grid[row][col] = -1;
        dfs(grid, size, {row, col}, rem - 1, cnt);
        grid[row][col] = 0;
      }
    }
  }
}

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    pair<int, int> size = {grid.size(), grid[0].size()};
    pair<int, int> cell = findStart(grid, size);
    int rem = countEmptyCells(grid, size);
    int cnt = 0;
    dfs(grid, size, cell, rem, cnt);
    return cnt;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
  cout << "Solution: " << Solution().uniquePathsIII(grid) << endl;
  return 0;
}
