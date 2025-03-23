#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> fCnt(n + 1);
  vector<pii> edge;
  set<pii> edgeSet;
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    fCnt[s]++;
    fCnt[e]++;
    edge.push_back({ s,e });
    edge.push_back({ e,s });
    edgeSet.insert({ s,e });
    edgeSet.insert({ e,s });
  }

  int ans = INF;
  for (int i = 0;i < 2 * m;i++)
    for (int j = i + 1;j < 2 * m;j++)
      if (edge[i].FF == edge[j].SS && edgeSet.find({ edge[i].SS, edge[j].FF }) != edgeSet.end())
        ans = min(ans, fCnt[edge[i].FF] + fCnt[edge[i].SS] + fCnt[edge[j].FF] - 6);

  cout << ( ( ans == INF ) ? -1 : ans );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
