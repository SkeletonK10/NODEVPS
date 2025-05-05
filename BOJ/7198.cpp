//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int N, R, V;
char field[21][21];
bool vst[21][21];

bool dfs(const string& s, int x, int y, int idx) {
  if (idx == s.length()) return true;
  for (int i = 0;i < 4;i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (inRange(nx, ny, N, N) && field[nx][ny] == s[idx] && !vst[nx][ny]) {
      vst[nx][ny] = true;
      if (dfs(s, nx, ny, idx + 1))
        return true;
      vst[nx][ny] = false;
    }
  }
  return false;
}

bool check(const string& s) {
  fill(&vst[0][0], &vst[20][20] + 1, 0);
  return dfs(s, R - 1, V - 1, 0);
}

void solve() {
  cin >> N >> R >> V;
  for (int i = 0;i < N;i++)
    cin >> field[i];
  int K;
  cin >> K;
  vector<string> ans;
  while (K--) {
    string s;
    cin >> s;
    if (check(s))
      ans.push_back(s);
  }
  if (ans.empty())
    cout << "EI SAA";
  for (const string& s : ans)
    cout << s << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
