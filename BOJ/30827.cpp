#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, k, ans = 0;
  cin >> n >> k;
  vector<pii> meeting(n);
  vector<int> room(k, -1);
  for (auto& [s, e] : meeting)
    cin >> s >> e;
  sort(all(meeting), [](pii& a, pii& b) { return a.SS < b.SS; });
  for (int i = 0;i < n;i++) {
    sort(all(room));
    reverse(all(room));
    for (int j = 0;j < k;j++) {
      if (meeting[i].FF > room[j]) {
        ans++;
        room[j] = meeting[i].SS;
        break;
      }
    }
  }
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
