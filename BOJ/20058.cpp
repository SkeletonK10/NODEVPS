#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
int field[66][66];
int temp[66][66];

void rotate(int sx, int sy, int l) {
  for (int i = 0;i < l;i++)
    for (int j = 0;j < l;j++)
      temp[j][l - 1 - i] = field[sx + i][sy + j];
  for (int i = 0;i < l;i++)
    for (int j = 0;j < l;j++)
      field[sx + i][sy + j] = temp[i][j];
}

void melt() {
  for (int x = 1;x <= N;x++) {
    for (int y = 1;y <= N;y++) {
      temp[x][y] = field[x][y];
      int around = 0;
      for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (field[nx][ny])
          around++;
      }
      if (around < 3)
        temp[x][y] = max(0, temp[x][y] - 1);
    }
  }
  for (int x = 1;x <= N;x++)
    for (int y = 1;y <= N;y++)
      field[x][y] = temp[x][y];
}

int getSum() {
  int res = 0;
  for (int i = 1;i <= N;i++)
    for (int j = 1;j <= N;j++)
      res += field[i][j];
  return res;
}

int bfs(int sx, int sy) {
  auto& vst = temp;
  int res = 0;
  queue<pii> q;
  q.push({ sx,sy });
  vst[sx][sy] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    res++;
    for (int i = 0;i < 4;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!vst[nx][ny] && field[nx][ny]) {
        vst[nx][ny] = 1;
        q.push({ nx,ny });
      }
    }
  }
  return res;
}

int getMaxComponent() {
  memset(temp, 0, sizeof(temp));
  int res = 0;
  for (int i = 1;i <= N;i++) {
    for (int j = 1;j <= N;j++) {
      if (!temp[i][j] && field[i][j]) {
        res = max(res, bfs(i, j));
      }
    }
  }
  return res;
}

void solve() {
  int Q;
  cin >> N >> Q;
  N = 1 << N;
  for (int i = 1;i <= N;i++)
    for (int j = 1;j <= N;j++)
      cin >> field[i][j];
  while (Q--) {
    int level;
    cin >> level;
    level = 1 << level;
    for (int i = 1;i < N;i += level)
      for (int j = 1;j < N;j += level)
        rotate(i, j, level);
    melt();
  }

  cout << getSum() << endl << getMaxComponent();
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
