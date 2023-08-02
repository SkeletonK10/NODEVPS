#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

void solve() {
  int n;
  string s[9];
  cin >> n;
  for (int i = 0;i < n;i++)
    cin >> s[i];
  vector<int> p(10);
  for (int i = 0;i < 10;i++)
    p[i] = i;

  string res = "", ans;
  do {
    bool judge = true;
    for (int i = 0;i < n;i++) {
      if (s[i][0] == '<') {
        if (p[i] > p[i + 1])
          judge = false;
      }
      else {
        if (p[i] < p[i + 1])
          judge = false;
      }
    }
    if (judge) {
      string temp = "";
      for (int i = 0;i <= n;i++)
        temp += '0' + (char)p[i];
      if (res == "")
        res = temp;
      ans = temp;
    }
  } while (next_permutation(all(p)));
  cout << ans << endl << res;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
