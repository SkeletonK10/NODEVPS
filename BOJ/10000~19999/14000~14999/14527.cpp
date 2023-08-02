#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define compress(x) sort(all(x)); x.erase(unique(all(x)),(x).end())
#define endl '\n'
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

bool comp(pii& a, pii& b) { return a.SS < b.SS; }

int main()
{
  FastIO;
	int T = 1;
	//cin >> T;
	while (T--)
	{
    int n, ans = 0;
    cin >> n;
    vector<pii> v(n);
    int front = 0, rear = n - 1;
    for (pii& i : v)
      cin >> i.FF >> i.SS;
    
    sort(all(v), comp);

    while (front < rear)
    {
      int p = min(v[front].FF, v[rear].FF);
      if (p > 0)
      {
        ans = max(ans, v[front].SS + v[rear].SS);
        v[front].FF -= p;
        v[rear].FF -= p;
      }
      if (v[front].FF <= 0) front++;
      if (v[rear].FF <= 0) rear--;
    }
    if (front == rear)
      ans = max(ans, v[front].FF * 2);
    cout << ans;
  }
}