#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  vector<map<int, int>> cont(11);
  for (int i = 0;i < 2047;i++) {
    for (int dim = 0;dim < 11;dim++) {
      int temp;
      cin >> temp;
      cont[dim][temp]++;
    }
  }
  for (int dim = 0;dim < 11;dim++) {
    int mn = 1e8, mnLoc;
    for (auto [loc, a] : cont[dim]) {
      if (mn > a) {
        mn = a;
        mnLoc = loc;
      }
    }
    cout << mnLoc << ' ';
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
