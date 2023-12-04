#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

// 간단한 약수 판정
// n >= 10 이므로 100만개 다 나눠봐도 된다.

bool solve() {
  ll n;
  cin >> n;
  for (int i = 2;i <= 1e6;i++)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << ( solve() ? "YES" : "NO" ) << endl;
  }
}
