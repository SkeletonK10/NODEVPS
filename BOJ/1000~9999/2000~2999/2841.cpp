#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, p, ans = 0;
  cin >> n >> p;
  stack<int> st[7];
  for (int i = 1;i <= 6;i++)
    st[i].push(0);

  while(n--) {
    int a, b;
    cin >> a >> b;
    while (st[a].top() > b) {
      ans++;
      st[a].pop();
    }
    if (st[a].top() != b) {
      ans++;
      st[a].push(b);
    }
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
