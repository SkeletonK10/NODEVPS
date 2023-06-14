#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, ans = 0, garbage;
  stack<int> st;
  st.push(0);
  cin >> n >> garbage;
  for (int i = 0;i < n;i++) {
    int y;
    cin >> garbage >> y;
    while (st.top() > y)
      st.pop();
    if (y > st.top()) {
      ans++;
      st.push(y);
    }
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
