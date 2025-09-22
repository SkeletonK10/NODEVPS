//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<string> v(N);
  for (string& s : v)
    cin >> s;
  sort(v.begin(), v.end());

  int ans = INF;
  do {
    string s = v[0];
    for (int i = 1;i < N;i++) {
      int sz = s.length();
      int minSz = min(sz, (int)v[i].length());
      int overlapped = 0;
      for (int j = 1;j <= minSz;j++) {
        bool flag = true;
        for (int k = 0;k < j;k++) {
          if (s[sz - j + k] != v[i][k]) {
            flag = false;
            break;
          }
        }
        if (flag)
          overlapped = j;
      }
      s = s.substr(0, sz - overlapped) + v[i];
    }
    ans = min(ans, (int)s.length());
  } while (next_permutation(v.begin(), v.end()));

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
