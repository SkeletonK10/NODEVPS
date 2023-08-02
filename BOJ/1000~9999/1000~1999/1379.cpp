#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<tiii> v(n);
  for (auto& [s, e, i] : v)
    cin >> i >> s >> e;
  sort(all(v));

  int cnt = 1;
  vector<int> ans(n + 1);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({ 0,1 });
  for (auto& [s, e, i] : v) {
    int roomIndex;
    auto [ra, ri] = pq.top();
    if (ra > s) {
      cnt++;
      roomIndex = cnt;
    }
    else {
      pq.pop();
      roomIndex = ri;
    }
    ans[i] = roomIndex;
    pq.push({ e, roomIndex });
  }
  cout << cnt << endl;
  for (int i = 1;i <= n;i++)
    cout << ans[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
