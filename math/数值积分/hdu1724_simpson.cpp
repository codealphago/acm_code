#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-6;
//����simpson��
template<class T>
double simpson(const T &f,double a,double b){
	double c =  a+(b-a)/2;
	return (f(a) + 4*f(c) + f(b))*(b-a)/6;
}
//����ӦSimpson��ʽ(�ݹ����)����֪��������[a,b]�ϵ�����simpsonֵA 
template<class T>
double asr(const T &f, double a , double b ,double eps ,double A){
	double c = a+ (b-a)/2;
	double L = simpson(f,a,c) ,R = simpson(f,c,b);
	if(fabs(A-L-R)<=15*eps) return L + R +(A-L-R)/15;
	return asr(f,a,c,eps/2,L) + asr(f,c,b,eps/2,R);
}
//����ӦSimpson��ʽ(������) 
template<class T>
double asr(const T &f, double a, double b, double eps){
	return asr(f, a, b, eps, simpson(f, a, b));
}
double a,b;
double func(double x){
	return 2*b*sqrt(1-x*x/(a*a));
}
int main(){
	int T;
	double l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
		printf("%.3f\n",asr(func,l,r,eps));
	}
	return 0;
}
