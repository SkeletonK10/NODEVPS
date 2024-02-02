#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, k, p;
  cin >> n >> k >> p;
  int hN, hP;
  for (int i = 0;i < 30;i++) {
    if (( 1 << i ) & n)
      hN = i;
    if (( 1 << i ) & p)
      hP = i;
  }
  hN++; hP++;

  if (hP > k) {
    cout << -1;
    return;
  }
  int childNum = 0;
  childNum += 1 << ( hN - hP );
  childNum -= 2;   // 원래 2^k - 1 꼴이고 자기 자신도 포함되어 있으므로 둘 다 빼줌
  if (( n >> ( hN - hP ) ) == p)
    childNum += ( n & ( ( 1 << ( hN - hP ) ) - 1 ) ) + 1;
  else if (( n >> ( hN - hP ) ) > p)
    childNum += 1 << ( hN - hP );

  if (childNum > n - k) {
    cout << -1;
    return;
  }

  int cur = hP;
  int root = 1;
  int tail = n;
  for (int i = 1;i <= n;i++) {
    if (i == p) {
      cout << k << endl;
      continue;
    }
    int tempP = p;
    while (tempP) {
      if (tempP == i) {
        cout << root++ << endl;
        break;
      }
      tempP >>= 1;
    }
    if (tempP) continue;

    int tempI = i;
    while (tempI) {
      if (tempI == p) {
        cout << tail-- << endl;
        break;
      }
      tempI >>= 1;
    }
    if (tempI) continue;

    if (cur == k) cur++;
    cout << cur++ << endl;
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
