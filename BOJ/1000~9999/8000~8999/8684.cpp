#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 1987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve()
{
  int n, g;
  cin >> n >> g;
  vector<vector<ll>> dp(n + 1, vector<ll>(g + 1, LINF));
  for (int i = 0;i <= n;i++) dp[i][0] = 0;
  vector<pii> v(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> v[i].FF >> v[i].SS;
  for (int i = 1;i <= n;i++)
  {
    for (int j = 1;j <= g;j++)
    {
      if (j - v[i].FF >= 0)
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i].FF] + v[i].FF + v[i].SS);
      else
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][0] + j + v[i].SS);
    }
  }
  if (dp[n][g] == LINF) cout << "NIE" << endl;
  else cout << dp[n][g] << endl;
}

int main()
{
  FastIO;
	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
    solve();
  }
}