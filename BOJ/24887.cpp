#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

// 1  5  2  8  4  7  2  9  8  2  8
// 1  5  5  8  8 12 12 17 17 17 20

// dp[k] = max(dp[k-1], dp[k-T]+arr[k])
// (T = gap + 1)

void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> v(N + 1);
  ll sum = 0;
  for (int i = 1;i <= N;i++) {
    cin >> v[i];
    sum += v[i];
    if (v[i] >= M) {
      cout << "Free!";
      return;
    }
  }
  if (sum < M) {
    cout << -1;
    return;
  }

  int s = 0, e = N;
  while (s < e) {
    int m = ( s + e ) / 2;

    int T = m + 1;
    vector<ll> dp(N + 1);
    for (int i = 1;i <= N;i++) {
      dp[i] = v[i];
      if (i >= T)
        dp[i] += dp[i - T];
      dp[i] = max(dp[i], dp[i - 1]);
    }
    if (dp[N] >= M)
      s = m + 1;
    else
      e = m;
  }
  cout << s - 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
