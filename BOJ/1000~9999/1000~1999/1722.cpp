#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

// a번째 수열은 어떤 모습을 하고 있는가?
// i번째 자리에 어떤 수가 들어갈지는 ( a % fact(i + 1) ) / fact(a) 로 나타난다.

// 예: 3 1 2 4 의 수열은 몇 번째 수열인가?
//
// 답: 첫 번째 자리에 3이 들어가므로 1 x x x, 2 x x x 와 같은 순열 모두 패스
// 이때 1 x x x 순열의 개수는 fact(3)개
// 2 x x x 도 마찬가지
// 따라서 n = 4일 때 첫 번째 수가 3인 수열의 번호는 fact(3)*2+1 부터 시작
//
// 같은 논리를 두 번째 자리, 세 번째 자리... 이어나가면 되는데...
// 이미 쓴 수를 피해야 한다! used 배열을 통해 반복하면서 회피함

// ...와 같은 아이디어로 문제 해결 가능

ll fact(int n) {
  ll res = 1;
  for (int i = 2;i <= n;i++)
    res *= i;
  return res;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<bool> used(n + 1);
  if (q == 1) {
    ll a;
    cin >> a;
    a--;
    for (int i = n - 1;i >= 0;i--) {
      int qt = ( a % fact(i + 1) ) / fact(i);
      int cnt = 0;
      for (int j = 1;j <= n;j++) {
        if (!used[j])
          cnt++;
        if (cnt > qt) {
          used[j] = true;
          cout << j << ' ';
          break;
        }
      }
    }
  }
  else if (q == 2) {
    ll ans = 0;
    for (int i = n - 1;i >= 0;i--) {
      int inp, cnt = 0;
      cin >> inp;
      for (int j = 1;j < inp;j++)
        if (!used[j])
          cnt++;
      used[inp] = true;
      ans += fact(i) * cnt;
    }
    cout << ans + 1;
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
