#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  map<char, int> mp;
  for (char i = 2;i <= 9;i++)
    mp['0' + i] = i;
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 14;

  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0;i < n;i++)
    cin >> v[i];

  int ans = 100;
  vector<int> priority = { 1, 2, 3, 4 };
  mp['s'] = 0;
  mp['h'] = 1;
  mp['d'] = 2;
  mp['c'] = 3;
  do {
    for (int order = 0; order < ( 1 << 4 );order++) {
      vector<int> seq, dp(1);
      for (int i = 0;i < n;i++) {
        char num = v[i][0];
        char suit = v[i][1];
        int ordered_num = mp[num];
        if (order & ( 1 << mp[suit] ))
          ordered_num *= -1;
        int mapped = priority[mp[suit]] * 100 + ordered_num;

        auto lis_loc = lower_bound(all(dp), mapped);
        if (lis_loc == dp.end())
          dp.push_back(mapped);
        else
          *lis_loc = mapped;
        // cout << mapped << ' ';
      }
      ans = min(ans, n - (int)dp.size() + 1);
      // cout << ans << endl;
    }
  } while (next_permutation(all(priority)));
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
