#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define FF first
#define SS second

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = n + 1;
  vector<pii> v;
  for (int i = 0;i < n;i++) {
    int x, r;
    cin >> x >> r;
    v.push_back({ x - r, 1 });    // start
    v.push_back({ x + r, -1 });   // end
  }
  sort(v.begin(), v.end());

  stack<pii> st;
  for (auto [x, flag] : v) {
    if (flag == 1)
      st.push({ 1, x });
    else {
      int acc = 0;
      while (st.top().FF != 1) {
        int a = st.top().SS;
        st.pop();
        acc += a;
      }
      int d = x - st.top().SS;
      if (d == acc)
        ans++;
      st.pop();
      st.push({ 0, d });
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
