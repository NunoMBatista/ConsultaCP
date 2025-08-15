Conjunto de funções para usar em qualquer polígono simples (sem "buracos" nem "torções")
    vector<point>: Conjunto de pontos que definem o polígono, sendo que o último elemento TEM de ser igual ao primeiro (fecho de loop)

Complexidade: Todas as funções são O(n), à exceção do Convex Hull, que é O(n*log(n))

Foi usado a "Andrew's Monotone Chain" como Convex Hull, em vez do Graham's Scan, pois é uma função mais fácíl e rápida de implementar, apesar de ambas terem a mesma complexidade.

Atenção!! É necessário o ficheiro "1D.md"

```c++
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
```
