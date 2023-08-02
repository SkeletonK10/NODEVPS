#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

int arr[49][49];

void solve() {
  int n, m;
  vector<int> v;
  cin >> n >> m;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++)
      cin >> arr[i][j];
  }
  for (int i = 0;i < n / 2;i++) {
    int t = n - i * 2 - 1;
    for (int j = 0;j < t;j++) {
      if (arr[i][i + j])
        v.push_back(arr[i][i + j]);
    }
    for (int j = 0;j < t;j++) {
      if (arr[i + j][i + t])
        v.push_back(arr[i + j][i + t]);
    }
    for (int j = 0;j < t;j++) {
      if (arr[i + t][i + t - j])
        v.push_back(arr[i + t][i + t - j]);
    }
    for (int j = 0;j < t;j++) {
      if (arr[i + t - j][i])
        v.push_back(arr[i + t - j][i]);
    }
  }
  reverse(all(v));

  int ans = 0;
  while (m--) {
    // cout << "----------------------------------------" << endl;
    int type, range;
    cin >> type >> range;
    if (type == 1)
      for (int i = 1;i <= range;i++)
        if (v.size() > i * ( 4 * i + 3 ) - 1)
          v[i * ( 4 * i + 3 ) - 1] = 0;
    if (type == 2)
      for (int i = 1;i <= range;i++)
        if (v.size() > i * ( 4 * i - 1 ) - 1)
          v[i * ( 4 * i - 1 ) - 1] = 0;
    if (type == 3)
      for (int i = 1;i <= range;i++)
        if (v.size() > i * ( 4 * i - 3 ) - 1)
          v[i * ( 4 * i - 3 ) - 1] = 0;
    if (type == 4)
      for (int i = 1;i <= range;i++)
        if (v.size() > i * ( 4 * i + 1 ) - 1)
          v[i * ( 4 * i + 1 ) - 1] = 0;

    vector<int> temp;
    for (int& i : v)
      if (i != 0)
        temp.push_back(i);
    v = temp;

    bool judge = true;
    while (judge) {
      judge = false;
      int sz = v.size(), prev = 0, cnt = 0;
      vector<bool> isExplode(sz);
      for (int i = 0;i < sz;i++) {
        if (prev != v[i]) {
          if (cnt >= 4) {
            ans += prev * cnt;
            for (int j = i - 1;j >= i - cnt;j--)
              isExplode[j] = true;
            judge = true;
          }
          prev = v[i];
          cnt = 1;
        }
        else {
          cnt++;
        }
      }
      if (cnt >= 4) {
        ans += prev * cnt;
        for (int j = sz - 1;j >= sz - cnt;j--)
          isExplode[j] = true;
        judge = true;
      }
      temp.clear();
      for (int i = 0;i < sz;i++)
        if (!isExplode[i])
          temp.push_back(v[i]);
      v = temp;
    }

    int prev = 0, cnt = 0;
    temp.clear();
    for (int i = 0;i < v.size();i++) {
      if (prev != v[i]) {
        if (prev != 0) {
          temp.push_back(cnt);
          temp.push_back(prev);
        }
        prev = v[i];
        cnt = 1;
      }
      else {
        cnt++;
      }
    }
    if (cnt) {
      temp.push_back(cnt);
      temp.push_back(prev);
    }
    v = { temp.begin(), min(temp.end(), temp.begin() + n * n - 1) };
    // for (int i : v)
    //   cout << i << ' ';
    // cout << endl;
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
