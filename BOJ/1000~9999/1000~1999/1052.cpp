#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int b = 0;
  for (int i = 23;i >= 0;i--) {
    b += ( n >> i ) & 1;
    if (b == k) {
      int l = ( 1 << i ) - 1;
      cout << ( ( ( ~n & l ) + 1 ) & l );
      return;
    }
  }
  cout << 0;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
