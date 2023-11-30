#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

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
  stack<pii> st;
  st.push({ INF,-1 });
  vector<int> v(n), cnt(1000001), ans(n, -1);
  for (int& i : v) {
    cin >> i;
    cnt[i]++;
  }

  for (int i = 0; i < n; i++) {
    while (st.top().FF < cnt[v[i]]) {
      ans[st.top().SS] = v[i];
      st.pop();
    }
    st.push({ cnt[v[i]],i });
  }
  for (int i : ans)
    cout << i << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}