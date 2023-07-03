#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

void solve() {
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0;i < n;i++) {
    ll temp;
    cin >> temp;
    pq.push(temp);
  }

  ll ans = 1;
  for (int i = 0;i < n - 1;i++) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    pq.push(a * b);
    ans = ( ans * ( ( a * b ) % MOD ) ) % MOD;
  }
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
