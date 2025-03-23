#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> pq;
  while (m--)
    pq.push(0);

  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  sort(all(v));

  for (int i = n - 1;i >= 0;i--) {
    pq.push(pq.top() + v[i]);
    pq.pop();
  }
  int ans = 0;
  while (!pq.empty()) {
    ans = pq.top();
    pq.pop();
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
