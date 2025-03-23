#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> depth(n + 1);
	vector<string> name(n + 1);
	depth[0] = -1;
	for (int i = 1;i <= n;i++) {
		int parent;
		cin >> parent >> name[i];
		adj[parent].push_back(i);
		depth[i] = depth[parent] + 1;
	}
	stack<int> st;
	st.push(1);
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		for (int i = 0;i < depth[cur];i++)
			cout << '.';
		cout << name[cur] << endl;
		reverse(adj[cur].begin(), adj[cur].end());
		for (int& nxt : adj[cur])
			st.push(nxt);
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
