#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  ll a;
  cin >> a;
  for (int i = 1;;i++) {
    if (a % i) {
      cout << i - 1 << endl;
      break;
    }
  }
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
