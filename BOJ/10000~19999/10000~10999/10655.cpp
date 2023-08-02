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
  int n;
  cin >> n;
  vector<pii> v(n);
  for (auto& [a, b] : v)
    cin >> a >> b;
  vector<ll> dist(n);
  for (int i = 1;i <= n - 1;i++)
    dist[i] = dist[i - 1] + abs(v[i - 1].FF - v[i].FF) + abs(v[i - 1].SS - v[i].SS);
  ll ans = LINF;
  for (int i = 1;i < n - 1;i++)
    ans = min(ans, dist[i - 1] + dist[n - 1] - dist[i + 1] + abs(v[i - 1].FF - v[i + 1].FF) + abs(v[i - 1].SS - v[i + 1].SS));
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
