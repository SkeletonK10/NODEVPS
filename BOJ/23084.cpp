#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

int diff(vector<int>& oCnt, vector<int>& sCnt) {
  int sum = 0;
  for (int i = 0;i < 26;i++)
    sum += abs(oCnt[i] - sCnt[i]);
  return sum;
}

bool solve(vector<int>& oCnt, int sz) {
  string s;
  vector<int> sCnt(26);
  cin >> s;
  if (s.size() < sz)
    return false;

  for (int i = 0;i < sz;i++)
    sCnt[s[i] - 'a']++;

  int d = diff(oCnt, sCnt);
  if (s.size() == sz) {
    if (d == 2)
      return true;
  }
  else {
    if (d == 0 || d == 2)
      return true;
    for (int i = sz;i < s.size();i++) {
      sCnt[s[i - sz] - 'a']--;
      sCnt[s[i] - 'a']++;
      d = diff(oCnt, sCnt);
      if (d == 0 || d == 2)
        return true;
    }
  }
  return false;
}

int main() {
  FastIO;
  string o;
  vector<int> oCnt(26);
  cin >> o;
  int sz = o.size();

  for (char& c : o)
    oCnt[c - 'a']++;

  int testcase = 1;
  cin >> testcase;
  while (testcase--) {
    if (solve(oCnt, sz))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
