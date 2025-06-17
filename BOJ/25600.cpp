//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  int mx = 0;
  while (N--) {
    int a, d, g;
    cin >> a >> d >> g;
    int mul = ( a == d + g ) ? 2 : 1;
    mx = max(mx, a * ( d + g ) * mul);
  }
  cout << mx;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
