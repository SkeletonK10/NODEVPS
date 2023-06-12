#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve()
{
  int n;
  ll k;
  cin >> n;
  bool judge = false;
  vector<ll> v(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> v[i];
  cin >> k;
  if (v[1] == k) judge = true;
  for (int i = 2;i <= n;i++)
  {
    ll a = k * ( i - 1 );
    ll b = k * i;
    if (v[i - 1] >= a && v[i] <= b) judge = true;
    if (v[i - 1] <= a && v[i] >= b) judge = true;
  }
  cout << ( judge ? "T" : "F" ) << endl;
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