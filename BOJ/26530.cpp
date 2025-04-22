#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define FF first

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  stack<pii> st, ans;
  for (int i = 1;i <= N;i++) {
    int num;
    cin >> num;
    int mx = num;
    while (!st.empty() && st.top().FF > num) {
      mx = max(mx, st.top().FF);
      st.pop();
    }
    st.push({ mx,i });
  }
  while (!st.empty()) {
    ans.push(st.top());
    st.pop();
  }
  cout << ans.size() << endl;
  int start = 1;
  while (!ans.empty()) {
    auto [end, _] = ans.top();
    cout << end - start + 1 << ' ';
    for (int i = start;i <= end;i++) {
      cout << i << ' ';
    }
    cout << endl;
    start = end + 1;
    ans.pop();
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
