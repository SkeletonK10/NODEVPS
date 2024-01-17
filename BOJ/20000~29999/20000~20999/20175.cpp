#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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

// 해결 아이디어
// 로봇들의 집합지를 구하는 과정에서 답을 구할 수 있다.

// 집합지를 시작 지점으로 대충 정해놓자.
// 그리고 각자 위치로 가야 하는 곳까지의 거리 중 최대/최소를 구한다.
// 중간 친구들이 뭐라 하던, 최대와 최소의 거리를 맞출 때가 최적
// 이때 로봇이 가야 할 최대 거리는 (최대 - 최소) / 2

// 주의: 로봇이 역순으로 배열될 수 있음

void solve() {
  ll n, d;
  cin >> n >> d;
  ll mx = -LINF, mn = LINF;
  vector<ll> v(n);
  for (ll& i : v)
    cin >> i;
  ll start = v[0];
  for (int i = 0;i < n;i++) {
    mx = max(mx, v[i] - ( start + d * i ));
    mn = min(mn, v[i] - ( start + d * i ));
  }
  ll ans = mx - mn;

  mx = -LINF, mn = LINF;
  for (int i = 0;i < n;i++) {
    mx = max(mx, v[i] - ( start - d * i ));
    mn = min(mn, v[i] - ( start - d * i ));
  }
  ans = min(ans, mx - mn);
  cout << ans / 2;
  if (ans % 2)
    cout << ".5";
  else
    cout << ".0";
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
