/*hdu 5234 Happy birthday
  ���⣺
  ������Gorwin�����ա�������������Ҫʵ������һ��Ը����Gorwin˵����Ժܶ൰�⡣������������������˵���԰��
  ���԰�ӱ��ֳ���n*m�������ӡ���ÿһ���������棬��һ�����⡣��i�У���j�еĸ�������һ������Ϊw[i][j]ǧ�˵ĵ��⣬Gorwin�����Ͻ�(1,1)�ĸ��ӿ�ʼ�ߣ��ߵ����½�(n,m)�ĸ��ӡ���ÿһ���У�Gorwin�������һ��������ߣ����ǣ�Gorwinվ��(i,j)��ʱ������������(i+1,j)����(i,j+1) (Ȼ���������߳������԰)��
  ��Gorwin����һ�����ӵ�ʱ�������԰��Ǹ���������ĵ��������߲��ԡ����ǣ�������ֻ��һ���֡�����θ������ô�����������ֻ�ܳ�Kǧ�˵ĵ��⡣���ڣ�Gorwinվ�����Ͻǣ����ڿ�����԰�ĵ�ͼ����Ҫ�ҳ�һ��·���ܹ�ʹ�����Ե��ĵ�������һ��·�����������æ��
  ���ƣ�
  0 < n,m,k,w[i][j] <= 100
  ˼·��
  01����
  �����һά����ά�����ˡ�
  ���Ӷ�O(n^3)
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int a[N][N];
int dp[N][N][N];
void init(){
	memset(dp,0,sizeof(dp));
}
void gao(int n,int m,int v){
	for(int i=a[0][0];i<=v;++i){
		dp[0][0][i]=a[0][0];
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<=v;++j){
			if(j<a[i][0])
				dp[i][0][j]=dp[i-1][0][j];
			else
				dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][0][j-a[i][0]]+a[i][0]);
		}
	}
	for(int i=1;i<m;++i){
		for(int j=0;j<=v;++j){
			if(j<a[0][i])
				dp[0][i][j]=dp[0][i-1][j];
			else
				dp[0][i][j]=max(dp[0][i-1][j],dp[0][i-1][j-a[0][i]]+a[0][i]);
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			for(int k=0;k<=v;++k){
				if(k<a[i][j])
					dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
				else
					dp[i][j][k]=max(max(dp[i-1][j][k],dp[i-1][j][k-a[i][j]]+a[i][j]),max(dp[i][j-1][k],dp[i][j-1][k-a[i][j]]+a[i][j]));
			}
		}
	}
	printf("%d\n",dp[n-1][m-1][v]);
}
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&a[i][j]);
		gao(n,m,k);
	}
	return 0;
}
