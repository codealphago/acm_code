/*hdu 3756 Dome of Circus
  ���⣺
  ��һ����ά�ռ���, ����һЩ��, ��Щ���z���궼�Ǵ���0�ġ�Ҫ�����һ��Բ׶(������Բ��), ʹ�����Բ׶�ĵ�����z = 0��ƽ����, ���ܹ��������и�����n���㲢��Բ׶�����Ҫ����С��
  ���ƣ�
  1 <= n <= 10000
  |x|, |y|, |z| <= 1000
  ˼·��
  �Ȱ����е�ӳ�䵽һ��X-Y����ĵ�һ������, Ȼ�������ת��Ϊ, ��һ��ֱ�ߺ�X��, Y��Χ�ɵ������ΰ����е㶼Χ����, ����Ҫ�������������С��
  ���Կ������ְ뾶�����������εĵױ��������
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 1e4 + 5;
const double eps = 1e-8;
const double INF = 1e10;
struct Pt{
	double x, y, z;
	double X, Y;
}p[N];
double sqr(double x){
	return x * x;
}
double get_Y(double x, int n){
	double max_xl = 0;
	for(int i = 0; i < n; ++i){
		double tmp = p[i].Y / (x - p[i].X);
		max_xl = max(max_xl, tmp);
	}
	return max_xl * x;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		double max_x = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
			p[i].X = sqrt(sqr(p[i].x) + sqr(p[i].y));
			p[i].Y = p[i].z;
			max_x = max(max_x, p[i].X);
		}
		double L = max_x + eps, R = INF;
		double m_l, m_r;
		while(L + eps < R){
			double m_l = (2*L + R) / 3;
			double m_r = (L + 2*R) / 3;
			double ans_l = get_Y(m_l, n) * m_l * m_l;
			double ans_r = get_Y(m_r, n) * m_r * m_r;
			if(ans_l > ans_r){
				L = m_l;
			} else {
				R = m_r;
			}
		}
		double ans = (L + R) / 2;
		printf("%.3f %.3f\n", get_Y(ans, n), ans);
	}
	return 0;
}
