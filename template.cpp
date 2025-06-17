//////Debugging//////////////////////////////////////////////////////////////////////////

#include <ostream>
#include <iterator>
#include <vector>
template<class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
  copy(v.begin(), v.end(), std::ostream_iterator<T>(stream, " "));
  return stream;
}

//////New Type Definition////////////////////////////////////////////////////////////////

#include <complex>
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

#include <cmath>
const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

//////2D Graph Search////////////////////////////////////////////////////////////////////

// const int dx[] = { -1,1,0,0,1,1,-1,-1 };
// const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

// bool inRange(int i, int j, int n, int m) {
//   return 0 <= i && i < n && 0 <= j && j < m;
// }

//////Union-Find/////////////////////////////////////////////////////////////////////////

// struct union_find {
//   std::vector<int> arr;

//   union_find(int sz) {
//     arr.resize(sz + 1);
//     for (int i = 1; i <= sz; i++)
//       arr[i] = i;
//   }

//   int find(int x) {
//     if (arr[x] == x) return x;
//     else return arr[x] = find(arr[x]);
//   }

//   void merge(int x, int y) {
//     x = find(x);
//     y = find(y);
//     if (x != y) {
//       arr[y] = x;
//     }
//   }
// };

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  // DO what you can DO!
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
