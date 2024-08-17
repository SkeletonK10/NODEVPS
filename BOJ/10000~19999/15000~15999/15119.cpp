#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void subroutine(string& s, int& ans, int& ansL, int& ansR, char c) {
  int tempAns = 0, tempL = 0;
  for (int i = 0;i < s.length();i++) {
    if (s[i] == c)
      tempAns++;
    else
      tempAns--;

    if (tempAns > ans) {
      ansL = tempL;
      ansR = i;
      ans = tempAns;
    }
    else if (tempAns == ans) {
      if (ansL > tempL || ( ansL == tempL && ansR > i )) {
        ansL = tempL;
        ansR = i;
      }
    }
    if (tempAns < 0) {
      tempAns = 0;
      tempL = i + 1;
    }
  }
}

void solve() {
  string s;
  cin >> s;
  int ans = 0, ansL = 0, ansR = 0;
  subroutine(s, ans, ansL, ansR, 'R');
  subroutine(s, ans, ansL, ansR, 'B');
  ansL++; ansR++;
  cout << ansL << ' ' << ansR;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
