#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
	int n, k;
	vector<int> cons;
	cin >> n >> k;
	int cons_temp = 0;
	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		if (temp % 2) {
			cons.push_back(cons_temp);
			cons_temp = 0;
		}
		else {
			cons_temp++;
		}
	}
	cons.push_back(cons_temp);
	
	vector<int> s(1);
	for (int& i : cons)
		s.push_back(s.back() + i);

	int ans = 0;
	if (k + 1 >= s.size())
		ans = s.back();
	for (int i = 0;i < s.size();i++) {
		int r = min(int(s.size() - 1), i + k + 1);
		ans = max(ans, s[r] - s[i]);
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
