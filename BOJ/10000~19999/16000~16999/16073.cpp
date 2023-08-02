#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> field(h + 2, vector<int>(w + 2));
  vector<string> ans(h);
  for (int i = 0;i < h + 2;i++)
    for (int j = 0;j < w + 2;j++)
      cin >> field[i][j];
  for (int i = 1;i < h + 1;i++) {
    for (int j = 1;j < w + 1;j++) {
      if (field[i - 1][j - 1] == 1) {
        ans[i - 1] += 'X';
        for (int k = -1;k <= 1;k++)
          for (int l = -1;l <= 1;l++)
            field[i + k][j + l]--;
      }
      else if (field[i - 1][j - 1] == 0)
        ans[i - 1] += '.';
    }
  }
  for (int i = 0;i < h + 2;i++) {
    for (int j = 0;j < w + 2;j++) {
      if (field[i][j] != 0) {
        cout << "impossible";
        return;
      }
    }
  }

  for (int i = 0;i < h;i++)
    cout << ans[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
