#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1234567;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

vector<vector<int>> adj = {
  {7},
  {2,4},
  {1,3,5},
  {2,6},
  {1,5,7},
  {2,4,6,8},
  {3,5,9},
  {4,8,0},
  {5,7,9},
  {6,8}
};

int dp[1001][10];

void dpProcess() {
  for (int i = 0;i < 10;i++)
    dp[1][i] = 1;
  for (int i = 2;i <= 1000;i++)
    for (int j = 0;j < 10;j++)
      for (int a : adj[j])
        dp[i][j] = ( dp[i][j] + dp[i - 1][a] ) % MOD;
}

void solve() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0;i < 10;i++)
    ans += dp[N][i];
  cout << ans % MOD << endl;
}

int main() {
  FastIO;
  dpProcess();
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
