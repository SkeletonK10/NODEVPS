#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int solve() {
  int n, k;
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    pq.push(temp);
  }
  for (int i = 1;i <= n;i++) {
    int target = pq.top();
    while (target < i) {
      pq.pop();
      target += k;
      pq.push(target);
      target = pq.top();
    }
    pq.pop();
    if (target > i)
      return 0;
  }
  return 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve();
  }
}
