ZJUT 1423

/*

�����Թ�

Description:
����ɽ�廬�£�DK�������˵���֩�������Թ���Ϊ������DH֮ǰ��
��TFT��DK���뾡���߳����Թ������Թ�����һ�����ڣ������ڴ�BOSS
����������Ӱ�쵽��DK��ʹDK�ļ����������½����������޷��ǵ���
��һ������ʲô��������ֻ��ÿ�εȸ��������ѡȡһ�������ߡ�
��Ȼ������ѡȡ��Χ���ϰ��ĵط��ߡ���DK��Χֻ�������յأ���ÿ
������1/2�ĸ��ʡ�����Ҫ����ƽ��Ҫ�߶��ٲ������߳����Թ���

Input:
����һ����������N, M(1<=N, M<=10)��ʾ�Թ�ΪN*M��С��
Ȼ����N�У�ÿ��M���ַ���'.'��ʾ�ǿյأ�'E����ʾ���ڣ�'D����ʾDK��'X����ʾ�ϰ���
Output:
���DK�޷��߳���Ҫ����1000000�������߳������tragedy!��
�������һ��ʵ����ʾƽ�������DKҪ�߼��������߳��Թ����������뵽С�������λ��
Sample Input:
2
ED
3
D.X
.X.
X.E
Sample Output:
1.00
tragedy!


���ȶԵ�ͼ�ڵ����±�š�����E[i]��ʾDK��i�㿪ʼ�߳��Թ�������ֵ��
��ôE[i]=(E[a1]+E[a2]+E[a3]+...+E[an])/n+1������a1...an��i�����ڽڵ㡣
��ô����ÿһ��DK�ɴ�Ľڵ���˵��������Ϊ������������һ�����̡���
�ڼ���DK�ɴ�ĵ���N������ô�������ս���õ�NԪһ�η����顣���
���ø�˹��Ԫ���E[No[S]]������S��DK����㣬No[S]���ر�ź�����
����Ҫ�ص�ע����ǣ������������̵�ʱ��һ��Ҫע��DK�ɴ����������
��Ȼ�ͻᵼ���޽�������

*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

#define eps 1e-9
const int MAXN=200;
double a[MAXN][MAXN],x[MAXN];//���̵���ߵľ���͵�ʽ�ұߵ�ֵ�����֮��x��ľ��ǽ��
int equ,var;//��������δ֪������

int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
          if(fabs(a[i][col])>fabs(a[max_r][col]))
            max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
              swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
          if(i!=k)
          {
              x[i]-=x[k]*a[i][k];
              for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
              a[i][col]=0;
          }
    }
    return 1;
}

char map[20][20];
int num[20][20];
struct Node
{
    int x,y;
};
int sx,sy,ex,ey;
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cnt;

void bfs()
{
    memset(num,-1,sizeof(num));
    cnt=0;
    num[sx][sy]=cnt++;
    queue<Node>que;
    Node temp;
    Node tt;
    temp.x=sx;temp.y=sy;
    que.push(temp);
    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            tt.x=temp.x+dir[i][0];
            tt.y=temp.y+dir[i][1];
            if(tt.x>=0&&tt.x<n&&tt.y>=0&&tt.y<m&&map[tt.x][tt.y]!='X'&&num[tt.x][tt.y]==-1)
            {
                num[tt.x][tt.y]=cnt++;
                que.push(tt);
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",&map[i]);
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='D')
                {
                    sx=i;sy=j;
                }
                if(map[i][j]=='E')
                {
                    ex=i;ey=j;
                }
            }
        }
        bfs();
        if(num[ex][ey]==-1)
        {
            printf("tragedy!\n");
            continue;
        }
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));
        equ=var=cnt;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           if(num[i][j]!=-1)
           {
               int now=num[i][j];
               if(map[i][j]=='E')
               {
                   memset(a[now],0,sizeof(a[now]));
                   x[now]=0;
                   a[now][now]=1;
                   continue;
               }

               int Count=0;
               for(int k=0;k<4;k++)
               {
                   int tx=i+dir[k][0];
                   int ty=j+dir[k][1];
                   if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='X'&&num[tx][ty]!=-1)
                   {
                       a[now][num[tx][ty]]=-1;
                       Count++;
                   }
                   a[now][now]=Count;
                   x[now]=Count;
               }
           }
        if(Gauss())
        {
            if(x[num[sx][sy]]<=1000000)printf("%.2lf\n",x[num[sx][sy]]);
            else printf("tragedy!\n");
        }
        else printf("tragedy!\n");
    }
    return 0;
}
