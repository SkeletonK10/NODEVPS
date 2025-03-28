#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  if (n == 1) {
    cout << "A";
    return;
  }
  else if (n == 2) {
    if (v[0] != v[1])
      cout << "A";
    else
      cout << v[0];
    return;
  }
  if (v[0] == v[1]) {
    for (int i = 1;i < n;i++) {
      if (v[i] != v[0]) {
        cout << "B";
        return;
      }
    }
    cout << v[0];
    return;
  }
  if (( v[2] - v[1] ) % ( v[1] - v[0] )) {
    cout << "B";
    return;
  }
  int a = ( v[2] - v[1] ) / ( v[1] - v[0] );
  int b = v[1] - v[0] * a;

  for (int i = 1;i < n - 1;i++) {
    if (v[i] * a + b != v[i + 1]) {
      cout << "B";
      return;
    }
  }
  cout << v.back() * a + b;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
