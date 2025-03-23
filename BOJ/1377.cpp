#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
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

// 버블 소트 중에 중요한 사실:
// 낮은 숫자를 내리는 과정은 반복마다 최대 한 번 수행된다
// 있어야 할 위치보다 높이 있는 숫자 중 최댓값을 구하면 되는 문제

void solve() {
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0;i < n;i++) {
    cin >> v[i].FF;
    v[i].SS = i;
  }
  sort(all(v));
  int ans = 0;
  for (int i = 0;i < n;i++)
    ans = min(ans, i - v[i].SS);
  cout << -ans + 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
