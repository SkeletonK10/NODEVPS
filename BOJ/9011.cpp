#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n), ans(n);
  vector<bool> flag(n, false);
  for (int& i : v)
    cin >> i;
  int in = n;
  while (in > 0)
  {
    stack<int> st;
    for (int i = 0;i < n;i++)
      if (v[i] == i)
        st.push(i);
    
    if (st.empty())
    {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    
    while (!st.empty())
    {
      int top = st.top();
      st.pop();
      ans[top] = in--;
      for (int i = top;i < n;i++)
      {
        v[i]++;
        if (v[i] == i)
          st.push(i);
      }
    }
  }

  for (int& i : ans)
    cout << i << ' ';
  cout << endl;
}

int main()
{
  FastIO;
	int testcase = 1;
	cin >> testcase;
	while (testcase--)
	{
    solve();
  }
}