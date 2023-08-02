#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> lis(1);
  for (int i = 1;i <= n;i++) {
    int a;
    cin >> a;
    if (lis.back() < a)
      lis.push_back(a);
    else
      *upper_bound(all(lis), a - 1) = a;
  }
  cout << lis.size() - 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
