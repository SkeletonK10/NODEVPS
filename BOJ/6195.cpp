#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    pq.push(temp);
  }
  ll ans = 0;
  for (int i = 0;i < n - 1;i++) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += a + b;
    pq.push(a + b);
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
