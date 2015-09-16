/*hdu 1724
  ���⣺
  ����Բ���, x^2/a^2+y^2/b^2=1, ����a,b,l,r, ����Բ��ֱ��x=l, x=r���������
  ˼·��
  ����Ӧsimpson�����Ȳ��Ǻܸߣ�����epsҪ��Сһ�㡣
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-6;
double a, b;
double f(double x) {	//���ֺ���
	return 2 * b * sqrt(1 - x * x / (a * a));
}
//����simpson��
double simpson(double a, double b) {
	double c =  a + (b - a) / 2;
	return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}
//����ӦSimpson��ʽ(�ݹ����)����֪��������[a,b]�ϵ�����simpsonֵA
double asr(double a , double b , double eps , double A) {
	double c = a + (b - a) / 2;
	double L = simpson(a, c) , R = simpson(c, b);
	if (fabs(A - L - R) <= 15 * eps) return L + R + (A - L - R) / 15;
	return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}
//����ӦSimpson��ʽ(������)
double asr(double a, double b, double eps) {
	return asr(a, b, eps, simpson(a, b));
}
int main() {
	int T;
	double l, r;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf%lf", &a, &b, &l, &r);
		printf("%.3f\n", asr(l, r, eps));
	}
	return 0;
}
