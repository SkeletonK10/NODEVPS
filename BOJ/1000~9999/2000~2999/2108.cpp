#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

// counter 배열을 활용해 최빈값 구함
// 2번째로 작은 값을 구하기 위해 isTwo를 토글로 켜 준 후 유지한다.

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