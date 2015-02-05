/*
POJ 1330
�����㷨

*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

const int MAXN=10010;

int F[MAXN];//���鼯
int r[MAXN];//���鼯�м��ϵĸ���
bool vis[MAXN];//���ʱ��
int ancestor[MAXN];//����
struct Node
{
    int to,next;
}edge[MAXN*2];

int head[MAXN];
int tol;
void addedge(int a,int b)
{
    edge[tol].to=b;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].next=head[b];
    head[b]=tol++;
}


struct Query
{
    int q,next;
    int index;//��ѯ���
}query[MAXN*2];//��ѯ��
int answer[MAXN*2];//��ѯ���
int cnt;
int h[MAXN];
int tt;
int Q;//��ѯ����


void add_query(int a,int b,int i)
{
    query[tt].q=b;
    query[tt].next=h[a];
    query[tt].index=i;
    h[a]=tt++;
    query[tt].q=a;
    query[tt].next=h[b];
    query[tt].index=i;
    h[b]=tt++;
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        F[i]=-1;
        r[i]=1;
        vis[i]=false;
        ancestor[i]=0;
        tol=0;
        tt=0;
        cnt=0;//�Ѿ���ѯ���ĸ���
    }
    memset(head,-1,sizeof(head));
    memset(h,-1,sizeof(h));
}
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}

void Union(int x,int y)//�ϲ�
{
    int t1=find(x);
    int t2=find(y);
    if(t1!=t2)
    {
        if(r[t1]<=r[t2])
        {
            F[t1]=t2;
            r[t2]+=r[t1];
        }
        else
        {
            F[t2]=t1;
            r[t1]+=r[t2];
        }
    }
}


void LCA(int u)
{
    //if(cnt>=Q)return;//��Ҫ�����
    ancestor[u]=u;
    vis[u]=true;//���һ��Ҫ����ǰ��
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(vis[v])continue;
        LCA(v);
        Union(u,v);
        ancestor[find(u)]=u;
    }
    for(int i=h[u];i!=-1;i=query[i].next)
    {
        int v=query[i].q;
        if(vis[v])
        {
            answer[query[i].index]=ancestor[find(v)];
            cnt++;//�Ѿ��ҵ��Ĵ���
        }
    }
}
bool flag[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int N;
    int u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init(N);
        memset(flag,false,sizeof(flag));
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            flag[v]=true;
            addedge(u,v);
        }
        Q=1;//��ѯֻ��һ��
        scanf("%d%d",&u,&v);
        add_query(u,v,0);//����һ���ѯ
        int root;
        for(int i=1;i<=N;i++)
          if(!flag[i])
          {
              root=i;
              break;
          }
        LCA(root);
        for(int i=0;i<Q;i++)//������д�
          printf("%d\n",answer[i]);
    }
    return 0;
}
