/*
 * POJ 1743 Musical Theme
 * ��N(1 <= N <=20000)����������������ʾһ��������ÿ����������1..88��Χ�ڵ�����������Ҫ��һ���ظ������⡣
 * "����"�������������е�һ���Ӵ�������Ҫ��������������
 * 1.��������Ϊ5������
 * 2.���������ظ�����(���ܾ���ת����"ת��"����˼������������ÿ�������������ϻ��ȥ��ͬһ������ֵ��)
 * 3.�ظ����ֵ�ͬһ���ⲻ���й������֡�
 * ��ת������������Ĳ�ֵ��Ȼ������Ҳ����ص��ظ��Ӵ���
 * �������Ƕ��ִ�LEN
 * Ȼ�����heightֵ���з���
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN=20010;

/*
*suffix array
*�����㷨  O(n*logn)
*���������鳤��Ϊn,����0~n-1�У�������油һ��0
*build_sa( ,n+1, );//ע����n+1;
*getHeight(,n);
*���磺
*n   = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };ע��num���һλΪ0����������0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]Ϊ��Чֵ��rank[n]�ض�Ϊ0��Чֵ
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]Ϊ��Чֵ��sa[0]�ض�Ϊn����Чֵ
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]Ϊ��Чֵ
*
*/

int sa[MAXN];//SA���飬��ʾ��S��n����׺��С�����������ź����
             //�ĺ�׺�Ŀ�ͷλ��˳�η���SA��
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
int rank[MAXN],height[MAXN];
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
void build_sa(int s[],int n,int m)	//nΪ���鳤��+1��mΪ���������ǿ��ܳ��ֵ��ַ�����
{
    int i,j,p,*x=t1,*y=t2;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j;i<n;i++)y[p++]=i;//�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//�´λ�����������ֵ
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}
int s[MAXN];
bool check(int n,int k)
{
    int Max=sa[1],Min=sa[1];
    for(int i=2;i<=n;i++)
    {
        if(height[i]<k)Max=Min=sa[i];
        else
        {
            if(sa[i]<Min)Min=sa[i];
            if(sa[i]>Max)Max=sa[i];
            if(Max-Min>k)return true;
        }
    }
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)scanf("%d",&s[i]);
        for(int i=n-1;i>0;i--)s[i]=s[i]-s[i-1]+90;
        n--;//����һ������
        for(int i=0;i<n;i++)s[i]=s[i+1];
        s[n]=0;
        build_sa(s,n+1,200);
        getHeight(s,n);
        int ans=-1;
        int l=1,r=n/2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(n,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(ans<4)printf("0\n");
        else printf("%d\n",ans+1);
    }
    return 0;
}
