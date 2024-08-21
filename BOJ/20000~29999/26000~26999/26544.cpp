#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

int solve() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    ans += temp;
  }
  int prev = 0;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    ans += temp;
    ans -= min(prev, temp);
    prev = temp;
  }
  return ans * 2;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve() << endl;
  }
}
