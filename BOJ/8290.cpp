#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

void solve() {
  int n;
  cin >> n;
  if (n < 4 || n % 2) {
    cout << "NIE";
    return;
  }

  vector<int> v(n / 4, 2);
  if (n % 4)
    v.push_back(0);

  vector<pii> ans;
  int x = 0, y = 0;
  for (;x < v.size();) {
    ans.push_back({ x, y });
    ans.push_back({ x + 1, y });
    y += v[x];
    x++;
  }

  bool isBack2 = ( v.back() == 0 );
  y += 2;
  ans.push_back({ x, y });
  x -= isBack2 ? 2 : 1;
  ans.push_back({ x, y });

  for (;x > 0;) {
    y -= v[x];
    x--;
    ans.push_back({ x + 1, y });
    ans.push_back({ x, y });
  }

  for (pii& i : ans) {
    cout << i.FF << ' ' << i.SS << endl;
  }
}

int main() {
  FastIO;
	int testcase = 1;
	//cin >> testcase;
	while (testcase--) {
    solve();
  }
}