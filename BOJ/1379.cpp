#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

//////////////////////////////////
// TODO: 더욱 자세한 증명 필요... //
//////////////////////////////////

// GREEDY: 시작하는 시간이 빠른 강의를, 제일 빨리 끝나는 강의실에 먼저 넣는다.
// '가장 빨리 끝나는 강의'를 넣는 것으로 생각할 수도 있는데, 다음과 같은 반례를 생각해보면 좋을 듯.

// 4
// 1 0 3
// 2 0 4
// 3 3 8
// 4 4 6

// 1번, 2번 강의를 각각 1번과 2번 강의실에 넣었다 가정.
// 넣은 후 가장 빨리 끝나는 4번 강의를 1번 강의실에 넣으면 3번 강의가 들어갈 자리가 없다.

void solve() {
  int n;
  cin >> n;
  vector<tiii> v(n);
  for (auto& [s, e, i] : v)
    cin >> i >> s >> e;
  sort(all(v));

  int cnt = 1;
  vector<int> ans(n + 1);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({ 0,1 });
  for (auto& [s, e, i] : v) {
    int roomIndex;
    auto [ra, ri] = pq.top();
    if (ra > s) {
      cnt++;
      roomIndex = cnt;
    }
    else {
      pq.pop();
      roomIndex = ri;
    }
    ans[i] = roomIndex;
    pq.push({ e, roomIndex });
  }
  cout << cnt << endl;
  for (int i = 1;i <= n;i++)
    cout << ans[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
