#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  int sz = s.size();
  vector<int> ans(sz), v(sz);
  bool judge;

  for (int i = 0;i < sz;i++)
    ans[i] = i;

  for (int i = 1;i <= n;i++)
  {
    judge = true;
    for (int j = 0;j < sz;j += 2)
      v[j / 2] = ans[j];
    for (int j = 1;j < sz;j += 2)
      v[( sz * 2 - j ) / 2] = ans[j];
    ans = { all(v) };
    // for (int& i : ans) cout << s[i];
    // cout << endl;
    for (int j = 0;j < sz;j++)
      if (ans[j] != j) judge = false;
    if (judge) i = ( n / i ) * i;
  }
  for (int& i : ans) cout << s[i];
}

int main()
{
  FastIO;
	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
    solve();
  }
}