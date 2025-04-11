#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef std::tuple<int, int, int> tiii;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int field[1500][1500];

void solve() {
  int n;
  cin >> n;
  for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
      cin >> field[i][j];

  priority_queue<tiii> pq;
  for (int j = 0;j < n;j++)
    pq.push({ field[n - 1][j], n - 1, j });

  for (int i = 0;i < n - 1;i++) {
    auto [_, x, y] = pq.top();
    pq.pop();
    pq.push({ field[x - 1][y], x - 1, y });
  }
  cout << get<0>(pq.top());
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
