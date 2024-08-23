#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int g = gcd(a, b);
  if (max(a, b) < c || c % g)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
