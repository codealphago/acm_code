/* ��Ҫ������ͷ�ļ� */
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
/* �������� */
const double INF = 1E200;
const double EP = 1E-11;
const int MAXV = 300;
const double PI = acos(-1.0);
/* �������νṹ */
struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;}
};
struct LINESEG
{
    POINT s;
    POINT e;
    double a, b, c;//һ��ʽ,ax+by+c=0
    LINESEG(POINT _s, POINT _e) { s=_s; e=_e;}
    LINESEG() { }
};
// ֱ�ߵĽ������� a*x+b*y+c=0 Ϊͳһ��ʾ��Լ�� a>= 0
struct LINE
{
    double a;
    double b;
    double c;
    LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;}
};
//�߶���
struct LINETREE
{
};
//�������Ĵ���
int dblcmp(double d)
{
    if(fabs(d)<EP)
        return 0 ;
    return (d>0) ?1 :-1 ;
}
// ��������֮��ŷ�Ͼ���
double dist(POINT p1,POINT p2)
{
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
// �ж��������Ƿ��غ�
bool equal_point(POINT p1,POINT p2)
{
    return ( (abs(p1.x-p2.x)<EP)&&(abs(p1.y-p2.y)<EP) );
}
/*(sp-op)*(ep-op)�Ĳ��
  r=multiply(sp,ep,op),�õ�(sp-op)*(ep-op)�Ĳ��
  r>0:sp��ʸ��op ep��˳ʱ�뷽��
  r=0��op sp ep���㹲�ߣ�
  r<0: sp��ʸ��op ep����ʱ�뷽�� */
double multiply(POINT sp,POINT ep,POINT op)
{
    return((sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y));
}
double amultiply(POINT sp,POINT ep,POINT op)
{
    return fabs((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
/*ʸ��(p1-op)��(p2-op)�ĵ��
  r=dotmultiply(p1,p2,op),�õ�ʸ��(p1-op)��(p2-op)�ĵ���������ʸ��������ʸ��
  r < 0: ��ʸ���н�Ϊ��ǣ�
  r = 0����ʸ���н�Ϊֱ�ǣ�
  r > 0: ��ʸ���н�Ϊ�۽� */
double dotmultiply(POINT p1,POINT p2,POINT p0)
{
    return ((p1.x-p0.x)*(p2.x-p0.x) + (p1.y-p0.y)*(p2.y-p0.y));
}
/* �жϵ�p�Ƿ����߶�l��
   ������(p���߶�l���ڵ�ֱ����)&& (��p�����߶�lΪ�Խ��ߵľ�����) */
bool online(LINESEG l,POINT p)
{
    return ((multiply(l.e,p,l.s)==0)
            && ( ( (p.x-l.s.x) * (p.x-l.e.x) <=0 ) && ( (p.y-l.s.y)*(p.y-l.e.y) <=0 ) ) );
}
// ���ص�p�Ե�oΪԲ����ʱ����תalpha(��λ������)�����ڵ�λ��
POINT rotate(POINT o,double alpha,POINT p)
{
    POINT tp;
    p.x -=o.x;
    p.y -=o.y;
    //cout<<alpha<<endl;
    tp.x=p.x*cos(alpha) - p.y*sin(alpha)+o.x;
    tp.y=p.y*cos(alpha) + p.x*sin(alpha)+o.y;
    //cout<<tp.x<<' '<<tp.y<<endl;
    return tp;
}
/* ���ض�����o�㣬��ʼ��Ϊos����ֹ��Ϊoe�ļн�(��λ������)
   �Ƕ�С��pi��������ֵ
   �Ƕȴ���pi�����ظ�ֵ
   �����������߶�֮��ļн� */
double angle(POINT o,POINT s,POINT e)
{
    /*cout<<o.x<<' '<<o.y<<endl;
    cout<<s.x<<' '<<s.y<<endl;
    cout<<e.x<<' '<<e.y<<endl;*/
    double cosfi,fi,norm;
    double dsx = s.x - o.x;
    double dsy = s.y - o.y;
    double dex = e.x - o.x;
    double dey = e.y - o.y;
    //cout<<dsx<<' '<<dsy<<' '<<dex<<' '<<dey<<endl;
    cosfi=dsx*dex+dsy*dey;

    norm=(dex*dex+dey*dey)*(dsx*dsx+dsy*dsy);
    cosfi /= sqrt( norm );
    //cout<<cosfi<<endl;
    if (cosfi >= 1.0 ) return 0;
    if (cosfi <= -1.0 ) return PI;
    fi=acos(cosfi);
    if (dsx*dey-dsy*dex>0) return fi; // ˵��ʸ��os ��ʸ�� oe��˳ʱ�뷽��
    return 2*PI-fi;
}

LINESEG ppline(POINT _a, POINT _b)
{
    LINESEG ret;
    ret.s.x = (_a.x + _b.x) / 2;
    ret.s.y = (_a.y + _b.y) / 2;
    //һ��ʽ
    ret.a = _b.x - _a.x;
    ret.b = _b.y - _a.y;
    ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
    //����ʽ
    if(fabs(ret.a) > EP)
    {
        ret.e.y = 0.0;
        ret.e.x = - ret.c / ret.a;
        if(fabs(ret.e.x-ret.s.x)<EP && fabs(ret.e.y-ret.s.y)<EP) //
        {
            ret.e.y = 1e10;
            ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
        }
    }
    else
    {
        ret.e.x = 0.0;
        ret.e.y = - ret.c / ret.b;
        if(fabs(ret.e.x-ret.s.x)<EP && fabs(ret.e.y-ret.s.y)<EP) //
        {
            ret.e.x = 1e10;
            ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
        }
    }
    return ret;
}

/* �жϵ�C���߶�AB���ڵ�ֱ��l�ϴ���P�����߶�AB�Ĺ�ϵ
   �������Ǹ�������Ĺ�ʽд�ģ�P�ǵ�C���߶�AB����ֱ�ߵĴ���
   AC dot AB
   r = ----------------------
   ||AB||^2
   (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
   = ----------------------------------------------------
   L^2
   r has the following meaning:
   r=0 P = A
   r=1 P = B
   r<0 P is on the backward extension of AB
   r>1 P is on the forward extension of AB
   0<r<1 P is interior to AB
 */
double relation(POINT c,LINESEG l)
{
    LINESEG tl;
    tl.s=l.s;
    tl.e=c;
    return dotmultiply(tl.e,l.e,l.s)/(dist(l.s,l.e)*dist(l.s,l.e));
}
// ���C���߶�AB����ֱ�ߵĴ��� P
POINT perpendicular(POINT p,LINESEG l)
{
    double r=relation(p,l);
    POINT tp;
    tp.x=l.s.x+r*(l.e.x-l.s.x);
    tp.y=l.s.y+r*(l.e.y-l.s.y);
    return tp;
}
/* ���p���߶�l����̾���
   �����߶��Ͼ�õ�����ĵ�np ע�⣺np���߶�l�ϵ���p����ĵ㣬��һ���Ǵ��� */
double ptolinesegdist(POINT p,LINESEG l,POINT &np)
{
    double r=relation(p,l);
    if(r<0)
    {
        np=l.s;
        return dist(p,l.s);
    }
    if(r>1)
    {
        np=l.e;
        return dist(p,l.e);
    }
    np=perpendicular(p,l);
    return dist(p,np);
}
// ���p���߶�l����ֱ�ߵľ���
//��ע�Ȿ�������ϸ�����������
double ptoldist(POINT p,LINESEG l)
{
    return abs(multiply(p,l.e,l.s))/dist(l.s,l.e);
}
/* ����㵽���߼����������,�����������.
   ע�⣺���õ���ptolineseg()���� */
double ptopointset(int vcount, POINT pointset[], POINT p, POINT &q)
{
    int i;
    double cd=double(INF),td;
    LINESEG l;
    POINT tq,cq;
    for(i=0;i<vcount-1;i++)
    {
        l.s=pointset[i];
        l.e=pointset[i+1];
        td=ptolinesegdist(p,l,tq);
        if(td<cd)
        {
            cd=td;
            cq=tq;
        }
    }
    q=cq;
    return cd;
}
/* �ж�Բ�Ƿ��ڶ������*/
bool CircleInsidePolygon(int vcount,POINT center,double radius,POINT polygon[])
{
    POINT q;
    double d;
    q.x=0;
    q.y=0;
    d=ptopointset(vcount,polygon,center,q);
    if(d<radius||fabs(d-radius)<EP) return true;
    else return false;
}
/* ��������ʸ��l1��l2�ļнǵ����� (-1 ~ 1)
   ע�⣺������������нǵĻ���ע�ⷴ���Һ�����ֵ���Ǵ� 0��pi */
double cosine(LINESEG l1,LINESEG l2)
{
    return(((l1.e.x-l1.s.x)*(l2.e.x-l2.s.x)+(l1.e.y-l1.s.y)*(l2.e.y-l2.s.y))/(dist(l1.e,l1.s)*dist(l2.e,l2.s)));
}
// �����߶�l1��l2֮��ļн�
//��λ������ ��Χ(-pi��pi)
double lsangle(LINESEG l1,LINESEG l2)
{
    POINT o,s,e;
    o.x=o.y=0;
    s.x=l1.e.x-l1.s.x;
    s.y=l1.e.y-l1.s.y;
    e.x=l2.e.x-l2.s.x;
    e.y=l2.e.y-l2.s.y;
    return angle(o,s,e);
}
//�ж��߶�u��v�ཻ(�����ཻ�ڶ˵㴦)
bool intersect(LINESEG u,LINESEG v)
{
    return ( (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&& //�ų�ʵ��
            (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
            (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
            (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
            (multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>=0)&& //����ʵ��
            (multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0));
}
// �ж��߶�u��v�ཻ��������˫���Ķ˵㣩
bool intersect_A(LINESEG u,LINESEG v)
{
    return ((intersect(u,v)) &&
            (!online(u,v.s)) &&
            (!online(u,v.e)) &&
            (!online(v,u.e)) &&
            (!online(v,u.s)));
}
// �ж��߶�v����ֱ�����߶�u�ཻ
bool intersect_l(LINESEG u,LINESEG v)
{
    return multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0;
}
// ������֪�������꣬����������ֱ�߽������̣� a*x+b*y+c = 0 (a >= 0)
LINE makeline(POINT p1,POINT p2)
{
    LINE tl;
    int sign = 1;
    tl.a=p2.y-p1.y;
    if(tl.a<0)
    {
        sign = -1;
        tl.a=sign*tl.a;
    }
    tl.b=sign*(p1.x-p2.x);
    tl.c=sign*(p1.y*p2.x-p1.x*p2.y);
    return tl;
}
// ����ֱ�߽������̷���ֱ�ߵ�б��k,ˮƽ�߷��� 0,��ֱ�߷��� 1e200
double slope(LINE l)
{
    if(abs(l.a) < 1e-20)return 0;
    if(abs(l.b) < 1e-20)return INF;
    return -(l.a/l.b);
}
// ����ֱ�ߵ���б��alpha ( 0 - pi)
// ע�⣺atan()���ص��� -PI/2 ~ PI/2
double alpha(LINE l)
{
    if(abs(l.a)< EP)return 0;
    if(abs(l.b)< EP)return PI/2;
    double k=slope(l);
    if(k>0)
        return atan(k);
    else
        return PI+atan(k);
}
// ���p����ֱ��l�ĶԳƵ�
POINT symmetry(LINE l,POINT p)
{
    POINT tp;
    tp.x=((l.b*l.b-l.a*l.a)*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/(l.a*l.a+l.b*l.b);
    tp.y=((l.a*l.a-l.b*l.b)*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/(l.a*l.a+l.b*l.b);
    return tp;
}
// �������ֱ�� l1(a1*x+b1*y+c1 = 0), l2(a2*x+b2*y+c2 = 0)�ཻ������true���ҷ��ؽ���p
bool lineintersect(LINE l1,LINE l2,POINT &p) // �� L1��L2
{
    double d=l1.a*l2.b-l2.a*l1.b;
    if(abs(d)<EP) // ���ཻ
        return false;
    p.x = (l2.c*l1.b-l1.c*l2.b)/d;
    p.y = (l2.a*l1.c-l1.a*l2.c)/d;
    return true;
}
// ����߶�l1��l2�ཻ������true�ҽ�����(inter)���أ����򷵻�false
bool intersection(LINESEG l1,LINESEG l2,POINT &inter)
{
    LINE ll1,ll2;
    ll1=makeline(l1.s,l1.e);
    ll2=makeline(l2.s,l2.e);
    if(lineintersect(ll1,ll2,inter)) return online(l1,inter);
    else return false;
}

int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
    double du;
    POINT p[4],o;
    p[0].x=p[0].y=3.1415;
    p[2].x=p[2].y=31.415;
    scanf("%d",&n);
    p[1]=p[0];
    p[3]=p[2];
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf",&o.x,&o.y,&du);
        p[1]=rotate(o,du,p[1]);
        p[3]=rotate(o,du,p[3]);
    }
    LINESEG l1=ppline(p[0],p[1]),
            l2=ppline(p[2],p[3]);
    POINT anso;
    intersection(l1,l2,anso);
    double ansdu;
    ansdu=angle(anso,p[2],p[3]);
    printf("%.10lf %.10lf %.10lf\n",anso.x,anso.y,ansdu);
    }
    return 0;
}
