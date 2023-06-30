#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define compress(x) sort(all(x)); x.erase(unique(all(x)),(x).end())
#define endl '\n'
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

//////2D Graph Search//////////////////////////////////////

// const int dx[] = { -1,1,0,0,1,1,-1,-1 };
// const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

// bool inRange(int i, int j, int n, int m) {
//   return 0 <= i && i < n && 0 <= j && j < m;
// }

//////Union-Find///////////////////////////////////////////

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

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  ll total = 0, cut = 0, s = 0, mxS = 0, mxCut = 0;
  for (int i = 0;i < n;i++) {
    ll temp;
    cin >> temp;
    s += temp;
    total += temp;
    if (mxS > s) {
      mxCut = cut;
      mxS = s;
    }
    if (s > 0) {
      s = 0;
      cut = total;
    }
  }
  cout << mxCut << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
