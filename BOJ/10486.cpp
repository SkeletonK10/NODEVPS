#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define FF first
#define SS second

//////New Type Definition////////////////////////////////////////////////////////////////

typedef std::pair<int, double> pid;
typedef std::pair<double, int> pdi;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

bool solve() {
  int n;
  cin >> n;
  if (n == 0) return false;
  vector<vector<pid>> adj(1001);    // 변의 길이를 vertex로 관리, pair<int, double>
  for (int i = 0;i < n;i++) {
    int a, b, h;
    cin >> a >> b >> h;
    double area = (double)( a + b ) * h / 2;
    double cost = area / 50;
    adj[a].push_back({ b,cost });
    adj[b].push_back({ a,cost });
  }
  int s, e;
  cin >> s >> e;
  priority_queue<pdi, vector<pdi>, greater<pdi>> pq;  // pair<double, int>, adj와 타입 다름 주의
  vector<double> dist(1001, INF);
  pq.push({ 0,s });
  dist[s] = 0;
  while (!pq.empty()) {
    auto [curDist, cur] = pq.top();
    pq.pop();
    if (cur == e) {
      cout << curDist << endl;
      return true;
    }
    for (auto [nxt, nxtDist] : adj[cur]) {
      if (dist[nxt] > curDist + nxtDist) {
        dist[nxt] = curDist + nxtDist;
        pq.push({ dist[nxt], nxt });
      }
    }
  }
  return true;  // no way to connect, impossible
}

int main() {
  FastIO;
  cout << fixed << setprecision(2);
  int testcase = 1;
  //cin >> testcase;
  while (solve()) {}
}
