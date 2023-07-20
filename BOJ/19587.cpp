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

int sz = 3;

vector<vector<ll>> matProd(vector<vector<ll>>& m1, vector<vector<ll>>& m2) {
  vector<vector<ll>> res(sz, vector<ll>(sz));
  for (int i = 0;i < sz;i++)
    for (int j = 0;j < sz;j++)
      for (int k = 0;k < sz;k++)
        res[i][j] = ( res[i][j] + m1[i][k] * m2[k][j] ) % MOD;
  return res;
}

vector<vector<ll>> matPow(vector<vector<ll>>& m, ll n) {
  vector<vector<ll>> res(sz, vector<ll>(sz));
  for (int i = 0;i < sz;i++)
    res[i][i] = 1;
  while (n) {
    if (n & 1) {
      res = matProd(res, m);
      n--;
    }
    else {
      m = matProd(m, m);
      n >>= 1;
    }
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> m = {
    {1,1,1},
    {1,0,1},
    {1,1,0}
  };

  m = matPow(m, n);

  ll ans = 0;
  for (ll& i : m[0])
    ans = ( ans + i ) % MOD;
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
