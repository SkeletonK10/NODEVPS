#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

// (ex: n == 371이라면)
// loop 1: 1의자리 => 1
//   0,1에 1씩 더해줌
// loop 2: 10의자리 => 7
//   0,1,2,3,4,5,6에 10씩 더해줌
//   7에 2 더해줌 (70, 71)
//   0 ~ 9에 7 * 1씩 더해줌 (1의자리가 그만큼 움직였음)
// loop 3: 100의자리 => 3
//   0,1,2에 100씩 더해줌
//   3에 72 더해줌 (300 ~ 371)
//   0~9에 3 * 20씩 더해줌 (1의자리+10의자리가 그만큼 움직임)
// ...
// 루프 종료
// 0에 자릿수만큼 빼줌 (111 빼기)

ll pow10ll(ll dgt) {
  ll ret = 1;
  for (ll i = 0;i < dgt;i++)
    ret *= 10;
  return ret;
}

void solve() {
  vector<ll> ans(10);
  ll n;
  cin >> n;
  ll dgt = 0, acc = 0;
  while (n) {
    ll coord = pow10ll(dgt);
    int d = n % 10;
    for (int i = 0;i < d;i++)
      ans[i] += coord;
    ans[d] += acc % coord + 1;
    acc += d * coord;
    for (int i = 0;i <= 9;i++)
      ans[i] += dgt * pow10ll(dgt - 1) * d;
    ans[0] -= coord;
    dgt++; n /= 10;
  }
  for (ll& i : ans)
    cout << i << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
