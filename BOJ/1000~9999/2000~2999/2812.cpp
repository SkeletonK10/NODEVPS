#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  stack<int> st;
  st.push(10);
  for (char c : s) {
    int i = c - '0';
    while (st.top() < i && k) {
      k--;
      st.pop();
    }
    st.push(i);
  }
  while (k--)
    st.pop();

  stack<int> ans;
  while (!st.empty()) {
    ans.push(st.top());
    st.pop();
  }
  ans.pop();
  while (!ans.empty()) {
    cout << ans.top();
    ans.pop();
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
