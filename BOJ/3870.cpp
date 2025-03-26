#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

int rem10[100001];
vector<int> a;

void preprocess(int n, int s, int w, int q) {
  a.resize(n);
  int g = s;
  for (int i = 0; i < n; i++) {
    a[i] = ( g / 7 ) % 10;
    if (g % 2 == 0) { g = ( g / 2 ); }
    else { g = ( g / 2 ) ^ w; }
  }
  reverse(a.begin(), a.end());
  int acc = 1;
  for (int i = 0;i < n;i++) {
    rem10[i] = acc;
    acc = ( acc * 10 ) % q;
  }
}

void solve() {
  while (true) {
    int n, s, w, q;
    cin >> n >> s >> w >> q;
    if (n == 0 && s == 0 && w == 0 && q == 0)
      break;
    preprocess(n, s, w, q);
    int ans = 0;
    if (10 % q == 0) {
      vector<int> zero(n);
      zero[n - 1] = a[n - 1] ? 0 : 1;
      for (int i = n - 2;i >= 0;i--) {
        zero[i] = zero[i + 1] + ( a[i] ? 0 : 1 );
      }
      for (int i = 0;i < n;i++) {
        if (a[i] % q == 0)
          ans += n - i - zero[i];
      }
    }
    else {
      int acc = 0;
      map<int, int> rem;
      rem[0]++;
      for (int i = 0;i < n;i++) {
        acc = ( acc + a[i] * rem10[i] ) % q;
        if (a[i])
          ans += rem[acc];
        rem[acc]++;
      }
    }
    cout << ans << endl;
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
