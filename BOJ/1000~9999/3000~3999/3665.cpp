#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n;
  vector<int> r(n), deg(n + 1), ans;
  vector<vector<bool>> adj(n + 1, vector<bool>(n + 1));  // adj matrix
  for (int& i : r)
    cin >> i;
  
  // 순위가 더 높은 쪽에서 낮은 쪽으로 '모든 간선'을 연결
  for (int i = 0;i < n - 1;i++)
    for (int j = i + 1;j < n;j++)
      adj[r[i]][r[j]] = true;

  // 방향 바꾸기 단계.
  cin >> m;
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;

    // (방향 무시 시) 완전 그래프는 반복문 동안 유지되므로 필요 없는 코드
    // if (!adj[e][s] && !adj[s][e]) {
    //   cout << "IMPOSSIBLE" << endl;
    //   return;
    // }
    
    if (adj[e][s]) {
      adj[e][s] = false;
      adj[s][e] = true;
    }
    else {
      adj[s][e] = false;
      adj[e][s] = true;
    }
  }

  // 위상 정렬
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= n;j++)
      if (adj[i][j])
        deg[j]++;
  
  queue<int> q;
  for (int i = 1;i <= n;i++)
    if (!deg[i])
      q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    ans.push_back(cur);
    q.pop();
    for (int i = 1;i <= n;i++) {
      if (!adj[cur][i]) continue;
      deg[i]--;
      if (!deg[i]) q.push(i);
    }
  }

  // 검증 단계. 완전 그래프에서 사이클이 없는 형태는 (이 문제에서) 순위가 결정된 상황밖에 없다.
  // 따라서 이 문제에서 ?를 출력하는 상황은 존재하지 않음.
  
  // 위상 정렬의 구현에 따라 사이클이 있다면 ans에 들어가지 않은 정점이 있다는 뜻.
  // 사이클이 있다면 일관성 없는 데이터이므로 IMPOSSIBLE
  // 사이클이 없다면 유일하게 결정된 순위를 그대로 출력
  if (ans.size() != n) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  else {
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
