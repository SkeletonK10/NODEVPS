//////New Type Definition////////////////////////////////////////////////////////////////

#include <vector>
typedef long long ll;
typedef std::pair<int, int> pii;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  queue<int> ready;

  ll sum = 0;
  for (int i = 1;i <= N;i++) {
    int temp;
    cin >> temp;
    sum += temp;
    if (temp)
      pq.push({ temp, i });
    else
      ready.push(i);
  }

  if (sum != N - 1) {
    cout << -1;
    return;
  }

  for (int i = 0;i < 2 * N - 1;i++) {
    if (i % 2) {
      auto [cnt, idx] = pq.top();
      pq.pop();
      cout << idx << endl;
      cnt--;
      if (cnt)
        pq.push({ cnt, idx });
      else
        ready.push(idx);
    }
    else {
      cout << ready.front() << endl;
      ready.pop();
    }
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
