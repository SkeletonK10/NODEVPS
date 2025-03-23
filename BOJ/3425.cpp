#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

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
const int THRESHOLD = 1e9;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
	while (true) {
		vector<string> pgm;
		map<int, int> nums;
		while (true) {
			string s;
			cin >> s;
			if (s == "QUIT")
				return;
			if (s == "END")
				break;
			if (s == "NUM") {
				int temp;
				cin >> temp;
				nums[pgm.size()] = temp;
			}
			pgm.push_back(s);
		}
		int n;
		cin >> n;
		vector<ll> input(n);
		for (int i = 0;i < n;i++) {
			stack<ll> st;
			ll temp;
			cin >> temp;
			st.push(temp);
			int top_idx = 1;
			for (int i = 0;i < pgm.size();i++) {
				string& instr = pgm[i];
				if (instr == "NUM") {
					st.push(nums[i]);
				}
				else if (instr == "POP") {
					if (st.empty())
						goto ERROR;
					st.pop();
				}
				else if (instr == "INV") {
					if (st.empty())
						goto ERROR;
					ll temp = st.top();
					st.pop();
					st.push(-temp);
				}
				else if (instr == "DUP") {
					if (st.empty())
						goto ERROR;
					st.push(st.top());
				}
				else if (instr == "SWP") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					st.push(tmp1);
					st.push(tmp2);
				}
				else if (instr == "ADD") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					ll res = tmp2 + tmp1;
					if (abs(res) > THRESHOLD)
						goto ERROR;
					st.push(res);
				}
				else if (instr == "SUB") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					ll res = tmp2 - tmp1;
					if (abs(res) > THRESHOLD)
						goto ERROR;
					st.push(res);
				}
				else if (instr == "MUL") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					ll res = tmp2 * tmp1;
					if (abs(res) > THRESHOLD)
						goto ERROR;
					st.push(res);
				}
				else if (instr == "DIV") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					if (tmp1 == 0)
						goto ERROR;
					ll res = tmp2 / tmp1;
					st.push(res);
				}
				else if (instr == "MOD") {
					if (st.size() < 2)
						goto ERROR;
					ll tmp1 = st.top();
					st.pop();
					ll tmp2 = st.top();
					st.pop();
					if (tmp1 == 0)
						goto ERROR;
					ll res = tmp2 % tmp1;
					st.push(res);
				}
			}
			if (st.size() != 1)
				goto ERROR;
			cout << st.top() << endl;
			continue;
		ERROR:
			cout << "ERROR" << endl;
		}
	
		cout << endl;
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
