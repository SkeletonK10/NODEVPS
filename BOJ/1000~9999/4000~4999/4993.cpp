#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

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

char field[21][21];
bool vst[21][21];

void solve() {
  while (true) {
    memset(vst, 0, sizeof(vst));
    int n, m;
    cin >> m >> n;
    if (n == 0 && m == 0) return;

    for (int i = 0;i < n;i++)
      cin >> field[i];

    int ans = 0;
    queue<pii> q;
    for (int i = 0;i < n;i++)
      for (int j = 0;j < m;j++)
        if (field[i][j] == '@') {
          q.push({ i,j });
          vst[i][j] = true;
          ans++;
        }


    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inRange(nx, ny, n, m) && field[nx][ny] == '.' && !vst[nx][ny]) {
          vst[nx][ny] = true;
          ans++;
          q.push({ nx,ny });
        }
      }
    }
    cout << ans << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
