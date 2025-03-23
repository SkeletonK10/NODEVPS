#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

// 제한이 10^12이기 때문에 단순 배열로는 메모리 초과가 날 것.
// map을 사용해 값을 저장하면 필요한 공간만 사용함. 공간복잡도 O(lgn)

ll p, q;

// Top-down DP
ll A(ll n, map<ll, ll>& mp) {
  if (mp[n]) return mp[n];
  else return mp[n] = A(n / p, mp) + A(n / q, mp);
}

void solve() {
  ll n;
  cin >> n >> p >> q;
  map<ll, ll> mp;
  mp[0] = 1;
  cout << A(n, mp);
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
