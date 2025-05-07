//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Constants//////////////////////////////////////////////////////////////////////////

#include <cmath>
const int MOD = 1e9 + 7;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll solve() {
  ll ans = 1;
  string s;
  cin >> s;
  for (int i = 0;i < s.length();i++) {
    set<char> st;
    st.insert(s[i]);
    if (i > 0)
      st.insert(s[i - 1]);
    if (i < s.length() - 1)
      st.insert(s[i + 1]);
    ans = ans * st.size() % MOD;
  }
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
}
