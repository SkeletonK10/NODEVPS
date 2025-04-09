#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef std::vector<std::vector<int>> mino;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

const mino
iMino = { {1, 1, 1, 1} },
oMino = {
  {1, 1},
  {1, 1}
},
lMino = {
  {1, 0},
  {1, 0},
  {1, 1},
},
jMino = {
  {0, 1},
  {0, 1},
  {1, 1},
},
sMino = {
  {1, 0},
  {1, 1},
  {0, 1},
},
zMino = {
  {0, 1},
  {1, 1},
  {1, 0},
},
tMino = {
  {0, 1},
  {1, 1},
  {0, 1},
};

set<mino> minoSet = { iMino, oMino, lMino, jMino, sMino, zMino, tMino };

int tile(const mino& m, const vector<vector<int>>& field, int sr, int sc) {
  int r = m.size(), c = m[0].size();
  int res = 0;
  for (int i = 0;i < r;i++)
    for (int j = 0;j < c;j++)
      res += field[sr + i][sc + j] * m[i][j];
  return res;
}

void rotate(mino& m) {
  int r = m.size(), c = m[0].size();
  vector<vector<int>> res(c, vector<int>(r));
  for (int i = 0;i < r;i++)
    for (int j = 0;j < c;j++)
      res[j][r - 1 - i] = m[i][j];
  m = res;
}

void solve() {
  int N, M;
  int ans = 0;
  cin >> N >> M;
  vector<vector<int>> field(N, vector<int>(M));
  for (auto& v : field)
    for (auto& i : v)
      cin >> i;
  for (mino m : minoSet) {
    for (int rc = 0;rc < 4;rc++) {
      int r = m.size(), c = m[0].size();
      for (int i = 0;i <= N - r;i++)
        for (int j = 0;j <= M - c;j++)
          ans = max(ans, tile(m, field, i, j));
      rotate(m);
    }
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
