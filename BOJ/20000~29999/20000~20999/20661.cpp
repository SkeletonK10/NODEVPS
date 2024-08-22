#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 1e7;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

bool isNotPrime[SZ + 1];
set<int> prime;

void preprocess() {
  for (int i = 2;i <= SZ;i++) {
    if (!isNotPrime[i]) {
      prime.insert(i);
      for (int j = 1;i * j <= SZ;j++) {
        isNotPrime[i * j] = true;
      }
    }
  }
}

int fMap(ll n, int p) {
  int s = 0;
  ll pt = p;
  while (n / pt) {
    s += n / pt;
    pt *= p;
  }
  return s;
}

void solve() {
  preprocess();
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  for (const int& p : prime) {
    if (fMap(b, p) + fMap(c - 1, p) > fMap(a - 1, p) + fMap(d, p)) {
      cout << "NE" << endl;
      return;
    }
  }
  cout << "DA" << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
