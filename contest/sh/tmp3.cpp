/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/17 4:04:42
File Name     :F:\2013ACM��ϰ\ר��ѧϰ\�����ʷ�\POJ3237Tree.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 100010;
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];//top[v]��ʾv���ڵ������Ķ��˽ڵ�
int fa[MAXN]; //���׽ڵ�
int deep[MAXN];//���
int num[MAXN];//num[v]��ʾ��vΪ���������Ľڵ���
int p[MAXN];//p[v]��ʾv���丸�׽ڵ���������߶����е�λ��
int fp[MAXN];//��p�����෴
int son[MAXN];//�ض���
int pos;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 0;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfs1(int u,int pre,int d) //��һ��dfs���fa,deep,num,son
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}
void getpos(int u,int sp) //�ڶ���dfs���top��p
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u],sp);
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

//�߶���
struct Node
{
    int l,r;
    int Max;
    int Min;
    int ne;
}segTree[MAXN*3];
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].Max = 0;
    segTree[i].Min = 0;
    segTree[i].ne = 0;
    if(l == r)return;
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
    segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    segTree[i].Min = min(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
}
void push_down(int i)
{
    if(segTree[i].l == segTree[i].r)return;
    if(segTree[i].ne)
    {
        segTree[i<<1].Max = -segTree[i<<1].Max;
        segTree[i<<1].Min = -segTree[i<<1].Min;
        swap(segTree[i<<1].Min,segTree[i<<1].Max);
        segTree[(i<<1)|1].Max = -segTree[(i<<1)|1].Max;
        segTree[(i<<1)|1].Min = -segTree[(i<<1)|1].Min;
        swap(segTree[(i<<1)|1].Max,segTree[(i<<1)|1].Min);
        segTree[i<<1].ne ^= 1;
        segTree[(i<<1)|1].ne ^= 1;
        segTree[i].ne = 0;
    }
}
void update(int i,int k,int val) // �����߶����ĵ�k��ֵΪval
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max = val;
        segTree[i].Min = val;
        segTree[i].ne = 0;
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}
void ne_update(int i,int l,int r) // �����߶���������[l,r]ȡ��
{
    if(segTree[i].l == l && segTree[i].r == r)
    {
        segTree[i].Max = -segTree[i].Max;
        segTree[i].Min = -segTree[i].Min;
        swap(segTree[i].Max,segTree[i].Min);
        segTree[i].ne ^= 1;
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)ne_update(i<<1,l,r);
    else if(l > mid) ne_update((i<<1)|1,l,r);
    else
    {
        ne_update(i<<1,l,mid);
        ne_update((i<<1)|1,mid+1,r);
    }
    push_up(i);
}
int query(int i,int l,int r)  //��ѯ�߶�����[l,r] �����ֵ
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].Max;
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return query(i<<1,l,r);
    else if(l > mid)return query((i<<1)|1,l,r);
    else return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
    push_up(i);
}
int findmax(int u,int v)//��ѯu->v�ߵ����ֵ
{
    int f1 = top[u], f2 = top[v];
    int tmp = -100000000;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp = max(tmp,query(1,p[f1],p[u]));
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query(1,p[son[u]],p[v]));
}
void Negate(int u,int v)//��u-v·���ϵıߵ�ֵ������Ϊval
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        ne_update(1,p[f1],p[u]);
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return;
    if(deep[u] > deep[v]) swap(u,v);
    return ne_update(1,p[son[u]],p[v]);
}
int e[MAXN][3];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
            addedge(e[i][0],e[i][1]);
            addedge(e[i][1],e[i][0]);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        for(int i = 0;i < n-1; i++)
        {
            if(deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update(1,p[e[i][1]],e[i][2]);
        }
        char op[10];
        int u,v;
        while(scanf("%s",op) == 1)
        {
            if(op[0] == 'D')break;
            scanf("%d%d",&u,&v);
            if(op[0] == 'Q')
                printf("%d\n",findmax(u,v));//��ѯu->v·���ϱ�Ȩ�����ֵ
            else if(op[0] == 'C')
                update(1,p[e[u-1][1]],v);//�ı��u���ߵ�ֵΪv
            else Negate(u,v);
        }
    }
    return 0;
}
