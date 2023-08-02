#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

int app[8001];

int main()
{
  FastIO;
  int n;
  double avg = 0;
  int mxApp;
  int mx = 0;
  bool isTwo = false;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
  {
    cin >> i;
    app[i + 4000]++;
    avg += i + 4000;
  }
  for (int i = -4000; i <= 4000; i++)
  {
    if (mx < app[i + 4000])
    {
      mx = app[i + 4000];
      mxApp = i;
      isTwo = false;
    }
    else if (mx == app[i + 4000] && !isTwo)
    {
      isTwo = true;
      mxApp = i;
    }
  }
  avg /= n;
  sort(v.begin(), v.end());
  cout << fixed << setprecision(0) << round(avg) - 4000 << endl;
  cout << v[n / 2] << endl;
  cout << mxApp << endl;
  cout << v[n - 1] - v[0];
}