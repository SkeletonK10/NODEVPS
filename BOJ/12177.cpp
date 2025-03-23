#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll solve() {
  ll k, v;
  cin >> k >> v;
  k++;
  ll ans1 = k;

  ll ans2 = ( k - v ) * v;
  for (ll i = v - 1;i > 0;i--)
    ans2 += i;
  ans2 *= 6;

  ll ans3 = ( v * ( v - 1 ) / 2 ) * ( k - v );
  for (ll i = v - 1;i > 0;i--)
    ans3 += i * ( i - 1 ) / 2;
  ans3 *= 6;
  return ans1 + ans2 + ans3;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
}
