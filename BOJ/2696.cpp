#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void balance(priority_queue<int>& small, priority_queue<int, vector<int>, greater<int>>& large) {
  while (large.size() < small.size()) {
    large.push(small.top());
    small.pop();
  }
  while (large.size() > small.size()) {
    small.push(large.top());
    large.pop();
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> ans;
  priority_queue<int> smallPQ;
  priority_queue<int, vector<int>, greater<int>> largePQ;
  smallPQ.push(INT_MIN);
  largePQ.push(INT_MAX);
  for (int i = 1;i <= n;i++) {
    int temp;
    cin >> temp;
    if (largePQ.top() < temp)
      largePQ.push(temp);
    else
      smallPQ.push(temp);
    balance(smallPQ, largePQ);
    if (i % 2)
      ans.push_back(smallPQ.top());
  }

  int sz = ans.size();
  cout << sz << endl;
  for (int i = 0;i < sz;i++) {
    cout << ans[i] << ( ( i + 1 ) % 10 ? ' ' : '\n' );
  }
  cout << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
