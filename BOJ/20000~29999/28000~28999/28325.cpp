#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll> v(n);
  for (ll& i : v) {
    cin >> i;
    ans += i;
  }

  if (ans == 0) {
    cout << n / 2;
    return;
  }
  
  int cnt = 0;
  vector<int> con;
  for (ll& i : v) {
    if (i == 0)
      cnt++;
    else if (cnt) {
      con.push_back(cnt);
      cnt = 0;
    }

  }
  if (v[0] == 0)
    con[0] += cnt;
  else if (cnt)
    con.push_back(cnt);

  for (int& i : con)
    ans += ( i + 1 ) / 2;
    
  
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
