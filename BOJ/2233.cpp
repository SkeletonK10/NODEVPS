#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

// 스택을 활용해 0101 string에서 트리를 재구성한다.
// 2개의 사과가 썩었기 때문에 이들의 LCS를 자르면 됨.
// 이후는 간단한 LCS 구하기. O(n) 으로 충분히 가능하다

void solve() {
  int n, x, y;
  string s;
  cin >> n >> s >> x >> y;
  vector<int>
    parent(n + 1),  // i번째 정점의 부모 (재구성한 실제 트리)
    in(n + 1),  // 정답 출력용 배열 (i번째 정점의 0 위치)
    out(n + 1),  // 정답 출력용 배열 (i번째 정점의 1 위치)
    depth(n + 1);  // i번째 정점의 깊이 (루트 기준)
  stack<int> st;
  st.push(0);

  int cnt = 0;
  for (int i = 0;i < s.length();i++) {
    if (s[i] == '0') {
      cnt++;
      depth[cnt] = st.size();
      parent[cnt] = st.top();
      st.push(cnt);
      in[cnt] = i + 1;
    }
    else {
      out[st.top()] = i + 1;
      st.pop();
    }
  }

  for (int i = 1;i <= n;i++) {
    if (x == in[i])
      x = i;
    if (x == out[i])
      x = i;
    if (y == in[i])
      y = i;
    if (y == out[i])
      y = i;
  }

  if (depth[x] > depth[y])
    swap(x, y);
  while (depth[x] < depth[y])
    y = parent[y];
  while (x != y) {
    x = parent[x];
    y = parent[y];
  }
  cout << in[x] << ' ' << out[x];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
