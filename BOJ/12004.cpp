#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////Union-Find///////////////////////////////////////////

struct union_find {
  std::vector<int> arr;

  union_find(int sz) {
    arr.resize(sz + 1);
    for (int i = 1; i <= sz; i++)
      arr[i] = i;
  }

  int find(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = find(arr[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      arr[y] = x;
    }
  }
};

///////////////////////////////////////////////////////////

using namespace std;

bool adj[3001][3001];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0;i < m;i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = true;
    adj[b][a] = true;
  }

  vector<int> query(n);
  for (int& i : query)
    cin >> i;
  
  reverse(all(query));
  union_find uf(n);
  set<int> st;
  vector<bool> ans;

  for (int i : query) {
    st.insert(i);
    bool judge = true;
    for (int j : st)
      if (adj[i][j])
        uf.merge(i, j);
    for (int j : st)
      if (uf.find(i) != uf.find(j))
        judge = false;
    ans.push_back(judge);
  }
  for (int i = n - 1;i >= 0;i--)
    cout << (ans[i] ? "YES" : "NO") << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
