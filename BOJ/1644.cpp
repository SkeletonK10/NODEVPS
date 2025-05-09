//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;


vector<int> getPrime(int N) {
  vector<int> prime;
  vector<bool> isPrime(N + 1, true);
  for (int i = 2;i <= N;i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = 2;i * j <= N;j++)
        isPrime[i * j] = false;
    }
  }
  return prime;
}

void solve() {
  int N;
  cin >> N;
  vector<int> prime = getPrime(N);
  int s = 0, e = 0, sum = 0;
  int ans = 0;
  while (e <= prime.size()) {
    ans += sum == N;
    if (sum < N) {
      if (e == prime.size())
        break;
      sum += prime[e];
      e++;
    }
    else {
      sum -= prime[s];
      s++;
    }
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
