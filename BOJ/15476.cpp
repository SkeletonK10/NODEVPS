//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int cntDistSum(int h, int w, vector<vector<int>>& field) {
  int res = 0;
  for (int i = 0;i < field.size();i++)
    for (int j = 0;j < field[i].size();j++)
      res += min(abs(i - h), abs(j - w)) * field[i][j];
  return res;
}

void solve() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> field(H, vector<int>(W));
  for (auto& v : field)
    for (auto& i : v)
      cin >> i;
  int ans = INF;
  for (int i = 0;i < H;i++)
    for (int j = 0;j < W;j++)
      ans = min(ans, cntDistSum(i, j, field));
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
