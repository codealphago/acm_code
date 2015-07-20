/*poj 2420
  ���⣺
  ƽ���ϸ���n����(xi,yi)��������һ���㣬����n��ľ������С��
  ���ƣ�
  1 <= n <= 100
  0 <= xi,yi <= 1e4, Ϊ����
  ˼·��
  ģ���˻�

  ��α�������£�
  Let s = s0
  For k = 0 through k_max (exclusive):
	T := temperature(k / k_max)
  	Pick a random neighbour, s_new := neighbour(s)
  	If P(E(s), E(s_new), T) > random(0, 1), move to the new state:
  		s := s_new
  Output: the final state s
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const double E = exp(1.0);
struct Pt{
	double x,y;
}p[105];
double sqr(double x){
	return x*x;
}
double dis(Pt a, Pt b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double get_sum(Pt p0, int n){
	double ret = 0;
	for(int i = 0; i < n; ++i)
		ret += dis(p0, p[i]);
   return ret;	
}
int main(){
	srand(1123);
	int n;
	int limit = 10000; //(x,y)�ķ�Χ
	while(scanf("%d", &n) != EOF){
		double x0 = 0, y0 = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf", &p[i].x, &p[i].y);
			x0 += p[i].x;
			y0 += p[i].y;
		}
		x0 /= n;
		y0 /= n;
		double ans = get_sum((Pt){x0, y0}, n);
		double temp = 1e5; //��ʼ�¶�, ������Ŀ�޸�
		while(temp > 0.02){ //0.02Ϊ�¶ȵ�����, ���¶�temp�ﵽ����, ��ֹͣ����
			double x = 0, y = 0;
			for(int i = 0; i < n; ++i){ //��ȡ�����Ĺ��������Ŀ����
				x += (p[i].x - x0) / dis((Pt){x0, y0}, p[i]);
				y += (p[i].y - y0) / dis((Pt){x0, y0}, p[i]);
			}
			double tmp = get_sum((Pt){x0 + x * temp, y0 + y * temp}, n); //�꺯��E(x_new);
			if(tmp < ans){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
			} else if(pow(E, (ans - tmp) / temp) > (rand() % limit) / (double)limit){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
			}
			temp *= 0.9; //0.9Ϊ�����˻�����, (��ΧΪ0~1, Խ��õ�ȫ�����Ž�ĸ���Խ��, ����ʱ��Խ��
		}
		printf("%.0f\n", ans);
	}
	return 0;
}
