//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

vector<int> adj, route;
vector<bool> vst, fin;

int findCycle(int axis) {
  int sz = route.size();
  for (int i = 0;i < sz;i++)
    if (route[i] == axis)
      return sz - i;
  return -1;
}

int dfs(int cur) {
  int ans = 0;
  vst[cur] = true;
  route.push_back(cur);
  int nxt = adj[cur];
  if (!fin[nxt] && vst[nxt]) {
    ans += findCycle(nxt);
  }
  else if (!vst[nxt])
    ans += dfs(nxt);
  route.pop_back();
  fin[cur] = true;
  return ans;
}

int solve() {
  int N;
  cin >> N;
  adj.resize(N + 1);
  vst = fin = vector<bool>(N + 1);
  for (int i = 1;i <= N;i++)
    cin >> adj[i];

  int ans = 0;
  for (int i = 1;i <= N;i++) {
    if (!vst[i])
      ans += dfs(i);
  }
  return N - ans;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve() << endl;
  }
}
