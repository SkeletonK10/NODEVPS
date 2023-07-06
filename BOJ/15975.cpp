#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 1987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pii> v(n), last(n + 1, { -1,-1 });
  vector<int> len(n);
  for (auto& [a, b] : v)
    cin >> a >> b;
  sort(all(v));

  for (int i = 0;i < n;i++) {
    auto& [a, b] = v[i];
    if (last[b].FF != -1) {
      len[last[b].SS] = min(len[last[b].SS], a - last[b].FF);
      len[i] = a - last[b].FF;
    }
    else {
      len[i] = INF;
    }
    last[b] = { a,i };
  }
  ll ans = 0;
  for (int i = 0;i < n;i++)
    if (len[i] != INF)
      ans += len[i];
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
