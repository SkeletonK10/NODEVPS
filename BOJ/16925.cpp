#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> v(2 * n - 2);
  vector<bool> prefixOccupy1(n), prefixOccupy2(n);
  vector<string> longest;
  string ans1, ans2, seq1, seq2;
  for (string& s : v) {
    cin >> s;
    if (s.length() == n - 1) {
      longest.push_back(s);
    }
  }
  ans1 = longest[0][0] + longest[0].substr(1) + longest[1][n - 2];
  ans2 = longest[1][0] + longest[1].substr(1) + longest[0][n - 2];

  bool judge = true;
  for (string& s : v) {
    int sz = s.length();
    if (s == ans1.substr(0, sz) && !prefixOccupy1[sz]) {
      prefixOccupy1[sz] = true;
      seq1 += 'P';
    }
    else if (s == ans1.substr(n - sz)) {
      seq1 += 'S';
    }
    else {
      judge = false;
    }
  }
  for (string& s : v) {
    int sz = s.length();
    if (s == ans2.substr(0, sz) && !prefixOccupy2[sz]) {
      prefixOccupy2[sz] = true;
      seq2 += 'P';
    }
    else if (s == ans2.substr(n - sz)) {
      seq2 += 'S';
    }
  }
  if (judge)
    cout << ans1 << endl << seq1;
  else
    cout << ans2 << endl << seq2;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
