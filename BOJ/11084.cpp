#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 9;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

//////2D Graph Search//////////////////////////////////////

const int dx[] = { -2,-2,-1,-1,1,1,2,2 };
const int dy[] = { -1,1,-2,2,-2,2,-1,1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

///////////////////////////////////////////////////////////

using namespace std;

int ans[400][400], vst[400][400];

void solve() {
  int r, c;
  cin >> r >> c;
  queue<pii> q;
  vst[0][0] = 1;
  ans[0][0] = 1;
  q.push({ 0,0 });
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0;i < 8;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inRange(nx, ny, r, c)) {
        if (vst[nx][ny] == 0) {
          vst[nx][ny] = vst[x][y] + 1;
          ans[nx][ny] = ans[x][y];
          q.push({ nx,ny });
        }
        else if (vst[nx][ny] - 1 == vst[x][y]) {
          ans[nx][ny] += ans[x][y];
          ans[nx][ny] %= MOD;
        }
      }
    }
  }
  if (ans[r - 1][c - 1] == 0)
    cout << "None";
  else
    cout << vst[r - 1][c - 1] - 1 << ' ' << ans[r - 1][c - 1];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
