#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool isAllSame(string& s, int len) {
  for (int i = 0;i < len - 1;i++)
    if (s[i] != s[i + 1])
      return false;
  return true;
}

bool isPalindrome(string& s, int len) {
  int i = 0, j = len - 1;
  while (i < j) {
    if (s[i] != s[j])
      return false;
    i++; j--;
  }
  return true;
}

int solve() {
  string s;
  cin >> s;
  int len = s.size();
  if (isAllSame(s, len))
    return -1;
  else if (isPalindrome(s, len))
    return len - 1;
  else
    return len;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve();
  }
}
