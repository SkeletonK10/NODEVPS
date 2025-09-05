//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
}

void solve(int N) {
  vector<pair<ll, ll>> v(N);
  for (auto& [a, b] : v)
    cin >> a >> b;
  vector<ll> d1, d2;
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  for (auto& [a, b] : v) {
    d1.push_back(dist(a, b, x1, y1));
    d2.push_back(dist(a, b, x2, y2));
  }
  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());

  int Q;
  cin >> Q;
  while (Q--) {
    ll r1, r2;
    cin >> r1 >> r2;
    int equipment =
      ( upper_bound(d1.begin(), d1.end(), r1 * r1) - d1.begin() ) +
      ( upper_bound(d2.begin(), d2.end(), r2 * r2) - d2.begin() );
    cout << max(0, N - equipment) << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;; tc++) {
    int N;
    cin >> N;
    if (!N) break;
    cout << "Case " << tc << ":" << endl;
    solve(N);
  }
}
