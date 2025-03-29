#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> pos, neg;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    if (temp < 0)
      neg.push_back(-temp);
    else
      pos.push_back(temp);
  }
  sort(pos.rbegin(), pos.rend());
  sort(neg.rbegin(), neg.rend());

  int ans = 0;
  for (int i = 0;i < pos.size();i += m)
    ans += pos[i] * 2;
  for (int i = 0;i < neg.size();i += m)
    ans += neg[i] * 2;

  int posMx = pos.empty() ? 0 : pos[0];
  int negMx = neg.empty() ? 0 : neg[0];
  ans -= max(posMx, negMx);

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
