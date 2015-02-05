#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * һ��
 * ���ȣ�һЩ���ö���
 * some definitions about �����
 * */
//definition of Point
struct Point{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}//construct function
};

//definition of Vector
typedef Point Vector;// To realize it from program, we name Point as anotherword - Vector

const double PI = acos(-1.0);

//���º���˳���ϸ�

//Vector + Vector = Vector, Point + Point = Vector;
Vector operator + (Vector A, Vector B){
	return Vector(A.x + B.x, A.y + B.y);
}

// Point - Point = Vector
Vector operator - (Vector A, Vector B){
	return Vector(A.x - B.x, A.y - B.y);
}

//Vector * number = Vector
Vector operator * (Vector A, double p){
	return Vector(A.x * p, A.y * p);
}

//Vector / number = Vector
Vector operator / (Vector A, double p){
	return Vector(A.x / p, A.y / p);
}

bool operator < (const Point & a, const Point & b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;//define the precision

//estimate if the error is in the eps range
int dcmp(double x){
	return (x > eps) - (x < -eps);         //x>eps  ��> 1��x < -eps  ��> -1.
}

//estimate if Point a and Point b is equal in the eps range
bool operator == (const Point & a, const Point & b){
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

//definition of Line
struct Line{
	Point p;
	Vector v;
	double a;
	Line (Point p = Point(), Vector v = Vector(1, 0)) : p(p), v(v) {a = atan2(v.y, v.x);}//���캯��
	bool operator < (const Line & b) const {return a < b.a;}
	Point point(double t){return p + v * t;}
};

/*
 * ����
 * ���¿�ʼ��������
 * I'm some Basic Operations, such as ����������relation of locations of 2 Vectors, rotations of Vectors, geometry operation of plural numbers
 * */
//Calc ���
double Dot(Vector A, Vector B){
	return A.x * B.x + A.y * B.y;
}

//Calc length by ���
double Length(Vector A){
	return sqrt(Dot(A, A));
}

//Calc Angle by ���
double Angle(Vector A, Vector B){
	return acos(Dot(A, B) / Length(A) / Length(B));
}

//Calc ���
double Cross(Vector A, Vector B){
	return A.x * B.y - A.y * B.x;
}
double Area2(Point A, Point B, Point C){
	return Cross(B - A, C - A);
}

//Rotation of Vector : x' = x * cos a - y * sin a, y' = x * sin a + y * cos a;   a - ��ʱ����ת�Ľ�,�������Ǻ͵Ĺ�ʽ�Ƴ���-Ϊ˳ʱ����ת��+Ϊ��ʱ����ת
Vector Rotate(Vector A, double rad){//rad is ����
	return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

// ����
Vector Normal(Vector A){
	double L = Length(A);
	return Vector(-A.y / L, A.x / L);	
}

/*
 * ����
 * ���ֱ��
 * */
//��2ֱ�߽��� - ֱ��P+tv,Q+tw��Ψһ���㣬���ҽ���Cross(v, w)!=0������ʽ
//����Ҫ�󼫸ߵ�ʱ����Զ��������
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}

//�㵽ֱ�ߵľ��룬����ʽ
double DistanceToLine(Point P, Point A, Point B){
	Vector v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2)) / Length(v1);
}

//�㵽�߶εľ���
double DistanceToSegment(Point P, Point A, Point B){
	if(A == B)
		return Length(P - A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if(dcmp(Dot(v1, v2)) < 0)
		return Length(v2);
	else return fabs(Cross(v1, v2)) / Length(v1);//���߶��Ϸ�
}

//��P��ֱ���ϵ�ͶӰQ������PQ��AB��ֱ
Point GetLineProjection(Point P, Point A, Point B){
	Vector v = B - A;
	return A + v * (Dot(v, P - A) / Dot(v, v));
}

//�߶��ཻ���ж� - ÿ���߶ε�2���˵�����һ���߶�����
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		   c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//�����ڶ˵��ཻ
bool OnSegment(Point p, Point a1, Point a2){
	return dcmp(Cross(a1 - p, a2 - p)) && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

const int N=105;
Point p[N];
int n;

struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point _o,double _r){
		o=_o;
		r=_r;
	}
};

double dis(Point a,Point b){
	Vector ab=a-b;
	return Dot(ab,ab);
}

Circle get_circle(Point p1,Point p2,Point p3){
	double a,b,c,d,e,f,x,y,r;
	a=2*(p2.x-p1.x);
	b=2*(p2.y-p1.y);
	c=Dot(p2,p2)-Dot(p1,p1);
	d=2*(p3.x-p2.x);
	e=2*(p3.y-p2.y);
	f=Dot(p3,p3)-Dot(p2,p2);
	if(b*d-e*a==0){
		if(p1<p2) swap(p1,p2);
		if(p2<p3) swap(p2,p3);
		if(p1<p2) swap(p1,p2);
		x=(p1.x+p3.x)/2;
		y=(p1.y+p3.y)/2;
	}
	else{
		x=(b*f-e*c)/(b*d-e*a);
		y=(d*c-a*f)/(b*d-e*a);
	}
	r=dis(p1,Point(x,y));
	return Circle(Point(x,y),r);
}
Circle min_circle(){
	Circle ret=Circle(p[0],0);
	for(int i=1;i<n;++i){
		if(dis(p[i],ret.o) - ret.r > eps){
			ret=Circle(p[i],0);
			for(int j=0;j<i;++j){
				if(dis(p[j],ret.o) - ret.r > eps){
					ret.o=(p[i]+p[j])/2;
					ret.r=dis(p[j],ret.o);
					for(int k=0;k<j;++k){
						if(dis(p[k],ret.o) - ret.r > eps)
							ret=get_circle(p[i],p[j],p[k]);
					}
				}
			}
		}
	}
	ret.r=sqrt(ret.r);
	return ret;
}

int main(){
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		Circle ans=min_circle();
		printf("%.2lf %.2lf %.2lf\n",ans.o.x,ans.o.y,ans.r);
	}
}
