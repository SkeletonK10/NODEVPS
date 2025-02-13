#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

bool solve() {
  int l, ml, mk, cAmmo;
  cin >> l >> ml >> mk >> cAmmo;
  queue<int> q;
  for (int i = 0;i < l;i++) {
    if (!q.empty() && q.front() <= i - ml)
      q.pop();
    int dmg = mk * ( q.size() + 1 ), h;
    cin >> h;
    if (dmg >= h) {
      q.push(i);
      continue;
    }
    else {
      if (cAmmo > 0)
        cAmmo--;
      else
        return false;
    }
  }
  return true;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << (solve() ? "YES" : "NO");
  }
}
