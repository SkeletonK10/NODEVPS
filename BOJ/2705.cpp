//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int dp[1001];

void preprocess() {
  for (int i = 1;i <= 1000;i++) {
    for (int j = 0;j <= i;j += 2)
      dp[i] += dp[( i - j ) / 2];
    dp[i]++;
  }
}

int solve(int n) {
  return dp[n];
}

int main() {
  FastIO;
  preprocess();
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    int N;
    cin >> N;
    cout << solve(N) << endl;
  }
}
