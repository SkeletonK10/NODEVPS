#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 10000000;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

vector<int> minPrime(SZ + 1), parity(SZ + 1), ans(SZ + 1);

void preprocess() {
  minPrime[1] = INF;
  for (int i = 2; i * i <= SZ; i++) {
    if (minPrime[i]) continue;
    for (int j = 2; i * j <= SZ; j++)
      if (!minPrime[i * j])
        minPrime[i * j] = i;
  }
  for (int i = 1; i <= SZ; i++)
    if (!minPrime[i])
      minPrime[i] = i;

  for (int i = 2;i <= SZ;i++) {
    parity[i] = parity[i / minPrime[i]];
    ans[i] = ans[i - 1];
    if (minPrime[i / minPrime[i]] > minPrime[i]) {
      parity[i]++;
    }

    if (parity[i] % 2)
      ans[i]--;
    else
      ans[i]++;
  }
}

void solve() {
  int s, e;
  cin >> s >> e;
  cout << ans[e] - ans[s - 1] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  preprocess();
  while (testcase--) {
    solve();
  }
}
