#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

map<string, string> bfs() {
  queue<string> q;
  map<string, string> mp;
  vector<vector<int>> transform = {
    {1,5},
    {0,2,6},
    {1,3},
    {2,4},
    {3,5,6},
    {0,4},
    {1,4} };
  q.push("ABCDEFO");
  mp["ABCDEFO"] = "O";
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    int oLoc;
    for (int i = 0;i < 7;i++)
      if (cur[i] == 'O')
        oLoc = i;
    for (int next : transform[oLoc]) {
      string s = cur;
      s[oLoc] = cur[next];
      s[next] = 'O';
      if (mp[s] == "") {
        mp[s] = mp[cur] + cur[next];
        q.push(s);
      }
    }
  }
  return mp;
}

void solve(map<string, string>& mp) {
  string s;
  cin >> s;
  s += 'O';
  if (mp[s] == "")
    cout << -1 << endl;
  else {
    string ans = mp[s].substr(1);
    reverse(all(ans));
    cout << ans.length() << ' ' << ans << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  map<string, string> mp = bfs();
  for (int tc = 1;tc <= testcase;tc++) {
    solve(mp);
  }
}
