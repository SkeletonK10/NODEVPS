//////New Type Definition////////////////////////////////////////////////////////////////

#include <utility>
typedef std::pair<int, int> pii;

//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,-1,1,1,2,2,-2,-2 };
const int dy[] = { 2,-2,2,-2,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

pii parseCoord(string chessCoord) {
  int x = chessCoord[0] - 'a';
  int y = chessCoord[1] - '1';
  return { x, y };
}

void solve(string s, string e) {
  int vst[8][8] = { 0 };
  pii a = parseCoord(s);
  queue<pii> q;
  q.push(a);
  vst[a.first][a.second] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0;i < 8;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inRange(nx, ny, 8, 8) && !vst[nx][ny]) {
        vst[nx][ny] = vst[x][y] + 1;
        q.push({ nx, ny });
      }
    }
  }
  pii b = parseCoord(e);
  cout << "To get from " << s << " to " << e << " takes " << vst[b.first][b.second] - 1 << " knight moves." << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  string s, e;
  while (cin >> s >> e) {
    solve(s, e);
  }
}
