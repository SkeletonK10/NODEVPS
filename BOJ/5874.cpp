//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  string s;
  cin >> s;
  int N = s.length();
  int ans = 0;
  vector<int> v(N);
  for (int i = 1;i < N;i++) {
    if (s[i - 1] == '(' && s[i] == '(')
      v[i]++;
    v[i] += v[i - 1];
  }
  for (int i = 1;i < N;i++)
    if (s[i - 1] == ')' && s[i] == ')')
      ans += v[i];
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
