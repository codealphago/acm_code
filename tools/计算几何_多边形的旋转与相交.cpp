/*cf283div1d
  ���⣺������P,Q,����������Σ�����������ηֱ���P,Q����ͬ�Ľ��ٶ���ת����������������ܲ����ཻ��
  ���ƣ�
  0<=|x|,|y|<=1e4
  ����α߱���С��1000
  ��⣺
  �ȿ���һ���߶���P��ת��һ������Q��ת���������ʲô����µ���߶��ཻ��
  ��Ŀ�ͱ��1000���߶κ�1000�����ܲ����ཻ������ѭ��ֱ���С�
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
struct Point {
	double x, y;
	Point() {}
	Point(int _x, int _y) { x = _x; y = _y; }
	void scan() {
		scanf("%lf%lf", &x, &y);
	}
	Point operator + (Point a) {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a) {
		return Point(x - a.x, y - a.y);
	}
	double operator * (Point a) {
		return x * a.x + y * a.y;
	}
	double operator ^ (Point a) {
		return x * a.y - y * a.x;
	}
	Point rotate() {
		return Point(-y, x);
	}
	double len() {
		return *this * *this;
	}
};
int n, m;
Point P, Q;
const int N = 1010;
Point A[N], B[N];
bool ans = false;
double R;
int sgn(double x) {
	if (x == 0) return 0;
	if (x < 0) return -1;
	return 1;
}
double getMinD(Point O, Point C, Point D) {
	double minD = min( (O - C).len(), (O - D).len() );
	Point OC = C - O;
	Point OD = D - O;
	Point OH = (D - C).rotate();
	if ( sgn(OH ^ OC) * sgn(OH ^ OD) != -1 )
		return minD;
	double s = fabs(OC ^ OD);
	double h2 = s * s / (C - D).len();
	return h2;
}
bool gao(Point O, Point C, Point D) {
	double maxD = max( (O - C).len(), (O - D).len() );
	double minD = getMinD(O, C, D);
	if (minD <= R && R <= maxD)
		return true;
	return false;
}
int main() {
	P.scan();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		A[i].scan();
	Q.scan();
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		B[i].scan();
	Point PQ = Q - P;
	R = PQ.len();
	for (int i = 0; i < n; ++i) {
		Point O = A[i] + PQ;
		for (int j = 0; j < m; ++j) {
			ans |= gao(O, B[j], B[(j + 1) % m]);
		}
	}
	for (int i = 0; i < m; ++i) {
		Point O = B[i] - PQ;
		for (int j = 0; j < n; ++j) {
			ans |= gao(O, A[j], A[(j + 1) % n]);
		}
	}
	if (ans)
		puts("YES");
	else
		puts("NO");
	return 0;
}

