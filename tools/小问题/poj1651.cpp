/*poj 1651
  ���⣺
  ����n������a1,a2,...,an��Ҫ�����ȡ���м��n-2����(���˵�������ȡ)��ȡ��ÿ�����Ĵ���Ϊ�����ߵ��������ĳ˻�����ȡ����n-2��������С����Ϊ���٣�
  ���ƣ�
  3 <= n <= 100; 1 <= ai <= 100
  ˼·��
  dp ���仯����
  ����ÿ��������ʵ���ǣ�ö�����ȡ����a[i]��Ȼ�������[l,r]�ָ��[l,i]��[i,r]�����֡�
  dp[l][r]=min(gao(l,i)+a[left]*a[i]*a[right]+gao(i,r))
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=105;
const int INF=0x3f3f3f3f;
int a[N];
LL dp[N][N];
int gao(int l,int r){
	if(dp[l][r]!=-1) return dp[l][r];
	int ret=INF;
	if(l+1==r) return dp[l][r]=0;
	for(int i=l+1;i<r;++i)
		ret=min(ret,gao(l,i)+gao(i,r)+a[l]*a[i]*a[r]);
	//cout<<l<<' '<<r<<' '<<ret<<endl;
	return dp[l][r]=ret;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	printf("%d\n",gao(0,n-1));
	return 0;
}
