/*poj1221
  ���⣺
  ������֣��ԳƲ��
  ���磺4: (4), (1 2 1), (2 2), (1 1 1 1) 
  ����һ������n�����ֵ���������
  ���ƣ�
  0 <= n < 250
  ˼·��
  �������ݽ�С�����Կ��� n^2 ���� n^3 ��dp
  ��dp[i][j]��ʾ������� i ʱ��������С�� j �ķ����ж����֡�
  ���ѵó���
  dp[i][j]=dp[i][j-1] + dp[i-j][min(j,i-j)];
  һ�� n^2 ��dp��
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=250;
LL dp[N][N];
void predo(){
	dp[0][0]=dp[1][1]=1;
	for(int i=2;i<N;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]=dp[i][j-1]+dp[i-j][min(j,i-j)];
		}
	}
}
int n;
void gao(){
	LL ans=0;
	if(n&1){
		for(int i=1;i<=n;i+=2){
			int m=(n-i)/2;
			ans+=dp[m][min(i,m)];
		}
	}
	else{
		ans+=dp[n/2][n/2];
		for(int i=2;i<=n;i+=2){
			int m=(n-i)/2;
			ans+=dp[m][min(i,m)];
		}
	}
	printf("%d %I64d\n",n,ans);
}
int main(){
	predo();
	while(scanf("%d",&n) && n){
		gao();
	}
	return 0;
}
