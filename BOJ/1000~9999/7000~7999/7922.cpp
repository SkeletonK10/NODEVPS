#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 1200000;                 // < Digits of 100000! (assumed 1.05e6)
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

vector<ll> fact(100001), dgt(SZ);

void preprocess() {
  ll f = 1;
  for (int i = 1;i <= 100000;i++) {
    f = ( f * i ) % MOD;
    fact[i] = f;
  }
  f = 1;
  for (int i = 0;i < SZ;i++) {
    dgt[i] = f;
    f = ( f * 10 ) % MOD;
  }
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  reverse(all(s));
  int sz = s.size();
  ll mod1 = fact[n], mod2 = 0, bPos;
  for (int i = 0;i < sz;i++) {
    if (s[i] == 'b')
      bPos = i;
    else if (s[i] == 'a')
      continue;
    else {
      mod2 = ( mod2 + ( s[i] - '0' ) * dgt[i] ) % MOD;
    }
  }
  // cout << bPos << ' ' << mod1 << ' ' << mod2 << endl;
  for (int i = 0;i < 100;i++) {
    if (mod1 == ( mod2 + i * dgt[bPos] ) % MOD) {
      cout << i / 10 << ' ' << i % 10 << endl;
      break;
    }
  }
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  preprocess();
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
