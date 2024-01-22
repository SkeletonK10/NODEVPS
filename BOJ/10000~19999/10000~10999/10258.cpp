#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

// 풀이: 일단 맞긴 했지만...
// 먼저 100..000 꼴의 수를 생각해 보았을 때 정답은 2^(n+1)-1임: 여기까지 간단

// 1이 여러 개 있는 걸 생각해 볼 때
// 1이 짝수 개 있을 때: 인접한 친구들끼리 짝 맞추고(001001 -> 001100 꼴) 뒤의 1 지우고 앞의 1 지우기
// 1이 홀수 개 있을 때: 제일 밑에 있는 1을 그냥 지우고 짝수 개로 만든 후 위의 풀이 방법 사용

// 하니까 맞습니다. 이게 왜 최적인지는 모름...

void solve() {
  vector<int> p;
  string s;
  cin >> s;
  reverse(all(s));
  for (int i = 0;i < s.length();i++)
    if (s[i] == '1')
      p.push_back(i);
  int pc = p.size();
  ll ans = 0;
  int idx = 0;
  if (pc % 2) {
    ans += ( 2 << p[0] ) - 1;
    idx++;
  }
  for (;idx < pc;idx += 2) {
    for (int j = p[idx];j < p[idx + 1];j++) {
      ans += 1 + ( ( 2 << j ) - 1 );
    }
  }
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
