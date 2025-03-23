#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

// 상자가 위에서 내려올 때 겹치는가? 
// 겹치기 판정... 귀찮다
// xo: x좌표에서 겹치는가?
// yo: y좌표에서 겹치는가?
// 둘 다 겹치면 겹치는 거임.
bool overlap(pair<pii, pii>& a, pair<pii, pii>& b) {
  bool xo = false, yo = false;
  if (a.FF.FF == b.FF.FF)
    xo = true;
  if (a.FF.FF < b.FF.FF && a.SS.FF > b.FF.FF)
    xo = true;
  if (b.FF.FF < a.FF.FF && b.SS.FF > a.FF.FF)
    xo = true;

  if (a.FF.SS == b.FF.SS)
    yo = true;
  if (a.FF.SS < b.FF.SS && a.SS.SS > b.FF.SS)
    yo = true;
  if (b.FF.SS < a.FF.SS && b.SS.SS > a.FF.SS)
    yo = true;
  return xo && yo;
}

void solve() {
  int a, b, n;
  cin >> a >> b >> n;
  vector<pair<pii, pii>> v(n + 1);  // 각각의 상자 좌표 (x1, y1), (x2, y2)
  vector<int>
    c(n + 1), // 각각 상자의 높이
    dp(n + 1); // dp배열 (n번째 상자까지 쌓았을 때 얼마나 높이 올라가는가?)
  for (int i = 1;i <= n;i++) {
    int lx, ly, lz, px, py;
    cin >> lx >> ly >> lz >> px >> py;
    v[i] = { {px, py}, {px + lx, py + ly} };
    c[i] = lz;
  }
  int ans = 0;
  // 2중for문으로, 겹쳐지면 dp값을 업데이트해줌.
  for (int i = 1;i <= n;i++) {
    dp[i] = c[i];
    for (int j = 1;j < i;j++)
      if (overlap(v[i], v[j]))
        dp[i] = max(dp[i], dp[j] + c[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
