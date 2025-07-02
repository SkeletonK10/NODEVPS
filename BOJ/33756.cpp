//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll num8[18];

void preprocess()
{
  num8[0] = 8;
  for (int i = 1;i < 18;i++)
    num8[i] = num8[i - 1] * 10 + 8;
}

bool solve() {
  ll N;
  cin >> N;
  int cnt = 0;
  for (int i = 17;i >= 0;i--) {
    if (N >= num8[i]) {
      N -= num8[i];
      i++;
      cnt++;
    }
    if (cnt > 8)
      return false;
    if (N == 0)
      return true;
  }
  return false;
}

int main() {
  preprocess();
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << ( solve() ? "Yes" : "No" ) << endl;
  }
}
