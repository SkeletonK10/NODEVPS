#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define FF first
#define SS second

//////Debugging//////////////////////////////////////////////////////////////////////////

template<class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
  copy(v.begin(), v.end(), std::ostream_iterator<T>(stream, " "));
  return stream;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<T>>& v) {
  //copy(v.begin(), v.end(), ostream_iterator<std::vector<T>>(os, "\n"));
  for (std::size_t i = 0; i < v.size(); i++)
    os << v[i] << "\n";
  return os;
}

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int solve() {
  int n;
  cin >> n;
  int ans = n;
  vector<pii> v1(n), v2(n);
  for (auto& [s, e] : v1)
    cin >> s >> e;
  for (auto& [s, e] : v2)
    cin >> s >> e;
  for (int i = 0;i < n;i++) {
    auto [s1, e1] = v1[i];
    auto [s2, e2] = v2[i];
    if (e1 < s2 || e2 < s1)
      return -1;
    else if (e1 == s2 || e2 == s1)
      ans--;
  }
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve();
  }
}
