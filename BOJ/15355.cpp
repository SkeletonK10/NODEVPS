#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

int arr[26][50001];

void solve() {
	string s;
	cin >> s;
	s = 'A' + s;
	int Q;
	cin >> Q;
	for (int i = 1; i < s.length();i++) {
		for (int j = 0; j < 26;j++)
			arr[j][i] = arr[j][i - 1];
		arr[s[i] - 'a'][i]++;
	}
	while (Q--) {
		int a, b, c, d;
		bool judge = true;
		cin >> a >> b >> c >> d;
		for (int i = 0;i < 26;i++) {
			if (arr[i][b] - arr[i][a - 1] != arr[i][d] - arr[i][c - 1])
				judge = false;
		}
		if (judge)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
