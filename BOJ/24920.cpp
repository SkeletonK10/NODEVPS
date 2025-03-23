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

int solve() {
  int d, n, u;
  cin >> d >> n >> u;

  vector<int> dt(d), dn(d), dx(d), uv(n);
  for (int i = 0;i < d;i++)
    cin >> dt[i] >> dn[i] >> dx[i];
  for (int& i : uv)
    cin >> i;

  int di = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  // cout << endl << "START DEBUGGING" << endl;
  for (int i = 0;i < n;i++) {
    while (di < d && dt[di] <= uv[i]) {
      // cout << "Time " << dt[di] << " entering " << di << "th delivery\n";
      pq.push({ dt[di] + dx[di], di });
      di++;
    }

    while (!pq.empty() && pq.top().FF <= uv[i]) {
      // cout << "Time " << pq.top().FF << " expiring " << pq.top().SS << "th delivery\n";
      pq.pop();
    }
    int fresh = 0;
    while (fresh < u) {
      if (pq.empty())
        return i;
      int top = pq.top().SS;
      // cout << "Time " << uv[i] << " using " << top << "th delivery\n";
      int use = min(dn[top], u - fresh);
      fresh += use;
      dn[top] -= use;
      if (!dn[top])
        pq.pop();
    }
  }
  return n;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1; tc <= testcase;tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
}
