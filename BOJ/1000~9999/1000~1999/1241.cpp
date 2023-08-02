#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n), mp(1000001);
  for (int& i : v) {
    cin >> i;
    mp[i]++;
  }
  for (int& i : v) {
    int ans = 0;
    for (int j = 1; j * j <= i;j++) {
      if (i % j == 0) {
        ans += mp[j];
        if (j * j != i)
          ans += mp[i / j];
      }
    }
    cout << ans - 1 << endl;
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
