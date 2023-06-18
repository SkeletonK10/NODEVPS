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

ll solve(int n, int k) {
  vector<int> v(n), p(n);
  vector<bool> cycled(n);
  for (int i = 0;i < n;i++)
    v[i] = i;

  vector<vector<int>> tp(k);
  for (int i = 0;i < n;i++) {
    tp[i % k].push_back(v[i]);
  }
  int cnt = 0;
  for (int i = 0;i < k;i++) {
    for (int j = tp[i].size() - 1;j >= 0;j--)
      p[cnt++] = tp[i][j];
  }

  ll ans = 1;
  for (int i = 0;i < n;i++) {
    int cnt = 0;
    if (!cycled[i]) {
      int temp = i;
      while (!cycled[temp]) {
        cnt++;
        cycled[temp] = true;
        temp = p[temp];
      }
      ans = lcm(ans, cnt);
    }
  }
  return ans;
}

int main() {
  FastIO;
  while (true) {
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
      break;
    cout << solve(n, k) << endl;
  }
}
