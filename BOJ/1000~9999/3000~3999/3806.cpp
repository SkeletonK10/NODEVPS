#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

int solve() {
  string s, t;
  cin >> s >> t;
  map<char, int> ms, mt;
  for (char c : s)
    ms[c]++;
  for (char c : t)
    mt[c]++;
  if (ms['1'] > mt['1'])
    return -1;

  int oz = 0, zo = 0;

  int ans = ms['?'];
  for (int i = 0;i < s.length();i++) {
    if (s[i] == '1' && t[i] == '0')
      zo++;
    if (s[i] == '0' && t[i] == '1')
      oz++;
  }
  return ans + max(zo, oz);
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case " << tc << ": " << solve() << endl;
  }
}
