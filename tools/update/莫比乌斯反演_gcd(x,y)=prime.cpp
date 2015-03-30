/*spoj 4491
  ���⣺
  ����a,b����gcd(x,y)=prime�ķ����������У�1 <= x <= a && 1 <= y <= b
  ���ƣ�
  1 <= a,b <= 1e7
  ˼·��
  �Ȱ�������һ��һ�������ǣ�Ȼ������ͱ��gcd(x,y)=k�ķ�������
  ��f(k)Ϊgcd(x,y)=k�ķ�������
  ��F(k)Ϊgcd(x,y)Ϊk�ı����ķ���������ȻF(k)=floor(a/k)*floor(b/k)��
  ��Ī����˹���ݵã�
  f(k)=mu[1]*F[k]+mu[2]*F[2*k]+...
  ���ԣ�
  ans=f(prime[1])+f(prime[2])+...	---1ʽ

  ��"1ʽ"չ�����֣�����ÿ��F(k)��������˵�Ī����˹ϵ���У�mu[i]������i<k && k%i=0 && k/i=prime��
  ��cnt[k]=sigma(mu[i])������i<k && k%i=0 && k/i=prime��
  ����ҪԤ�����cnt[]������Ԥ����ᳬʱ������Ҫ����Ī����˹���������ʣ�
  �����������
  1. cnt[k]=1 ����kΪ����
  2. cnt[i*prime]=-cnt[i]+mu[i] ����i%prime!=0
  3. cnt[i*prime]=mu[i] ����i%prime=0

  �����µ�2�㣺
  ������i���ҽ�����������ͬ��prime��ɣ���Ϊi%prime!=0������i*prime��ż����prime��ɣ�����cnt[i]�������϶���Ϊ����һ����ͬ����prime��������Լ����෴����Ȼ�����mu[i]��
  �磺
  cnt[6]=mu[2]+mu[3]
  cnt[30]=cnt[6*5]=mu[10]+mu[15]+mu[6]=mu[2*5]+mu[3*5]+mu[6]=(-mu[2])+(-mu[3])+mu[6]

  ���ڵ�3�㣺
  ��Ϊi%prime==0������i���Ѿ�����prime������i*prime���溬������prime������cnt[i]�е���϶���Ϊ����һ����ͬ������Ȼ����0���������cnt[i]=mu[i]��
  �磺
  cnt[6]=mu[2]+mu[3]
  cnt[18]=mu[6*3]=mu[6]+mu[9]=mu[6]+mu[3*3]=mu[6]+0

  ���ʣ�µľ�ֻ�зֿ�������ˡ�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
#define LL long long
const int N=1e7+5;
const int MOD=1000000007; 
int mu[N],pri[N],pcnt;
bool vis[N];
int cnt[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
			//cnt[i]=1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]){
			   mu[i*pri[j]]=-mu[i];
			   //cnt[i*pri[j]]=-cnt[i]+mu[i];
			}
			else{
				mu[i*pri[j]]=0;
				//cnt[i*pri[j]]=mu[i];
				break;
			}
		}
	}
}
LL sum[N];
//0 1 1 -1 1 -2 1 0 -1 -2
void predo(){
	for(int i=2;i<N;++i){
		if(!vis[i]) cnt[i]=1;
		for(int j=0;j<pcnt && pri[j]<=i && i*pri[j]<N;++j){
			if(i%pri[j]) cnt[i*pri[j]]=-cnt[i]+mu[i];
			else{ cnt[i*pri[j]]=mu[i]; break; }
		}
	}
	//for(int i=0;i<pcnt;++i){
	//	int lim=N/pri[i];
	//	for(int j=1;j<lim;++j){
	//		cnt[j*pri[i]]+=mu[j];
	//	}
	//}
	for(int i=1;i<=N;++i)
		sum[i]=sum[i-1]+cnt[i];
}
int main(){
	getMu();
	predo();
	int T;
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		LL ans=0;
		for(int i=1,ls=0;i<=min(a,b);i=ls+1){	//�ֿ�
			ls=min(a/(a/i),b/(b/i));
			ans+=((LL)sum[ls]-sum[i-1])*(a/i)*(b/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
