#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1000;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

vector<vector<int>> matPlus(vector<vector<int>> m1, vector<vector<int>> m2, int sz) {
  for (int i = 0;i < sz;i++)
    for (int j = 0;j < sz;j++)
      m1[i][j] = ( m1[i][j] + m2[i][j] ) % MOD;
  return m1;
}

vector<vector<int>> matProd(vector<vector<int>>& m1, vector<vector<int>>& m2, int sz) {
  vector<vector<int>> res(sz, vector<int>(sz));
  for (int i = 0;i < sz;i++)
    for (int j = 0;j < sz;j++)
      for (int k = 0;k < sz;k++)
        res[i][j] = ( res[i][j] + m1[i][k] * m2[k][j] ) % MOD;
  return res;
}

vector<vector<int>> matPow(vector<vector<int>> m, ll n, int sz) {
  vector<vector<int>> res(sz, vector<int>(sz));
  for (int i = 0;i < sz;i++)
    res[i][i] = 1;
  while (n) {
    if (n % 2) {
      res = matProd(res, m, sz);
      n--;
    }
    else {
      m = matProd(m, m, sz);
      n >>= 1;
    }
  }
  return res;
}

vector<vector<int>> dnq(vector<vector<int>>& m, ll n, int sz) {
  vector<vector<int>> res(sz, vector<int>(sz));
  if (n == 1)
    return m;
  res = dnq(m, n / 2, sz);
  vector<vector<int>> m1 = matPow(m, n / 2, sz);
  for (int i = 0;i < sz;i++)
    m1[i][i] = ( m1[i][i] + 1 ) % MOD;
  res = matProd(res, m1, sz);
  if (n % 2)
    res = matPlus(res, matPow(m, n, sz), sz);
  return res;
}

void solve() {
  int n;
  ll b;
  cin >> n >> b;
  vector<vector<int>> m(n, vector<int>(n));
  for (auto& v : m) {
    for (auto& i : v) {
      cin >> i;
      i %= MOD;
    }
  }

  vector<vector<int>> res = dnq(m, b, n);
  for (auto& v : res) {
    for (auto& i : v)
      cout << i << ' ';
    cout << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
