#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lca(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  // FastIO
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);


  int testcase = 200000;
  cin >> testcase;
  while (testcase--) {
    ll n;
    cin >> n;
    ll prod = 0, a, b;
    for (ll i = n / 2; i > 0; i--) {
      ll l = lca(i, n - i);
      if (prod < l) {
        prod = l;
        a = i;
        b = n - i;
      }
    }

    if (n == 6) {
      cout << "2 3 1 5 4 1" << endl;
      cout << "4 6" << endl;
      continue;
    }

    if (prod < n) {
      for (int i = 0; i < n - 1; i++) {
        cout << i + 2 << ' ';
      }
      cout << 1 << endl;
      cout << 1 << ' ' << 2 << endl;
    }
    else {
      for (int i = 0; i < a - 1; i++) {
        cout << i + 2 << ' ';
      }
      cout << 1 << ' ';
      for (int i = 0; i < b - 1; i++) {
        cout << a + i + 2 << ' ';
      }
      cout << a + 1 << endl;
      cout << 1 << ' ' << a + 1 << endl;
    }
  }

  return 0;
}
