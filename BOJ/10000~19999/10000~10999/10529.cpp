#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int n, sz;
vector<string> v;
string res;
vector<ll> cnt(26), resCnt(26);
vector<int> mp, leftmost, value;

vector<bool> used(10);

int dfs(int depth) {
  if (depth == sz) {
    bool judge = true;
    for (int i = 0;i < n;i++)
      if (!value[leftmost[i]])
        judge = false;
    if (!judge)
      return 0;
    ll left = 0, right = 0;
    for (int i = 0;i < sz;i++)
      left += cnt[mp[i]] * value[i];
    for (int i = 0;i < sz;i++)
      right += resCnt[mp[i]] * value[i];

    return left == right ? 1 : 0;
  }

  int res = 0;
  for (int i = 0;i < 10;i++) {
    if (!used[i]) {
      used[i] = true;
      value.push_back(i);
      res += dfs(depth + 1);
      value.pop_back();
      used[i] = false;
    }
  }
  return res;
}

void solve() {
  cin >> n;
  v.resize(n - 1);
  for (int i = 0;i < n - 1;i++)
    cin >> v[i];
  cin >> res;
  for (string& s : v) {
    leftmost.push_back(s[0] - 'A');
    reverse(all(s));
    ll temp = 1;
    for (int i = 0;i < s.length();i++) {
      cnt[s[i] - 'A'] += temp;
      temp *= 10;
    }
  }
  leftmost.push_back(res[0] - 'A');
  reverse(all(res));
  ll temp = 1;
  for (int i = 0;i < res.length();i++) {
    resCnt[res[i] - 'A'] += temp;
    temp *= 10;
  }

  for (int i = 0;i < 26;i++)
    if (cnt[i] || resCnt[i])
      mp.push_back(i);
  sz = mp.size();

  for (int i = 0;i < sz;i++)
    for (int& j : leftmost)
      if (j == mp[i])
        j = i;

  cout << dfs(0);
}


int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
