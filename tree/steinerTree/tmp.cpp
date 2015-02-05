//Minimal Steiner Tree
//G(V,E),A��V��һ���Ӽ��������ٰ���A�����е����С����
//ʱ�临�Ӷ� O(V^3+V*2^A*(2^A+V))
//INIT: d[][]�������; id[]��Ϊ����A�е�ı��;
//CALL: steiner(int n, int a);

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 205; //�ܶ�����
const int A = 7 ;  //Ҫ�����Ķ�����
int id[A];         //������������
int d[N][N];       //�������
int dp[1<<A][N];  //dp[i][j]��ʾ��j����ͨ�ļ���i����̾���

//������Сֵ
void floyd(){
	for(int k=0;k<n;k++)      //vertex 0---n-1
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j] && (d[i][k]!=inf && d[k][j]!=inf))
					d[i][j]=d[i][k]+d[k][j];
}
int stn(int n,int a)
{
	int top = 1<<a;
	
	floyd();	
	
	for(int i=0;i<top;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=inf;

	for(int i=0;i<a;i++)
	{
		for(int j=0;j<n;j++)
			dp[1<<i][j]=d[id[i]][j];
	}
	for(int i=1;i<top;i++)
	{
		if(i&(i-1)==0)
			continue;
		for(int k=0;k<n;k++)   //init
		{
			for(int j=1;j<i;j++)
			{
				if((i|j)==i && dp[i][k]>dp[j][k]+dp[i-j][k])
					dp[i][k]=dp[j][k]+dp[i-j][k];
			}
		}

		for(int j=0;j<n;j++)  //update
		{
			for(int k=0;k<n;k++)
			{
				if(dp[i][j]>dp[i][k]+d[k][j])
					dp[i][j]=dp[i][k]+d[k][j];
			}
		}
	}

	int ans = inf;
	for(int i=0;i<n;i++)
	{
		if(ans > dp[top-1][i])
			ans=dp[top-1][i];
	}
	return ans;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int u,v,c;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n;++i)
		d[i][i]=0;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&c);
		d[u][v]=d[v][u]=c;
	}
	for(int i=0;i<k;++i){
		scanf("%d",&id[i]);
	}
	cout<<stn(n,k)<<endl;
	return 0;
}
