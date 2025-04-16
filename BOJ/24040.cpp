#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

bool solve() {
  ll n;
  cin >> n;
  return ( n % 9 == 0 ) || ( n % 3 == 2 );
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    if (solve())
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
