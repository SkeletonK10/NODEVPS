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
const int INF = 1987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

//////2D Graph Search//////////////////////////////////////

//const int dx[] = { -1,1,0,0,1,1,-1,-1 };
//const int dy[] = { 0,0,-1,1,1,-1,1,-1 };
//
//bool inRange(int i, int j, int n, int m)
//{ return 0 <= i && i < n && 0 <= j && j < m; }

//////Union-Find///////////////////////////////////////////

//struct Union_Find {
//    std::vector<int> arr;
//
//    Union_Find(int sz) {
//        arr.resize(sz + 1);
//        for (int i = 1; i <= sz; i++)
//            arr[i] = i;
//    }
//
//    int Find(int x) {
//        if (arr[x] == x) return x;
//        else return arr[x] = Find(arr[x]);
//    }
//
//    void Union(int x, int y) {
//        x = Find(x);
//        y = Find(y);
//        if (x != y) {
//            arr[y] = x;
//        }
//    }
//};

///////////////////////////////////////////////////////////

using namespace std;

bool comp(pii& a, pii& b) { return a.FF < b.FF; }
bool compSS(pii& a, pii& b) { return a.SS < b.SS; }
bool compR(pii& a, pii& b) { return a.FF > b.FF; }
bool compRSS(pii& a, pii& b) { return a.SS > b.SS; }

void solve() {
  int n;
  cin >> n;
  if (n < 4 || n % 2) {
    cout << "NIE";
    return;
  }

  vector<int> v(n / 4, 2);
  if (n % 4)
    v.push_back(0);

  vector<pii> ans;
  int x = 0, y = 0;
  for (;x < v.size();) {
    ans.push_back({ x, y });
    ans.push_back({ x + 1, y });
    y += v[x];
    x++;
  }

  bool isBack2 = ( v.back() == 0 );
  y += 2;
  ans.push_back({ x, y });
  x -= isBack2 ? 2 : 1;
  ans.push_back({ x, y });

  for (;x > 0;) {
    y -= v[x];
    x--;
    ans.push_back({ x + 1, y });
    ans.push_back({ x, y });
  }

  for (pii& i : ans) {
    cout << i.FF << ' ' << i.SS << endl;
  }
}

int main() {
  FastIO;
	int testcase = 1;
	//cin >> testcase;
	while (testcase--) {
    solve();
  }
}