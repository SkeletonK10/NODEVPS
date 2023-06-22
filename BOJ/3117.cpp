#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> watch(n), to(k + 1);
  for (int& i : watch)
    cin >> i;
  for (int i = 1;i <= k;i++)
    cin >> to[i];
  vector<int> ans(k + 1);
  for (int i = 1;i <= k;i++)
    ans[i] = i;

  m--;
  vector<int> temp(k + 1);
  while (m) {
    if (m % 2) {
      for (int i = 1;i <= k;i++)
        ans[i] = to[ans[i]];
      m--;
    }
    else {
      for (int i = 1;i <= k;i++)
        temp[i] = to[to[i]];
      to = temp;
      m /= 2;
    }
  }
  for (int i : watch)
    cout << ans[i] << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
