#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 9;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

ll power(ll a, int n) {
  ll res = 1;
  while (n) {
    if (n & 1) {
      res = ( a * res ) % MOD;
      n--;
    }
    else {
      a = ( a * a ) % MOD;
      n /= 2;
    }
  }
  return res;
}

ll comb(int n, int r) {
  ll factN = 1, factR = 1;
  for (int i = 1; i <= n; i++)
    factN = ( factN * i ) % MOD;
  for (int i = 1; i <= r; i++)
    factR = ( factR * i ) % MOD;
  for (int i = 1; i <= ( n - r ); i++)
    factR = ( factR * i ) % MOD;
  factR = power(factR, MOD - 2);
  return ( factN * factR ) % MOD;
}

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    int factor = 2;
    while (temp > 1) {
      if (temp % factor == 0) {
        mp[factor]++;
        temp /= factor;
      }
      else
        factor++;

      if (factor * factor > temp)
        break;
    }
    if (temp > 1)
      mp[temp]++;
  }
  ll ans = 1;
  for (pii i : mp) {
    ans *= comb(n + i.SS - 1, i.SS);
    ans %= MOD;
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
