#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
	string s;
	cin >> s;
	ll k;
	cin >> k;
	ll ans = k * s.size();

	// if (cons_temp) statement can be removed
	ll cons_temp = 0;
	vector<ll> cons;
	for (char c : s) {
		if (c == 'P')
			cons_temp++;
		else {
			if (cons_temp)
				cons.push_back(cons_temp);
			cons_temp = 0;
		}
	}
	if (cons_temp) cons.push_back(cons_temp);
	
	if (cons.size() > 1 && s[0] == 'P' && s[s.size() - 1] == 'P') {
		cons[0] += cons.back();
		cons.pop_back();
	}

    // special case: ALL P
	if (cons.size() == 1 && cons[0] == s.size()) {
		cout << 0;
		return;
	}
    
	// sub for consecutive p's:
	// example:
	// k = 4 && 7 consecutive p's -> 4+4+4+4+3+2+1 cases
	// k = 7 && 4 consecutive p's -> 4+3+2+1 cases
	for (ll& ps : cons) {
		ll sub = ( ps * ( ps + 1 ) ) / 2;
		ll temp = max(0LL, ps - k);
		sub -= ( temp * ( temp + 1 ) ) / 2;
		ans -= sub;
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
