//��n���εķ����
//���ҵ�һ����ʹ������㵽n����ľ���֮����С
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
const double inf = 1e10;
const double pi = acos(-1.0);
const int Rp = 4;//��ʼʱ���ѡ��һЩ�㣬����̫��
const int shift = 60;//���Ƿ���һ��Ҫ��
struct point {
    double x,y;
    void goto_rand_dir(double key)
    {
        double d=2*pi*(double)rand()/RAND_MAX;
        x+=key*sin(d);
        y+=key*cos(d);
    }
    void Get_Rand_Point(int a,int b)
    {
        x=rand()%a+1;
        y=rand()%b+1;
    }
}p[1010],randp[Rp];
double Dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dis[Rp];
int main()
{
    int i,j,x,y,k,m;
    srand(time(NULL));
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        x=10000;y=10000;
        double tmp;
        for(i=0;i<Rp;i++)
        {
            dis[i]=inf;
            randp[i].Get_Rand_Point(x,y);
            tmp=0;
            for(j=0;j<m;j++)
            {
                tmp+=Dis(randp[i],p[j]);    
            }
            if(tmp<dis[i])
                dis[i]=tmp;
        }
        double key=sqrt(1.0*(x*x+y*y));//��ʼ�Ĳ�����Ҫ��֤��ʼ��Ӹõ�����϶��ܰ�����������
        while(key>=0.01)
        {
            for(i=0;i<Rp;i++)
            {
                for(j=0;j<shift;j++)
                {
                    point cc=randp[i];
                    cc.goto_rand_dir(key);
                    if(cc.x<0||cc.y<0||cc.x>x||cc.y>y) continue;
                    tmp=0;
                    for(k=0;k<m;k++)
                    {
                        tmp+=Dis(cc,p[k]);
                    }
                    if(tmp<dis[i]) //�����i���������ƶ��ĵ��ԭ���ĵ���ţ�����ܸ��ƶ�
                    {
                        dis[i]=tmp;
                        randp[i]=cc;
                    }
                }
            }
            key=key*0.6;//��������
        }
        for(i=k=0;i<Rp;i++)
            if(dis[i]<dis[k])
                k=i;
            printf("%.0lf\n",dis[k]);
    }
    return 0;
}
