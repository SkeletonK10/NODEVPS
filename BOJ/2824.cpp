//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9;
const int SZ = 400000;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

vector<ll> prime;
bool isModed = false;

void preprocess() {
  vector<bool> isPrime(SZ, true);
  for (int i = 2;i < SZ;i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = 2;i * j < SZ;j++)
        isPrime[i * j] = false;
    }
  }
}

void factorize(int n, map<ll, int>& m) {
  int i = 0;
  while (n > 1 && i < prime.size()) {
    while (n % prime[i] == 0) {
      n /= prime[i];
      m[prime[i]]++;
    }
    i++;
  }
  if (n != 1)
    m[n]++;
}

ll powAndMod(ll a, int exp) {
  ll res = 1;
  while (exp) {
    if (exp & 1) {
      res *= a;
      if (res >= MOD) {
        isModed = true;
        res %= MOD;
      }
      res %= MOD;
      exp--;
    }
    else {
      a *= a;
      if (a >= MOD) {
        isModed = true;
        a %= MOD;
      }
      exp /= 2;
    }
  }
  return res;
}

void solve() {
  preprocess();
  map<ll, int> a, b;
  int N;
  cin >> N;
  for (int i = 0;i < N;i++) {
    int temp;
    cin >> temp;
    factorize(temp, a);
  }
  int M;
  cin >> M;
  for (int i = 0;i < M;i++) {
    int temp;
    cin >> temp;
    factorize(temp, b);
  }
  ll ans = 1;
  for (auto [p, ae] : a) {
    int exp = min(ae, b[p]);
    ans = ( ans * powAndMod(p, exp) );
    if (ans >= MOD) {
      isModed = true;
      ans %= MOD;
    }
  }

  if (isModed) {
    cout.width(9);
    cout.fill('0');
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
