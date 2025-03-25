#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define FF first
#define SS second

//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 10000;
const double EPS = 0.0000001;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

// 1. 한 건물에서 이분탐색을 할 것.
// 1-1. 높이 median을 정함.
// 1-2. 그 높이에서 다른 건물로 (좌우로) 선을 그음.
// 1-3. 그중 각도가 가장 높은 것을 취해 태양의 반원과 교점 구함.
// 1-4. tan 취해서 시간 계산.
// 1-5. 이를 양쪽에서 해서 일조량 구하기.
// 2. 모든 건물에 대해 반복.

using namespace std;

// ax^2 + bx + c = 0
struct quadratic {
	double a, b, c;

	quadratic(double ta, double tb, double tc) : a(ta), b(tb), c(tc) {}

	pair<double, double> solve() {
		double pm = sqrt(b * b - 4 * a * c);
		return { ( -b - pm ) / ( 2 * a ), ( -b + pm ) / ( 2 * a ) };
	}
};

// y = ax + b
struct linear {
	double a, b;

	linear(double ta, double tb) : a(ta), b(tb) {}

	quadratic operator* (const linear& l) const {
		double ta = a * l.a;
		double tb = a * l.b + b * l.a;
		double tc = b * l.b;
		return quadratic(ta, tb, tc);
	}

	double getY(double x) {
		return a * x + b;
	}
};

double check(int curI, double curH, double r, vector<pair<double, double>>& building) {
	double x = building[curI].FF;
	double a1, a2;
	double slope = INF;
	for (int i = 0;i < curI;i++) {
		auto [bx, by] = building[i];
		double tempSlope = ( curH - by ) / ( x - bx );
		slope = min(slope, tempSlope);
	}
	if (slope == INF) {
		a1 = PI;
	}
	else {
		linear l1 = linear(slope, curH - slope * x);
		quadratic eq1 = ( l1 * l1 );
		eq1.a += 1;
		eq1.c -= r * r;
		double sol1 = eq1.solve().FF;
		if (l1.getY(sol1) < 0)
			a1 = PI;
		else a1 = acos(sol1 / r);
	}
	slope = -INF;
	for (int i = curI + 1;i < building.size();i++) {
		auto [bx, by] = building[i];
		double tempSlope = ( by - curH ) / ( bx - x );
		slope = max(slope, tempSlope);
	}

	if (slope == -INF) {
		a2 = 0;
	}
	else {
		linear l2 = linear(slope, curH - slope * x);
		quadratic eq2 = ( l2 * l2 );
		eq2.a += 1;
		eq2.c -= r * r;
		double sol2 = eq2.solve().SS;
		if (l2.getY(sol2) < 0)
			a2 = 0;
		else a2 = acos(sol2 / r);
	}

	return a1 - a2;
}

double buildingBSearch(int cur, double r, double hAngle, vector<pair<double, double>>& building) {
	double s = 0, e = building[cur].SS;
	while (e - s > EPS) {
		double m = ( s + e ) / 2;
		if (check(cur, m, r, building) > hAngle - EPS) {
			e = m;
		}
		else {
			s = m;
		}
	}
	return building[cur].SS - e;
}

double solve() {
	int n;
	double r, h, ans = 0, total = 0;
	cin >> n >> r >> h;
	vector<pair<double, double>> building(n);
	for (auto& [x, y] : building) {
		cin >> x >> y;
		total += y;
	}
	sort(building.begin(), building.end());
	double hAngle = ( h / 12 ) * PI;
	for (int i = 0;i < n;i++) {
		ans += buildingBSearch(i, r, hAngle, building);
	}
	return ans / total;
}

int main() {
	FastIO;
	int testcase = 1;
	cin >> testcase;
	cout << fixed << setprecision(7);
	for (int tc = 1;tc <= testcase;tc++) {
		cout << "Case #" << tc << ": " << solve() << endl;
	}
}
