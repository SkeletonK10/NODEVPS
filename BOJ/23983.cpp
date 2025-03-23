#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

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

ll solve() {
  int n;
  cin >> n;
  vector<ll> v(n), mp(SZ);
  for (ll& i : v) {
    cin >> i;
    mp[i]++;
  }

  sort(all(v));

  ll ans = 0, ans2 = 0, ans3 = 0;
  for (int i = 0;i < n - 1;i++) {
    for (int j = i + 1;j < n;j++) {
      mp[v[i]]--;
      mp[v[j]]--;

      ll pro = v[i] * v[j];
      if (pro <= 200000) {
        if (v[i] == v[j] && v[i] == pro)
          ans3 += mp[pro];
        else if (v[i] == pro || v[j] == pro)
          ans2 += mp[pro];
        else
          ans += mp[pro];
      }
      mp[v[i]]++;
      mp[v[j]]++;
    }
  }
  return ans + ( ans2 / 2 ) + ( ans3 / 3 );
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1; tc <= testcase;tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
}
