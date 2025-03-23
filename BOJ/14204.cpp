#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int solve() {
  int arr[50][50];
  int n, m;
  cin >> n >> m;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      cin >> arr[i][j];
      arr[i][j]--;
    }
  }
  for (int i = 0;i < n;i++) {
    int q = arr[i][0] / m;
    for (int j = 0;j < m;j++)
      if (arr[i][j] / m != q)
        return 0;
  }
  for (int j = 0;j < m;j++) {
    int r = arr[0][j] % m;
    for (int i = 0;i < n;i++)
      if (arr[i][j] % m != r)
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
