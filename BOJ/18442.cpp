#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll cDist(ll a, ll b, ll l) {
  ll ab = abs(a - b);
  return min(ab, l - ab);
}

void solve() {
  int v, p;
  ll l;
  cin >> v >> p >> l;
  vector<ll> ville(v);
  vector<bool> post(v);
  for (int i = 0;i < v;i++)
    cin >> ville[i];
  for (int i = 0;i < p;i++)
    post[i] = true;
  reverse(post.begin(), post.end());

  ll ans = LINF;
  vector<bool> ansV;
  do {
    ll tAns = 0;
    for (int vi = 0; vi < v;vi++) {
      ll minDist = LINF;
      for (int pi = 0;pi < v;pi++) {
        if (post[pi])
          minDist = min(minDist, cDist(ville[vi], ville[pi], l));
      }
      tAns += minDist;
    }
    if (ans > tAns) {
      ans = tAns;
      ansV = post;
    }
  } while (next_permutation(post.begin(), post.end()));
  cout << ans << endl;
  for (int i = 0;i < v;i++)
    if (ansV[i])
      cout << ville[i] << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
