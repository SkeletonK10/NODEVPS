#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 2e9 + 1;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  int l = 0, r = n - 1;
  int ans = INF, ansL, ansR;
  while (l < r) {
    int s = v[l] + v[r];
    if (ans > abs(s)) {
      ans = abs(s);
      ansL = l;
      ansR = r;
    }
    if (s < 0) l++;
    else if (s > 0) r--;
    else break;
  }
  cout << v[ansL] << ' ' << v[ansR];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
