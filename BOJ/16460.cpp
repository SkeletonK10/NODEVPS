//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  string pref;
  int d, n;
  cin >> pref >> pref >> d >> n;

  multiset<string> ans;
  while (n--) {
    string name, gender;
    int dist;
    cin >> name >> gender >> dist;
    if (dist <= d && pref.find(gender) != string::npos)
      ans.insert(name);
  }
  for (const string& s : ans)
    cout << s << endl;
  if (ans.empty())
    cout << "No one yet";
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
