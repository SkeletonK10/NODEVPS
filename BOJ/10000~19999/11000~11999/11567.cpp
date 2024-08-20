#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

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

char field[501][501];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0;i < n;i++)
    cin >> field[i];
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  r1--; c1--; r2--; c2--;

  queue<pii> q;
  q.push({ r1, c1 });
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    // cout << x << ' ' << y << endl;
    for (int i = 0;i < 4;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inRange(nx, ny, n, m)) {
        if (field[nx][ny] == 'X' && nx == r2 && ny == c2) {
          cout << "YES";
          return;
        }
        if (field[nx][ny] == '.') {
          field[nx][ny] = 'X';
          q.push({ nx, ny });
        }
      }
    }
  }
  cout << "NO";
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
