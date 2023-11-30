#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n), mp(1000001);  // mp: 제한이 10^6이므로 벡터로 처리 가능
  for (int& i : v) {
    cin >> i;
    mp[i]++;
  }

  // 약수 찾기
  for (int& i : v) {
    int ans = 0;
    for (int j = 1; j * j <= i;j++) {
      if (i % j == 0) {
        ans += mp[j];

        //제곱수만 거르기
        if (j * j != i)
          ans += mp[i / j];
      }
    }
    // 중요! 이때까지 센 값에는 자기 자신도 포함되므로 -1이 필요함.
    cout << ans - 1 << endl;
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
