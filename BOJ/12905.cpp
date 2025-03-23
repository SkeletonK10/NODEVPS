#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int dp[51][2];  // 0: honest, 1: liar

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += s[0];
	fill(&dp[0][0], &dp[0][0] + ( 51 * 2 ), INF);
	dp[0][0] = 0; // honest first
	for (int i = 1;i <= n;i++) {
		if (s[i - 1] == 'L') {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else if (s[i - 1] == 'H') {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else {
			dp[i][0] = min({ dp[i - 1][0], dp[i - 1][1] });
			dp[i][1] = dp[i][0] + 1;
		}
	}
	int ans = dp[n][0];

	fill(&dp[0][0], &dp[0][0] + ( 51 * 2 ), INF);
	dp[0][1] = 1;
	for (int i = 1;i <= n;i++) {
		if (s[i - 1] == 'L') {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else if (s[i - 1] == 'H') {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else {
			dp[i][0] = min({ dp[i - 1][0], dp[i - 1][1] });
			dp[i][1] = dp[i][0] + 1;
		}
	}
	ans = min(ans, dp[n][1] - 1);    // first liar is double counted
	cout << ( ans >= INF ? -1 : ans );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
