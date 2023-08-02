#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

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
  vector<pii> v;
  for (int i = 0;i < n;i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({ b, a });
  }

  sort(all(v));
  int now = 0, maxIdle = 1e9 + 7;
  for (auto& [due, time] : v) {
    maxIdle = min(maxIdle, due - now - time);
    now += time;
  }

  cout << maxIdle;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
