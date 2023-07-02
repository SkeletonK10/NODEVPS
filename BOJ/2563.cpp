#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int arr[100][100];

void solve() {
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x;i < x + 10;i++)
      for (int j = y;j < y + 10;j++)
        arr[i][j] = 1;
  }
  int ans = 0;
  for (int i = 0;i < 100;i++)
    for (int j = 0;j < 100;j++)
      ans += arr[i][j];
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
