#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int mx = -INF, mn = INF;
	for (int i = 0;i < n - 1;i++) {
		int temp;
		cin >> temp;
		mx = max(mx, temp);
		mn = min(mn, temp);
	}
	if (mn == a && mx == b)
		for (int i = a; i <= b;i++)
			cout << i << endl;
	else if (mx == b)
		cout << a << endl;
	else if (mn == a)
		cout << b << endl;
	else
		cout << -1 << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
