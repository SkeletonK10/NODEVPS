#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  priority_queue<pii> jewel;
  priority_queue<int> bag;
  priority_queue<int, vector<int>, greater<int>> usedBag;
  for (int i = 0;i < n;i++) {
    int m, v;
    cin >> m >> v;
    jewel.push({ m, v });
  }
  for (int i = 0;i < k;i++) {
    int c;
    cin >> c;
    bag.push(c);
  }
  bag.push(-1);
  while (!jewel.empty()) {
    auto [m, v] = jewel.top();
    jewel.pop();
    if (m > bag.top()) {
      if (usedBag.empty())
        continue;
      else if (usedBag.top() < v) {
        usedBag.pop();
        usedBag.push(v);
      }
    }
    else {
      bag.pop();
      usedBag.push(v);
    }
  }
  ll ans = 0;
  while (!usedBag.empty()) {
    ans += usedBag.top();
    usedBag.pop();
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
