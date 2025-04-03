#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

char field[15][15];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<char> firstAppear(n, '.');
  for (int i = 0;i < n;i++) {
    cin >> field[i];
    for (int j = 0;j < m;j++) {
      if (field[i][j] != '?') {
        firstAppear[i] = field[i][j];
        break;
      }
    }
  }
  int firstAppearLine = -1;
  for (int i = 0;i < n;i++) {
    if (firstAppear[i] == '.')
      continue;
    if (firstAppearLine == -1)
      firstAppearLine = i;
    for (int j = 0;j < m;j++) {
      if (field[i][j] != '?')
        firstAppear[i] = field[i][j];
      field[i][j] = firstAppear[i];
    }
  }
  for (int i = firstAppearLine - 1;i >= 0;i--)
    for (int j = 0;j < m;j++)
      field[i][j] = field[i + 1][j];
  for (int i = firstAppearLine + 1;i < n;i++) {
    if (firstAppear[i] != '.') continue;
    for (int j = 0;j < m;j++)
      field[i][j] = field[i - 1][j];
  }
  for (int i = 0;i < n;i++)
    cout << field[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case #" << tc << ':' << endl;
    solve();
  }
}
