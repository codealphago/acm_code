/*���⣺
  ƽ���ϸ���n����(xi,yi)��������һ���㣬����n��ľ������С��
  ���ƣ�
  1 <= n <= 100
  0 <= xi,yi <= 1e4, Ϊ����
  ˼·��
  ��ɽ�㷨
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Pt {
	double x, y;
} p[105];
double sqr(double x) {
	return x * x;
}
double dis(Pt a, Pt b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double get_sum(Pt p0, int n) {
	double ret = 0;
	for (int i = 0; i < n; ++i)
		ret += dis(p0, p[i]);
	return ret;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		double x0 = 0, y0 = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			x0 += p[i].x;
			y0 += p[i].y;
		}
		x0 /= n;
		y0 /= n;
		double ans = get_sum((Pt) {x0, y0}, n);
		double temp = 1e5; //��ʼ�¶�, ������Ŀ�޸�
		while (temp > 0.02) { //0.02Ϊ�¶ȵ�����, ���¶�temp�ﵽ����, ��ֹͣ����
			double x = 0, y = 0;
			//�������û�а취ȡ������� = double(rand() - RAND_MAX / 2) / (RAND_MAX / 2);
			for (int i = 0; i < n; ++i) { //���㲽���Ĺ��򣬸�����Ŀ�������ο�ģ���˻�ģ�� 
				x += (p[i].x - x0) / dis((Pt) {x0, y0}, p[i]);
				y += (p[i].y - y0) / dis((Pt) {x0, y0}, p[i]);
			}
			x0 += x * temp;
			y0 += y * temp;
			double tmp = get_sum((Pt) {x0, y0}, n);
			ans = min(ans, tmp);
			temp *= 0.9;
		}
		printf("%.0f\n", ans);
	}
	return 0;
}
