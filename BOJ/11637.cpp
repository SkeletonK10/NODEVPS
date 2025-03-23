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
  int n, s = 0;
  cin >> n;
  priority_queue<pii> pq;
  for (int i = 1;i <= n;i++) {
    int temp;
    cin >> temp;
    pq.push({ temp,i });
    s += temp;
  }
  auto [cnt, w] = pq.top();
  pq.pop();
  if (pq.top().FF == cnt)
    cout << "no winner" << endl;
  else if (cnt * 2 > s)
    cout << "majority winner " << w << endl;
  else
    cout << "minority winner " << w << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
