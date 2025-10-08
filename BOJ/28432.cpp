//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  vector<string> v;
  set<string> st;
  int N, M;
  char start, end;
  cin >> N;
  for (int i = 0;i < N;i++) {
    string s;
    cin >> s;
    v.push_back(s);
    st.insert(s);
  }
  for (int i = 0;i < N;i++) {
    if (v[i][0] == '?') {
      if (i == 0) start = '?';
      else start = v[i - 1].back();
      if (i == N - 1) end = '?';
      else end = v[i + 1][0];
      break;
    }
  }

  cin >> M;
  for (int i = 0;i < M;i++) {
    string s;
    cin >> s;
    if (( start == '?' || start == s[0] ) && ( end == '?' || end == s.back() )) {
      if (st.find(s) == st.end()) {
        cout << s;
        return;
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
