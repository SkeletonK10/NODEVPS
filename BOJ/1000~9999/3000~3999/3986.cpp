#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int solve() {
  string s;
  stack<char> st;
  cin >> s;
  for (char& c : s) {
    if (st.empty())
      st.push(c);
    else if (st.top() == c)
      st.pop();
    else
      st.push(c);
  }
  return st.empty() ? 1 : 0;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  int ans = 0;
  for (int tc = 1;tc <= testcase;tc++)
    ans += solve();
  cout << ans;
}
