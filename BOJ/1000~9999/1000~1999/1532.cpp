#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

// Solution

// 부족한 동화나 금화는 은화로밖에 충당할 수 없다.
// 먼저 은화를 빌려와서 동화나 금화 충당
// 이후 부족한 은화를 금화나 동화를 이용해 채운다
// 은화가 부족한데 부족분 채울 금화나 동화가 없으면 -1, 있으면 거래하고 횟수 출력
// 금화와 동화가 있다면 금화부터 거래 (은화를 9개씩 채우므로)

// 이미 거래한 화폐를 또 거래할 일은 없음.
// 딱 맞춰 거래하기 때문


void solve() {
  int g1, s1, b1, g2, s2, b2;
  int ans = 0;
  cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
  if (b1 < b2) {
    int trans = ( b2 - b1 - 1 ) / 9 + 1;
    s1 -= trans;
    b1 += trans * 9;
    ans += trans;
  }
  if (g1 < g2) {
    int trans = g2 - g1;
    s1 -= trans * 11;
    g1 += trans;
    ans += trans;
  }
  if (s1 < s2) {
    int need = s2 - s1;
    int gAfford = ( g1 - g2 ) * 9, bAfford = ( b1 - b2 ) / 11;
    int afford = gAfford + bAfford;
    if (need > afford) {
      cout << -1;
      return;
    }
    int gTrans = min(( need - 1 ) / 9 + 1, gAfford / 9);
    s1 += gTrans * 9;
    ans += gTrans;
    if (s1 < s2)
      ans += s2 - s1;
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
