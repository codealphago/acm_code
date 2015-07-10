/*hdu 4804 Campus Design ������dp
  ���⣺
  ����һ��n*m��01��������Ҫ��Ѿ��������1��1*1��1*2��ש�����������������0Ϊ�ϰ����ʹ��1*1��ש����>=c && <=d �ķ����ж����֡�
  ���ƣ�
  1 <= n <= 100; 1 <= m <= 10; 1 <= c <= d <= 20;
  ˼·��
  ��Ϊ 1 <= m <= 10 ���Կ��Բ���������dp��
  ����״̬�����ڴ�����˵����
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
const int N=105;
char mp[N][15];
LL dp[2][25][1030];
void gao(int n,int m,int c,int d){
	int limit=(1<<m);
	//cout<<limit<<endl;
	int now=0,pre=1;
	memset(dp[now],0,sizeof(dp[now]));
	dp[now][0][limit-1]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			swap(now,pre);
			memset(dp[now],0,sizeof(dp[now]));
			for(int s=0;s<limit;++s){
				//cout<<mp[i][j]<<"!"<<endl;
				if(mp[i][j]=='1'){
					for(int k=0;k<=d;++k){
						if(s & (1<<j))	//����שͷ
							dp[now][k][s ^ (1<<j)]=(dp[now][k][s ^ (1<<j)]+dp[pre][k][s])%MOD;
						if(s & (1<<j))	//����1*1
							dp[now][k+1][s]=(dp[now][k+1][s]+dp[pre][k][s])%MOD;
						if(j && !(s & (1<<(j-1))) && (s & (1<<j))) //���1*2
							dp[now][k][s | (1<<(j-1))]=(dp[now][k][s | (1<<(j-1))] + dp[pre][k][s])%MOD;
						if(i && !(s & (1<<j)))	//����1*2
							dp[now][k][s ^ (1<<j)]=(dp[now][k][s ^ (1<<j)]+dp[pre][k][s])%MOD;
					}
				}
				else{
					for(int k=0;k<=d;++k){
						if(s & (1<<j))	//�ж��ϰ���
							dp[now][k][s]=(dp[now][k][s]+dp[pre][k][s])%MOD;
					}
				}
			}
		}
	}
	//cout<<now<<endl;
	LL ans=0;
	for(int i=c;i<=d;++i)
		ans=(ans+dp[now][i][limit-1])%MOD;
	cout<<ans<<endl;
}
int main(){
	int n,m,c,d;
	while(cin>>n>>m>>c>>d){
		for(int i=0;i<n;++i)
			scanf("%s",mp[i]);
		gao(n,m,c,d);
	}
	return 0;
}
