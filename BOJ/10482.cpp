#include <format>
#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef std::pair<int, int> pii;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

vector<bool> isPrime(32001, true);

void preprocess() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2;i <= 32000;i++)
    if (isPrime[i])
      for (int j = 2;i * j <= 32000;j++)
        isPrime[i * j] = false;
}

void solve() {
  int N;
  cin >> N;
  vector<pii> ans;
  for (int i = 2;i <= N / 2;i++)
    if (isPrime[i] && isPrime[N - i])
      ans.push_back({ i,N - i });

  cout << format("{} has {} representation(s)", N, ans.size()) << endl;
  for (auto [p, q] : ans)
    cout << format("{}+{}", p, q) << endl;
}

int main() {
  FastIO;
  preprocess();
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
    if (tc != testcase)
      cout << endl;
  }
}
