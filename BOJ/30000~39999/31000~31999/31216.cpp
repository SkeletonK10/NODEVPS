#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
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
const int SZ = 318137;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

bool isComp[SZ + 1];
vector<int> prime(1);

void preprocess() {
  for (int i = 2;i <= SZ;i++) {
    if (!isComp[i]) {
      prime.push_back(i);
      for (int j = 2;i * j <= SZ; j++) {
        isComp[i * j] = true;
      }
    }
  }
}

void solve() {
  preprocess();
  int q;
  cin >> q;
  while (q--) {
    int temp;
    cin >> temp;
    cout << prime[prime[temp]] << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
