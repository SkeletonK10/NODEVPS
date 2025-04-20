#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

using namespace std;

vector<pii> loc = {
  {0,4}, {1,1}, {1,3}, {1,5},
  {1,7}, {2,2}, {2,6}, {3,1},
  {3,3}, {3,5}, {3,7}, {4,4}
};
vector<vector<int>> sum = {
  {0,2,5,7}, {7,8,9,10}, {10,6,3,0},
  {1,5,8,11}, {11,9,6,4}, {4,3,2,1}
};

/////////////////////////////////////////////////////////////////////////////////////////

char field[6][10];
vector<int> star(12), unusedNum(12, 1), unusedLoc(12, 1);

void set2Vec(vector<int>& v) {
  vector<int> temp;
  for (int i = 0;i < 12;i++)
    if (v[i])
      temp.push_back(i);
  v = temp;
}

void assign(vector<int>& v, vector<int>& l) {
  for (int i = 0;i < v.size();i++)
    star[l[i]] = v[i];
}

bool check() {
  for (auto& line : sum) {
    int temp = 0;
    for (int& e : line)
      temp += star[e];
    if (temp != 22)     //  26 - 4
      return false;
  }
  return true;
}

void assignField() {
  for (int i = 0;i < 12;i++) {
    auto [x, y] = loc[i];
    char c = 'A' + star[i];
    field[x][y] = c;
  }
}

void printField() {
  for (int i = 0;i < 5;i++)
    cout << field[i] << endl;
}

void solve() {
  for (int i = 0;i < 5;i++)
    cin >> field[i];
  for (int i = 0;i < 12;i++) {
    auto [x, y] = loc[i];
    if (field[x][y] != 'x') {
      star[i] = field[x][y] - 'A';
      unusedNum[field[x][y] - 'A'] = 0;
      unusedLoc[i] = 0;
    }
  }
  set2Vec(unusedNum);
  set2Vec(unusedLoc);
  int sz = unusedLoc.size();
  vector<int> zero(sz);
  do {
    assign(unusedNum, unusedLoc);
    if (check()) {
      assignField();
      printField();
      return;
    }
  } while (next_permutation(unusedNum.begin(), unusedNum.end()));
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
