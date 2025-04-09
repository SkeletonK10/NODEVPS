#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  string s;
  int st, ed;
  cin >> s >> st >> ed;
  for (int i = 0;i < s.length();i++)
    if (i < st || ed <= i)
      cout << s[i];
  cout << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
