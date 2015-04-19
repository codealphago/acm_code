const double EPS=1e-10;
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){ x=_x; y=_y; }
	Point operator + (Point p){ return Point(x+p.x,y+p.y); }
	Point operator - (Point p){ return Point(x-p.x,y-p.y); }
	Point operator * (double d){ return Point(d*x,d*y); }
	double dot(Point p){ return x*p.x+y*p.y; }	//�ڻ�
	double det(Point p){ return x*p.y-p.x*y; }
};
bool cmpxy(const Point &p,const Point &q){
	if(p.x!=q.x) return p.x<q.x;
	return p.y<q.y;
}
vector<Point> convex_hull(Point *ps,int n){	//͹��Ҫע���˻���2���㣬1��������
	sort(ps,ps+n,cmpxy);
	int k=0;
	vector<Point> qs(n*2);	//�����е�͹��
	for(int i=0;i<n;++i){	//����͹�����²�
		while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
		qs[k++]=ps[i];
	}
	for(int i=n-2,t=k;i>=0;--i){	//����͹�����ϲ�
		while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}
int main(){
	vector<Point> qs=convex_hull(ps,n);
	return 0;
}
