#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

using namespace std;

double solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n), gap;
  for (int& i : v)
    cin >> i;
  sort(all(v));

  int mxGap = 0;
  gap.push_back(v[0] - 1);
  for (int i = 0;i < n - 1;i++) {
    gap.push_back(( v[i + 1] - v[i] ) / 2);
    mxGap = max(mxGap, v[i + 1] - v[i] - 1);
  }
  gap.push_back(k - v[n - 1]);

  sort(rall(gap));

  return (double)( max(mxGap, gap[0] + gap[1]) ) / k;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  cout << fixed << setprecision(10);
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
}
