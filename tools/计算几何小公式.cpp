1. a*b*c=4*R*s(�������ʽ�����Ҷ���õ�)
2. ���׹�ʽ: s=sqrt(p*(p-a)*(p-b)*(p-c))��p=(a+b+c)/2
3. ��֪�����ε�����abc����뾶: R=abc/sqrt(a+b+c)(a+b-c)(a+c-b)(b+c-a)
4. Բ̨: V=��h(R^2��Rr��r^2)/3
5. pick��ʽ:
��AΪƽ�����Ը��ӵ�Ϊ����ĵ�������Σ��������Ϊ�� 
s=b/2+i-1
����bΪ�߽��ϵĸ��ӵ���,iΪ�Ȳ��ĸ��ӵ�����

���ӣ�
/*
   ���⣺��������������꣬�������������������������������ж��ٸ������������ϵģ�
*/
#include<cstdio>
#include<cmath>
using namespace std;
struct point{
	int x,y;
}p[3];
int _abs(int x){
	if(x<0) return -x;
	else return x;
}
int xmul(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int p_num(point a,point b){
	return gcd(_abs(a.x-b.x),_abs(a.y-b.y));
}
int main(){
	int i;
	double s,b;
	while(1){
		for(i=0;i<3;++i) scanf("%d%d",&p[i].x,&p[i].y);
		if(p[0].x==0&&p[0].y==0&&p[1].x==0&&p[1].y==0&&p[2].x==0&&p[2].y==0) break;
		s=fabs((xmul(p[0],p[1],p[2])+0.0)/2);
		b=p_num(p[0],p[1])+p_num(p[0],p[2])+p_num(p[1],p[2]);
		printf("%.0f\n",s-b/2+1);
	}
	return 0;
}
6. ��������壺
a * b = |a| * |b| * sin<a,b>
