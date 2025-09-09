//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  deque<char> dq;
  int N;
  cin >> N;
  for (int i = 0;i < N;i++) {
    string s;
    cin >> s;
    char c = s[0];

    int sameCnt = 0;
    while (!dq.empty() && dq.front() == c) {
      dq.pop_front();
      sameCnt++;
    }

    if (!dq.empty()) {
      if (dq.front() < c)
        dq.push_back(c);
      else
        dq.push_front(c);
    }
    else {
      dq.push_back(c);
    }

    while (sameCnt--)
      dq.push_front(c);
  }
  while (!dq.empty()) {
    cout << dq.front();
    dq.pop_front();
  }
  cout << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
