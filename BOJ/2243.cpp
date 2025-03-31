#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 1 << 20; // 1048576
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int arr[SZ + 1], tree[2 * SZ + 1];

int update(int target, int diff, int s = 1, int e = SZ, int node = 1) {
  if (target < s || e < target) return tree[node];
  else if (s == e) return tree[node] += diff;
  else {
    int m = ( s + e ) / 2;
    return tree[node] = update(target, diff, s, m, node * 2) + update(target, diff, m + 1, e, node * 2 + 1);
  }
}

int sum(int l, int r, int s = 1, int e = SZ, int node = 1) {
  if (r < s || e < l) return 0;
  else if (l <= s && e <= r) return tree[node];
  else {
    int m = ( s + e ) / 2;
    return sum(l, r, s, m, node * 2) + sum(l, r, m + 1, e, node * 2 + 1);
  }
}

int query(int target) {
  int s = 1, e = SZ;
  while (s < e) {
    int m = ( s + e ) / 2;
    if (sum(1, m) < target) {
      s = m + 1;
    }
    else {
      e = m;
    }
  }
  return s;
}

void solve() {
  int q;
  cin >> q;
  while (q--) {
    int cmd, a, b;
    cin >> cmd >> a;
    if (cmd == 1) {
      int ans = query(a);
      cout << ans << endl;
      update(ans, -1);
    }
    else {
      cin >> b;
      update(a, b);
    }

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
