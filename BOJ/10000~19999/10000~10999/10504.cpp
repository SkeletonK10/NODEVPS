#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  for (int i = 2;i <= 44721;i++) {
    int tri = i * ( i + 1 ) / 2;
    if (n < tri) {
      cout << "IMPOSSIBLE" << endl;
      break;
    }
    if (( n - tri ) % i == 0) {
      cout << n << " = ";
      int q = ( n - tri ) / i;
      for (int j = 1;j < i;j++) {
        cout << q + j << " + ";
      }
      cout << q + i << endl;
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
