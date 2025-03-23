#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int n, m;
ll msr;
vector<ll> w, on;
set<ll> a, s;

void dfs(int depth) {
  if (depth == m) {
    if (msr >= 0)
      s.insert(msr);
    return;
  }

  dfs(depth + 1);
  msr += w[depth];
  dfs(depth + 1);
  msr -= w[depth] * 2;
  dfs(depth + 1);
  msr += w[depth];
}

ll solve() {
  a = set<ll>();
  w = vector<ll>(m);
  s = set<ll>();
  msr = 0;
  for (int i = 0;i < n;i++) {
    ll temp;
    cin >> temp;
    a.insert(temp);
  }
  for (ll& i : w)
    cin >> i;
  dfs(0);

  for (ll i : s) {
    // cout << "CAN MEASURE " << i << endl;
    if (a.find(i) != a.end())
      a.erase(i);
  }

  if (a.empty())
    return 0;

  set<ll> available;
  for (ll j : s) {
    int i = *a.begin();
    available.insert(i + j);
    available.insert(abs(i - j));
  }
  for (ll i : a) {
    set<ll> ts;
    for (ll j : s) {
      if (available.find(i + j) != available.end())
        ts.insert(i + j);
      if (available.find(abs(i - j)) != available.end())
        ts.insert(abs(i - j));
    }
    available = ts;
  }

  return available.empty() ? -1 : *available.begin();
}

int main() {
  FastIO;

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    cout << solve() << endl;
  }
}
