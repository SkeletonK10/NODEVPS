#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

int query[26];

void rev_and_insert(string s, int l, int r, set<string>& st) {
	int len = r - l;
	if (len <= 1) {
		st.insert(s);
		return;
	}

	if (len % 2) {
		int m1 = ( l + r ) / 2;
		int m2 = m1 + 1;
		string s_m1 = s, s_m2 = s;
		reverse(s_m1.begin() + l, s_m1.begin() + m1);
		rev_and_insert(s_m1, m1, r, st);
		reverse(s_m1.begin() + l, s_m1.begin() + m1);
		reverse(s_m1.begin() + m1, s_m1.begin() + r);
		rev_and_insert(s_m1, l, m1, st);
		reverse(s_m2.begin() + l, s_m2.begin() + m2);
		rev_and_insert(s_m2, m2, r, st);
		reverse(s_m2.begin() + l, s_m2.begin() + m2);
		reverse(s_m2.begin() + m2, s_m2.begin() + r);
		rev_and_insert(s_m2, l, m2, st);
	}
	else {
		int m = ( l + r ) / 2;
		string s_m = s;
		reverse(s_m.begin() + l, s_m.begin() + m);
		rev_and_insert(s_m, m, r, st);
		reverse(s_m.begin() + l, s_m.begin() + m);
		reverse(s_m.begin() + m, s_m.begin() + r);
		rev_and_insert(s_m, l, m, st);
	}
}

void solve() {
	int n, len = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string c;
		int temp;
		cin >> c >> temp;
		query[c[0] - 'a'] = temp;
		len += temp;
	}
	string template_s;
	for (int i = 0;i < 26;i++) {
		while (query[i]--)
			template_s += 'a' + i;
	}

	set<string> st;
	string s;
	cin >> s;
	for (int i = 0;i <= s.size() - len;i++) {
		string sliced_s = s.substr(i, len);
		string sliced_s_sorted = sliced_s;
		sort(all(sliced_s_sorted));
		if (template_s == sliced_s_sorted) {
			rev_and_insert(sliced_s, 0, len, st);
		}
	}
	// for (auto a : st)
	// 	cout << a << endl;
	cout << st.size();
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
