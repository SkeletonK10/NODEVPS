#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
  int n, k;
  cin >> n >> k;
  vector<pii> v(k);
  for (pii& i : v) {
    cin >> i.FF >> i.SS;
    if (i.FF < i.SS)
      swap(i.FF, i.SS);
  }

  sort(all(v));
  int i = 0, cur = 0, ans = 0;
  while (i < k) {
    ans++;
    cur = v[i].FF;
    for (int j = i + 1;j <= k;j++) {
      if (j == k || v[j].SS > cur) {
        i = j;
        break;
      }
    }
  }
  cout << ans + 1 << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
