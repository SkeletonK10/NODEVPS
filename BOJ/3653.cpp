#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int tree[2 * SZ + 1], arr[SZ + 1], loc[SZ + 1];

int init(int s = 1, int e = SZ, int node = 1) {
  int m = ( s + e ) / 2;
  if (s == e) return tree[node] = arr[s];
  else return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

int sum(int l, int r, int s = 1, int e = SZ, int node = 1) {
  int m = ( s + e ) / 2;
  if (r < s || e < l) return 0;
  else if (l <= s && e <= r) return tree[node];
  else return sum(l, r, s, m, node * 2) + sum(l, r, m + 1, e, node * 2 + 1);
}

int update(int target, int to, int s = 1, int e = SZ, int node = 1) {
  int m = ( s + e ) / 2;
  if (target < s || e < target) return tree[node];
  else if (s == e) return tree[node] = to;
  else return tree[node] = update(target, to, s, m, node * 2) + update(target, to, m + 1, e, node * 2 + 1);
}

void solve() {
  memset(tree, 0, sizeof(tree));
  memset(arr, 0, sizeof(arr));
  int N, M;
  cin >> N >> M;
  for (int i = 1;i <= N;i++) {
    arr[SZ - N + i] = 1;
    loc[i] = SZ - N + i;
  }
  init();
  int top = SZ - N;
  while (M--) {
    int want;
    cin >> want;
    cout << sum(1, loc[want]) - 1 << ' ';
    update(loc[want], 0);
    update(top, 1);
    loc[want] = top;
    top--;
  }
  cout << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
