//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int fact[10];

void solve() {
  fact[0] = 1;
  for (int i = 1;i < 10;i++)
    fact[i] = fact[i - 1] * i;
  int N;
  cin >> N;
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  for (int i = 1;i <= N;i++) {
    for (int j = 1;fact[j] <= i;j++)
      dp[i] = min(dp[i], dp[i - fact[j]]);
    dp[i]++;
  }
  cout << dp[N];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
