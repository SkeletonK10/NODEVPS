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

bool intersect(pii a, pii b) {
  if (a.FF > b.FF) swap(a, b);
  return b.FF <= a.SS;
}

void solve() {
  int n, l;
  cin >> n >> l;
  vector<pii> stick(n);
  vector<int> dir(n);
  for (int i = 0;i < n;i++) {
    int len, d;
    cin >> len >> d;
    if (d == 0)
      stick[i] = make_pair(0, len);
    else
      stick[i] = make_pair(l - len, l);
    dir[i] = d;
  }

  int floor = 0;
  for (int t = 0;;t++) {
    while (floor < n - 1 && intersect(stick[floor], stick[floor + 1]))
      floor++;

    if (floor == n - 1) {
      cout << t;
      return;
    }
    for (int i = 0;i < n;i++) {
      if (dir[i] == 0) {
        if (stick[i].SS == l - 1)
          dir[i] = 1;
        stick[i].FF++;
        stick[i].SS++;
      }
      else {
        if (stick[i].FF == 1)
          dir[i] = 0;
        stick[i].FF--;
        stick[i].SS--;
      }
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