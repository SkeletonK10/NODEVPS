#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void checkAndInsert(set<int>& s, int a, int b) {
  if (a < b) swap(a, b);
  // cout << a + b << ' ' << a - b << ' ' << a * b << ' ';
  // if (b > 0) cout << a / b << endl;
  // else cout << endl;
  s.insert(a + b);
  s.insert(a - b);
  s.insert(a * b);
  if (b > 0)
    s.insert(a / b);
}

void solve() {
  int k, n;
  cin >> k >> n;

  vector<set<int>> s(9);
  for (int a = k, i = 1; i <= 6; a = a * 10 + k, i++) {
    s[i].insert(a);
  }

  for (int i = 2;i <= 8;i++) {
    // cout << "SET " << i << ": " << endl;
    for (int j = 1;j <= i - j;j++) {
      for (int a : s[j]) {
        for (int b : s[i - j]) {
          checkAndInsert(s[i], a, b);
        }
      }
    }
  }
  for (int i = 0;i < n;i++) {
    int input;
    bool flag = false;
    cin >> input;
    for (int i = 1;i <= 8;i++) {
      if (s[i].find(input) != s[i].end()) {
        cout << i << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << "NO" << endl;
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
