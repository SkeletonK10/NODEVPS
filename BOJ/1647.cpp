#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Union-Find///////////////////////////////////////////

struct union_find {
  std::vector<int> arr;

  union_find(int sz) {
    arr.resize(sz + 1);
    for (int i = 1; i <= sz; i++)
      arr[i] = i;
  }

  int find(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = find(arr[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      arr[y] = x;
    }
  }
};

///////////////////////////////////////////////////////////

using namespace std;

// 2개의 마을로 분할하기, 이때 cost 최소로

// MST로 해결
// MST를 구성하는 edge 중 cost가 최대인 것을 골라내서 지우면 완성
// Kruskal algorithm을 사용하되, 마지막으로 사용된 edge의 cost 저장

void solve() {
  int n, m;
  vector<tiii> edge;
  cin >> n >> m;
  for (int i = 0;i < m;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    edge.push_back({ c,s,e });
  }
  sort(all(edge));
  union_find uf(n);
  int ans = 0, last = 0;
  for (auto& [c, s, e] : edge) {
    if (uf.find(s) != uf.find(e)) {
      last = c;  // 마지막 edge 저장
      ans += c;  // 총 cost 저장
      uf.merge(s, e);
    }
  }
  cout << ans - last;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
