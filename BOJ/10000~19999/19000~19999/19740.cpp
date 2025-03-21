#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, len, mn = 0;
  cin >> n;
  for (int i = 0;i < n;i++) {
    string s;
    cin >> s;
    if (!i) len = s.length();
    mn = max(stoi(s), mn);
  }
  int dgt = 1;
  for (int i = 1;i < len;i++)
    dgt *= 10;
  cout << max(dgt, mn) << endl << dgt * 10 - 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
