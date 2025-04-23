#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int cnt(const vector<int>& v) {
  int mx = 0, ans = 0;
  for (int i : v) {
    if (mx < i) {
      mx = i;
      ans++;
    }
  }
  return ans;
}

void solve() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int& i : v)
    cin >> i;
  cout << cnt(v) << endl;
  reverse(v.begin(), v.end());
  cout << cnt(v);
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
