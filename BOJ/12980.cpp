#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> v(n), blank, miss;
  vector<bool> num(n + 1);
  for (int i = 0;i < n;i++) {
    cin >> v[i];
    if (!v[i])
      blank.push_back(i);
    num[v[i]] = true;
  }
  for (int i = 1;i <= n;i++)
    if (!num[i])
      miss.push_back(i);

  int sz = blank.size(), ans = 0;
  do {
    int score = 0;
    for (int i = 0;i < sz;i++)
      v[blank[i]] = miss[i];
    for (int i = 0;i < n;i++)
      for (int j = i + 1;j < n;j++)
        score += ( ( v[i] < v[j] ) ? 1 : 0 );
    if (score == s) ans++;
  } while (next_permutation(all(miss)));
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
