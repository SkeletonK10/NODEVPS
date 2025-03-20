#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = std::numbers::pi;

//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector<vector<int>> dst(n, vector<int>(m, -1));
  vector<tiii> room(r);
  for (auto& [x, y, c] : room) {
    cin >> x >> y >> c;
    x--; y--;
  }

  queue<pii> q;
  for (int i = 0;i < c;i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    dst[x][y] = 0;
    q.push({ x, y });
  }

  while (!q.empty()) {
    auto [curX, curY] = q.front();
    q.pop();
    for (int i = 0;i < 4;i++) {
      int nx = curX + dx[i];
      int ny = curY + dy[i];
      if (inRange(nx, ny, n, m) && dst[nx][ny] == -1) {
        q.push({ nx, ny });
        dst[nx][ny] = dst[curX][curY] + 1;
      }
    }
  }
  int ans = INF;
  for (auto& [x, y, c] : room)
    ans = min(ans, dst[x][y] * c);
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
