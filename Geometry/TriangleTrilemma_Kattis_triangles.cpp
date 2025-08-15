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

//1 - in, 0 - border, -1 - out
double insideCircle(const point &p, const point &c, double r){
	double dx = p.x - c.x, dy = p.y - c.y;
	double Euc = dx*dx + dy*dy, rSq = r*r;
	return (fabs(Euc - rSq) < eps) ? 0 : (Euc < rSq ? 1: -1);
}

double circlePerimeter(double r){ return 2 * PI * r; }
double circleArea(double r){ return r * r * PI; }
double arcLenght(double perimeter, double angle){ return angle * perimeter / 360.0;}
double chordLength(double r, double angle){ return 2 * r * sin(angle/2); }
double sectorArea(double angle, double area) { return angle * area / 360.0; }
double segmentArea(double angle, double area, double r){
	return sectorArea(angle, area) - (chordLength(r, angle) * r*cos(angle/2))/2;
}

//if 2 points are the intersection of 2 circles of radius r
bool circle2PtsRad(point p1, point p2, double r, point &c){
	double d2 = (p1.x - p2.x) * (p1.x *p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
	double det = r*r/d2 - 0.25;
	if (det < eps) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x)*0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y)*0.5 + (p2.x - p1.x) * h;
	return true;
}

bool isTriangle(point a, point b, point c){
	double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	return (ab + bc > ca) && (bc + ca > ab) && (ca + ab > bc) && !collinear(a, b, c);
}

double trianglePerimeter(double a, double b, double c){ return a + b + c; };
double trianglePerimeter(point a, point b, point c){ 
	return dist(a, b) + dist(b, c) + dist(c, a);
}

//Heron's formula with separated sqrt
double triangleArea(double a, double b, double c){
	double hp = trianglePerimeter(a, b, c)*0.5;
	return sqrt(hp) * sqrt(hp - a) * sqrt(hp - b) * sqrt(hp - c);
}
double triangleArea(point a, point b, point c){
	return triangleArea(dist(a, b), dist(b, c), dist(c, a));
}

//radius of inner circle in triangle
double rInCircle(double ab, double bc, double ca){
	return triangleArea(ab, bc, ca) / (0.5 * trianglePerimeter(ab, bc, ca));
}
double rInCircle(point a, point b, point c){
	return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

//centre of inner circle, if it exists
bool inCircle(point p1, point p2, point p3, point &ctr, double &r){
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < eps) return false;
	
	line l1, l2;
	double ratio = dist(p1, p2) / dist(p1, p3);
	point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
	pointsToLine(p1, p, l1);
	
	ratio = dist(p2, p1) / dist(p2, p3);
	p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
	pointsToLine(p2, p, l2);
	
	areIntersect(l1, l2, ctr);
	return true;
}

//radius of circumCircle in triangle
double rCircumCircle(double ab, double bc, double ca){
	return ab * bc * ca / (4.0 * triangleArea(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c){
	return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

//centre of circumcircle, if it exists
bool circumCircle(point p1, point p2, point p3, point &ctr, double &r){
	double a = p2.x - p1.x, b = p2.y - p1.y;
	double c = p3.x - p1.x, d = p3.y - p1.y;
	double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
	double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
	double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
	if (fabs(g) < eps) return 0;
	
	ctr.x = (d*e - b*f) / g;
	ctr.y = (a*f - c*e) / g;
	r = dist(p1, ctr);
	return 1;
}

//Square of width w and height h, with (x, y) being its leftmost and downmost coordinate
int insideRectangle(int x, int y, int w, int h, int a, int b){
	if ((x < a) && (a < x + w) && (y < b) && (b < y+h))
		return 1;
	else if ((x <= a) && (a <= x + w)  && (y <= b) && (b <= y + h))
		return 0;
	else
		return -1;
}

void solve(){
	point a, b, c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	if (!isTriangle(a, b, c)) cout<<"not a triangle"<<endl;
	else{
		double ang = max(angle(a, b, c), max(angle(b, c, a), angle(c, a, b)));
		ang = RadToDeg(ang);
		if (ang > 90.0){
			if (ab == bc || ab == ca || bc == ca) cout<<"isosceles obtuse triangle"<<endl;
			else cout<<"scalene obtuse triangle"<<endl;
		}else if (ang < 90.0){
			if (ab == bc || ab == ca || bc == ca) cout<<"isosceles acute triangle"<<endl;
			else cout<<"scalene acute triangle"<<endl;
		}else{
			if (ab == bc || ab == ca || bc == ca) cout<<"isosceles right triangle"<<endl;
			else cout<<"scalene right triangle"<<endl;
		}
	}
}
	
			

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout<<fixed<<setprecision();
	//cin>>getline(cin, string);
	ll t;
	cin>>t;
	for(ll i = 0; i < t; i++){
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
	return 0;
}
