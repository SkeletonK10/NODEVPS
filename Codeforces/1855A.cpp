#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, s = 0;
  cin >> n;
  for (int i = 1;i <= n;i++) {
    int a;
    cin >> a;
    if (a == i)
      s++;
  }
  cout << ( s + 1 ) / 2 << endl;;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
