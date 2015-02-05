/*poj 2411
  ��Ŀ��˼����һ��n*m�ľ������򣬽�1*2��2*1��С��������������һ���ж��������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
int n,m;
LL dp[12*12][1<<12];
int main(){
	while(scanf("%d%d",&n,&m) && (n||m)){
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int cur,next;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cur=i*m+j,next=i*m+j+1;
				for(int k=0;k<(1<<m);++k){
					// ����Ѿ����ˣ��Ǿ�ֱ��ת��
					if((k>>j) & 1){
						dp[next][k &~ (1<<j)] += dp[cur][k];
					}
					else{
						//�����Ժ��
						if(j+1<m && !(k>>(j+1) & 1)){
							dp[next][k | 1<<(j+1)]+=dp[cur][k];
						}
						// ��������
						if(i+1<n){
							dp[next][k | 1<<j]+=dp[cur][k];
						}
					}
				}
			}
		}
		printf("%lld\n",dp[next][0]);
	}
	return 0;
}
