#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;
int sz, n;
vector<string> s;
bool used[21];

bool recur(vector<int>& v)
{
  if (v.size() == sz)
  {
    for (int i = 0;i < sz;i++)
    {
      for (int j = 0;j < i;j++)
      {
        if (s[v[i]][j] != s[v[j]][i])
          return false;
      }
    }
    for (int i = 0;i < sz;i++)
      cout << s[v[i]] << endl;
    return true;
  }

  for (int i = 1;i <= n;i++)
  {
    if (!used[i])
    {
      used[i] = true;
      v.push_back(i);
      if (recur(v)) return true;
      v.pop_back();
      used[i] = false;
    }
  }
  return false;
}

void solve()
{
  vector<int> v;
  cin >> sz >> n;
  s.resize(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> s[i];
  
  sort(all(s));
  
  if (recur(v)) return;
  else cout << "NONE";
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