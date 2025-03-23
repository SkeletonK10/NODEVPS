#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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

void solve() {
  string s, temp, t;
  cin >> s >> temp;
  int sl = s.length(), tl = temp.length();
  ll ans = 0;
  set<string> st;
  for (int i = 0;i < tl;i++) {
    t = temp.substr(i) + temp.substr(0, i);
    if (st.find(t) != st.end()) continue;
    st.insert(t);
    vector<vector<ll>> dp(sl + 1, vector<ll>(tl + 1));
    for (int j = 0;j <= sl;j++)
      dp[j][0] = 1;
    for (int j = 1;j <= sl;j++) {
      for (int k = 1;k <= tl;k++) {
        dp[j][k] = dp[j - 1][k];
        if (t[k - 1] == s[j - 1])
          dp[j][k] += dp[j - 1][k - 1];
        dp[j][k] %= MOD;
        // cout << dp[j][k] << ' ';
      }
      // cout << endl;
    }
    ans = ( ans + dp[sl][tl] ) % MOD;
  }
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
