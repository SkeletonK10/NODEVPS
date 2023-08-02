#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

map<string, int> bfs() {
  queue<string> q;
  map<string, int> mp;
  vector<vector<int>> transform = {
    {1,3},
    {0,2,4},
    {1,5},
    {0,4,6},
    {1,3,5,7},
    {2,4,8},
    {3,7},
    {4,6,8},
    {5,7} };
  q.push("123456780");
  mp["123456780"] = 1;
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    int oLoc;
    for (int i = 0;i < 9;i++)
      if (cur[i] == '0')
        oLoc = i;
    for (int next : transform[oLoc]) {
      string s = cur;
      s[oLoc] = cur[next];
      s[next] = '0';
      if (!mp[s]) {
        mp[s] = mp[cur] + 1;
        q.push(s);
      }
    }
  }
  return mp;
}

void solve(map<string, int>& mp) {
  string s;
  for (int i = 0;i < 9;i++) {
    string t;
    cin >> t;
    s += t;
  }
  cout << mp[s] - 1 << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  map<string, int> mp = bfs();
  for (int tc = 1;tc <= testcase;tc++) {
    solve(mp);
  }
}
