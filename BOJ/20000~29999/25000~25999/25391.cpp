#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

bool compR(pii& a, pii& b) { return a.FF > b.FF; }
bool compRSS(pii& a, pii& b) { return a.SS > b.SS; }

int main()
{
  FastIO;
	int T = 1;
	//cin >> T;
	while (T--)
	{
    int n, m, k;
    ll ans = 0;
    cin >> n >> m >> k;
    vector<pii> v(n);
    for (pii& i : v)
      cin >> i.FF >> i.SS;
    
    sort(all(v), compRSS);
    
    for (int i = 0;i < k;i++)
      ans += v[i].FF;

    sort(v.begin() + k, v.end(), compR);

    for (int i = k;i < k + m;i++)
      ans += v[i].FF;
    
    cout << ans;
  }
}