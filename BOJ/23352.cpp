#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////2D Graph Search//////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

///////////////////////////////////////////////////////////

using namespace std;

int n, m;
int arr[50][50];

pii bfs(int sx, int sy) {
  pii res = { 0,arr[sx][sy] };
  queue<pii> q;
  vector<vector<int>> vst(n, vector<int>(m, -1));
  q.push({ sx,sy });
  vst[sx][sy] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0;i < 4;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inRange(nx, ny, n, m) && vst[nx][ny] == -1 && arr[nx][ny] != 0) {
        vst[nx][ny] = vst[x][y] + 1;
        res = max(res, { vst[nx][ny], arr[nx][ny] });
        q.push({ nx,ny });

      }
    }
  }
  res.SS += arr[sx][sy];
  return res;
}

void solve() {
  cin >> n >> m;
  for (int i = 0;i < n;i++)
    for (int j = 0;j < m;j++)
      cin >> arr[i][j];
  pii ans = { 0,0 };
  for (int i = 0;i < n;i++)
    for (int j = 0;j < m;j++)
      if (arr[i][j])
        ans = max(ans, bfs(i, j));
  cout << ans.SS;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
