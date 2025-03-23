#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int solve() {
  int n, q;
  cin >> n >> q;
  vector<bool> r(n + 1), c(n + 1);
  int ans = 0;
  while (q--) {
    int rt, ct;
    cin >> rt >> ct;
    if (r[rt] && c[ct])
      ans++;
    r[rt] = c[ct] = true;
  }
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Strategy #" << tc << ": " << solve() << "\n\n";
  }
}
