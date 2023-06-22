#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

int dp[51][15001];

int solve(int tc) {
  dp[0][0] = tc;
  int a, k;
  set<int> st;
  cin >> a >> k;
  vector<int> v(a);
  for (int& i : v)
    cin >> i;
  sort(all(v));
  for (int i = 0;i < a - 1;i++) {
    st.insert(v[i]);
    st.insert(v[i] * 2);
    st.insert(v[i] * 3);
  }
  st.insert(v[a - 1]);
  st.insert(v[a - 1] * 2);
  st.insert(0);

  int maxScore = v[a - 1] * k * 2;
  if (a > 1)
    maxScore = max(maxScore, v[a - 2] * k * 3);
  for (int i = 1;i <= k;i++)
    for (int j = 0;j <= maxScore;j++)
      if (dp[i - 1][j] == tc)
        for (int score : st)
          if (j + score <= maxScore)
            dp[i][j + score] = tc;
  int ans = 0;
  for (int i = 0;i <= maxScore;i++)
    if (dp[k][i] == tc)
      ans++;
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Scenario #" << tc << ":" << endl;
    cout << solve(tc) << endl;
    if (tc != testcase)
      cout << endl;
  }
}
