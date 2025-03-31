#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int field[20][20], vst[20][20];

void solve() {
  int n, x, y;
  int sz = 2, eat = 0;
  int ans = 0;
  cin >> n;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++) {
      cin >> field[i][j];
      if (field[i][j] == 9) {
        x = i; y = j;
        field[i][j] = 0;
      }
    }
  }

  while (true) {
    memset(vst, -1, sizeof(vst));
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({ 0,x,y });
    vst[x][y] = 0;
    bool judge = false;
    while (!pq.empty()) {
      auto [dst, curX, curY] = pq.top();
      pq.pop();
      if (field[curX][curY] != 0 && field[curX][curY] < sz) {
        ans += dst;
        judge = true;
        field[curX][curY] = 0;
        x = curX; y = curY;
        eat++;
        break;
      }

      for (int i = 0;i < 4;i++) {
        int nx = curX + dx[i];
        int ny = curY + dy[i];
        if (inRange(nx, ny, n, n) && vst[nx][ny] == -1 && field[nx][ny] <= sz) {
          vst[nx][ny] = dst + 1;
          pq.push({ dst + 1,nx,ny });
        }
      }
    }
    if (eat == sz) {
      eat = 0;
      sz++;
    }
    if (!judge)
      break;
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
