#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 2e9 + 1;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  sort(v.begin(), v.end());

  int p1 = 0, p2 = n - 1;
  int ans = INF;
  int ansP1 = 0, ansP2 = n - 1;
  while (p1 < p2) {
    int s = v[p1] + v[p2];
    if (ans > abs(s)) {
      ans = abs(s);
      ansP1 = p1;
      ansP2 = p2;
    }
    if (s > 0)
      p2--;
    else
      p1++;
  }
  cout << v[ansP1] << ' ' << v[ansP2];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
