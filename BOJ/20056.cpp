#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,-1,0,1,1,1,0,-1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };

// bool inRange(int i, int j, int n, int m) {
//   return 0 <= i && i < n && 0 <= j && j < m;
// }

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int assign() {
  static int nxt = 10000;
  return nxt++;
}

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<vector<int>>> field(N, vector<vector<int>>(N)), tempField(field);
  map<int, tiii> fMap;
  for (int i = 1;i <= M;i++) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    field[r - 1][c - 1].push_back(i);
    fMap[i] = { m,s,d };
  }
  while (K--) {
    // Move Phase
    for (int x = 0;x < N;x++) {
      for (int y = 0;y < N;y++) {
        for (int ballIndex : field[x][y]) {
          auto [m, s, d] = fMap[ballIndex];
          int nx = ( x + dx[d] * s + 1000 * N ) % N;
          int ny = ( y + dy[d] * s + 1000 * N ) % N;
          tempField[nx][ny].push_back(ballIndex);
        }
      }
    }
    field = tempField;
    for (int i = 0;i < N;i++)
      for (int j = 0;j < N;j++)
        tempField[i][j].clear();

    // Merge Phase
    for (int x = 0;x < N;x++) {
      for (int y = 0;y < N;y++) {
        int sz = field[x][y].size();
        if (sz > 1) {
          int aggM = 0, aggS = 0, aggD = 0;
          for (int ballIndex : field[x][y]) {
            auto [m, s, d] = fMap[ballIndex];
            aggM += m; aggS += s; aggD += d % 2;
          }
          aggM /= 5; aggS /= sz;
          int dOffset = aggD == 0 || aggD == sz ? 0 : 1;
          vector<int> newCell;
          if (aggM > 0) {
            for (int i = 0;i < 4;i++) {
              int newIdx = assign();
              fMap[newIdx] = { aggM, aggS, i * 2 + dOffset };
              newCell.push_back(newIdx);
            }
          }
          field[x][y] = newCell;
        }
      }
    }
  }
  int ans = 0;
  for (int x = 0;x < N;x++)
    for (int y = 0;y < N;y++)
      for (int ballIndex : field[x][y])
        ans += get<0>(fMap[ballIndex]);
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
