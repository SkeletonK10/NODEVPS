#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

// 어떤 컴퓨터를 시작점으로 하여 그래프 탐색 (여기서는 BFS) 진행.
// 모든 컴퓨터에 대해 반복하여 최댓값을 찾는다.
// 최댓값이 갱신될 때 정답 컴퓨터 리스트도 같이 갱신해야함!

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    adj[e].push_back(s);
  }

  vector<int> ans;
  int ansCnt = 0;
  for (int i = 1;i <= n;i++) {
    vector<bool> vst(n + 1);
    queue<int> q;
    int in = 1;
    q.push(i);
    vst[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int& next : adj[cur]) {
        if (!vst[next]) {
          in++;
          q.push(next);
          vst[next] = true;
        }
      }
    }
    if (ansCnt < in) {
      ansCnt = in;
      ans = { i };
    }
    // 같을 때 정답 리스트에 추가
    // 이미 오름차순으로 순회 중이기 때문에 따로 정렬할 필요는 없음.
    else if (ansCnt == in)
      ans.push_back(i);
  }
  for (int& i : ans)
    cout << i << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
