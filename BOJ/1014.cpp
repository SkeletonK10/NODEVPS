#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> field(n + 1);  // 입력 받기용 string 배열
  int dp[11][1024] = { 0 };

  for (int i = 1;i <= n;i++)
    cin >> field[i];

  int ans = 0;
  for (int i = 1;i <= n;i++) {
    for (int j = 0; j < ( 1 << m );j++) {  // 한 row에 대한 모든 경우의 수 순회
      bool rowJudge = true;                // row 자체의 제한조건 살펴보기
      for (int k = 0;k < m - 1;k++)
        if (( j & ( 1 << k ) ) && ( j & ( 1 << ( k + 1 ) ) ))  // 앉는 자리가 연속되는지?
          rowJudge = false;
      for (int k = 0;k < m;k++)
        if (( j & ( 1 << k ) ) && field[i][k] == 'x')  // 부순 책상에 앉는지?
          rowJudge = false;

      if (!rowJudge)
        continue;

      int cnt = 0;
      for (int k = 0;k < m;k++)
        cnt += ( j & ( 1 << k ) ) ? 1 : 0;  // 이번 row에서 앉은 학생 수

      for (int k = 0;k < ( 1 << m );k++) {  // 이전 row에 대한 모든 경우의 수 순회
        bool judge = true;

        // 바로 앞은 상관없으니 대각선 앞쪽 두 개만 겹치는지 검사
        for (int l = 0;l < m - 1;l++)
          if (( j & ( 1 << l ) ) && ( k & ( 1 << ( l + 1 ) ) ))
            judge = false;
        for (int l = 1;l < m;l++)
          if (( j & ( 1 << l ) ) && ( k & ( 1 << ( l - 1 ) ) ))
            judge = false;

        // 이번 row의 배열이 j일 때, 이전 row까지 있을 수 있었던 최대 학생 수 업데이트
        if (judge) {
          dp[i][j] = max(dp[i][j], dp[i - 1][k]);
        }
      }
      dp[i][j] += cnt;  // j가 가능한 배열이고, 이전까지 있을 수 있었던 최대 학생 업데이트 후 덧셈
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
