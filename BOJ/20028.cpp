#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

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

//////Union-Find///////////////////////////////////////////

struct union_find {
  std::vector<int> arr, cnt, lb;

  union_find(int sz, std::vector<int>& l) {
    arr.resize(sz * 2 + 1);
    cnt.resize(sz * 2 + 1);
    for (int i = 1; i <= sz; i++) {
      arr[i] = i;
      cnt[i] = 1;
    }
    for (int i = sz + 1;i <= sz * 2;i++)
      arr[i] = i;
    lb = { all(l) };
  }

  int find(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = find(arr[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      arr[y] = x;
      cnt[x] += cnt[y];
      lb[x] = std::min(lb[x], lb[y]);
    }
  }

  int count(int x) {
    return cnt[find(x)];
  }

  int label(int x) {
    return lb[find(x)];
  }
};

///////////////////////////////////////////////////////////

using namespace std;


void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> label(2 * n + 1, INF);
  vector<vector<int>> adj(n + 1);
  map<int, ll> mp1, mp2;
  for (int i = 1;i <= n;i++)
    cin >> label[i];
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  vector<int> vst(n + 1, -1);
  union_find uf(n, label);
  ll ans = 0;
  for (int i = 1;i <= n;i++) {
    if (vst[i] == -1) {
      vst[i] = 0;
      queue<pii> q;
      q.push({ i + n,i });
      while (!q.empty()) {
        auto [parent, cur] = q.front();
        q.pop();
        int nDist = vst[cur] + 1;
        for (int& next : adj[cur]) {
          uf.merge(parent, next);
          if (vst[next] == -1) {
            vst[next] = nDist;
            q.push({ cur, next });
          }
        }
      }
      ll cnt1 = uf.count(i);
      ans += ( cnt1 - 1 ) * cnt1 / 2;
      if (uf.find(i) != uf.find(i + n)) {
        ll cnt2 = uf.count(i + n);
        ans += ( cnt2 - 1 ) * cnt2 / 2;
      }
    }
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
