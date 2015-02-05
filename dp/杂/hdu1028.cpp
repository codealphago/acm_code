/*hdu1028
  ���⣺������֣�����4�����
  4 = 4;
  4 = 3 + 1;
  4 = 2 + 2;
  4 = 2 + 1 + 1;
  4 = 1 + 1 + 1 + 1;
  ���ƣ�1 <= n <= 120
  ˼·��dp
  dp[i][j]��ʾ����i�������jΪ��β�ķ�ʽ�ж�����
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL dp[205][205];
LL ans[205];
int main(){
	dp[1][1]=1;
	for(int i=2;i<=120;++i){
		for(int j=1;j<=i;++j){
			for(int k=j;k<=i-j;++k){
				dp[i][j]+=dp[i-j][k];
			}
		}
		dp[i][i]=1;
	}
	for(int i=1;i<=120;++i)
		for(int j=1;j<=i;++j)
			ans[i]+=dp[i][j];
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",ans[n]);
	}
	return 0;

}

