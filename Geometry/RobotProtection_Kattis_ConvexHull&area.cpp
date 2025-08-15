#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1e9+7;
double eps = 1e-12;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln  "\n" 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>
inline ll mod(ll a, ll m) {return ((a%m) + m)%m;}

const double PI = acos(-1.0);
//Sempre que se usa fabs(y) < eps, é o equivalente a y == 0, mas para doubles
//Law of Cosines: c**2 = a**2 + b**2 - 2*a*b*cos(C)
//Law of Sines: a/sin(A) == b/sin(B) == c/sin(C) == 2*(r of circumcircle)

//Points cant have coordinates more specific than eps
struct point{
	double x, y;
	point() {x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	
	bool operator < (point other) const {
		if (fabs(x-other.x) > eps) return x < other.x;
		return y < other.y;
	}
	
	bool operator == (const point &other) const {
		return (fabs(x-other.x) < eps) && (fabs(y-other.y) < eps);
	}
};

//Euclidean distance
double dist(const point &p1, const point &p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}

double DegToRad(double d) { return d*PI / 180.0; }
double RadToDeg(double r) { return r*180 / PI; }

//theta in degrees
//rotate point, with origin (0, 0)
point rotate(const point &p, double theta) {
	double rad = DegToRad(theta);
	return point(p.x*cos(rad) - p.y*sin(rad),
					p.x*sin(rad) + p.y*cos(rad));
}

//a*x + b*y + c = 0
struct line {double a, b, c; };

void pointsToLine(const point &p1, const point &p2, line &l){
	if (fabs(p1.x - p2.x) < eps)          //vertical line
		l = {1.0, 0.0, -p1.x};
	else
		l = {-(double) (p1.y - p2.y) / (p1.x - p2.x),
				1.0,
				-(double) (l.a*p1.x) - p1.y};
}

void pointSlopeToLine(point p, double m, line &l){
	l.a = -m;
	l.b = 1.0;
	l.c = -((l.a * p.x) + (l.b * p.y));
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}

bool areSame(line l1, line l2){
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < eps);
}

bool areIntersect (line l1, line l2, point &p){
	if (areParallel(l1, l2)) return false;
	//solve a1*x + b1*y + c = a2*x + b1*y + c
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	//test for vertical case
	if (fabs(l1.b) > eps) p.y = -(l1.a * p.x + l1.c);
	else                  p.y = -(l2.a * p.x + l2.c);
	return true;
}

point lineIntersectSeg(point p, point q, point A, point B){
	double a = B.y - A.y, b = A.x - B.x, c = B.x*A.y - A.x*B.y;
	double u = fabs(a*p.x + b*p.y + c);
	double v = fabs(a*q.x + b*q.y + c);
	return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

struct vec { double x, y;
	vec(double _x, double _y): x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {
	return vec(b.x - a.x, b.y - a.y);
}

vec scale(const vec &v, double s){
	return vec(v.x*s, v.y*s);
}

point translate(const point &p, const vec &v){
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

//normal squared
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

//angle between vectors
double angle(const point &a, const point &o, const point &b){
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa)*norm_sq(ob)));      // oa * ob = cos(ang)*|oa|*|ob|
}

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

//true if p, q, r in ccw
bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > eps;
}

bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < eps;
}

//returns dist (and point) closest to p in line AB
double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

//returns dist (and point) closest to p in segment [AB]
double distToLineSegment(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if ( u < 0.0){
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);
}

//Interseção de 2 segmentos de reta
bool segmentIntersect(point a, point b, point c, point d, point &e){
	if (ccw(a, b, c) == ccw(a, b, d) || ccw(c, d, a) == ccw(c, d, b)) return false;
	line l1, l2;
	pointsToLine(a, b, l1);
	pointsToLine(c, d, l2);
	areIntersect(l1, l2, e);
	return true;
}

//P[n-1] == P[0]
double perimeter(const vector<point> &P){
	double ans = 0.0;
	for (int i = 0; i < (int)P.size()-1;++i){
		ans += dist(P[i], P[i+1]);
	}
	return ans;
}

double area(const vector<point> &P){
	double ans = 0.0;
	for (int i = 0; i < (int)P.size()-1; ++i){
		ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
	}
	return fabs(ans)/2.0;
}

bool isConvex(const vector<point> &P){
	int n = (int)P.size();
	if (n <= 3) return false;
	bool firstTurn = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < n-1; ++i){
		if (ccw(P[i], P[i+1], P[(i+2 == n ? 1 : i+2)]) != firstTurn) return false;
	}
	return false;
}

//Returns if point is inside Polygon
//if sum of all angles of every pair of adjacent points in polygon with pt (pt is centre) is 360, pt in polygon
//if sum is 0, pt isn´t in polygon
int insidePolygon(point pt, const vector<point> &P){
	int n = (int)P.size();
	if (n <= 3) return -1;
	bool on_polygon = false;
	for (int i = 0; i < n-1; ++i){
		if (fabs(dist(P[i], pt) + dist(pt, P[i+1]) - dist(P[i], P[i+1])) < eps){
			on_polygon = true;
		}
	}
	if (on_polygon) return 0;
	double sum = 0.0;
	for (int i = 0; i < n-1; ++i){
		if (ccw(pt, P[i], P[i+1])){
			sum += angle(P[i], pt, P[i+1]);
		}else{
			sum -= angle(P[i], pt, P[i+1]);
		}
	}
	return fabs(sum) > PI ? 1: -1;
}

//Leftmost part by polygon cut by segment [AB], where A.y < B.y (A is lower than B)
//For rightmost part, use [BA]
vector<point> cutPolygon(point A, point B, const vector<point> &Q){
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); ++i){
		double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(toVec(A, B), toVec(A, Q[i+1]));
		if (left1 > -eps) P.push_back(Q[i]);
		if (left1*left2 < -eps)
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], A, B));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());
	return P;
}

//Convex Hull
vector<point> CH_Andrew(vector<point> &Pts){
	int n = Pts.size(), k = 0;
	vector<point> H(2*n);
	sort(Pts.begin(), Pts.end());
	for (int i = 0; i < n; i++){
		while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
		H[k++] = Pts[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--){
		while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
		H[k++] = Pts[i];
	}
	H.resize(k);
	return H;
}
//Nao esquecer !!! P[n] tem de ser P[0]

void solve(int n){
	vector<point> poly(n);
	for (int i = 0; i < n; i++){
		cin>>poly[i].x>>poly[i].y;
	}
	poly.pb(poly[0]);
	vector<point> ch = CH_Andrew(poly);
	cout<<area(ch)<<endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout<<fixed<<setprecision(1);
	//cin>>getline(cin, string);
	ll t;
	while(cin>>t && t != 0){
		solve(t);
	}
	return 0;
}
