/*hdu 5072
  ���⣺
  ����n����a1,a2,...,an, ����ѡ��������a,b,c,��������������[(a,b)=(b,c)=(a,c)=1] || [(a,b)!=1 && (b,c)!=1 && (a,c)!=1] ����(x,y)��ʾx,y�����Լ��������������������Ԫ��ĸ�����
  ���ƣ�
  3 <= n <= 1e5; 1 <= ai <= 1e5
  ˼·��
  ��biΪ��ai���ʵ����ĸ�������������� !(((a,b)=(b,c)=(a,c)=1) || ((a,b)!=1 && (b,c)!=1 && (a,c)!=1)) ����Ԫ��ĸ���Ϊ��
  t=(sigma(1~n)bi*(n-1-bi))/2
  ���Կ���C(n,3)-t��Ϊ�𰸡�
  ����֤������ʽ�ӵ�������
  �����������������a,b,c������6�������
  1. (a,b)=1 && (a,c)!=1 && (b,c)=1
  2. (a,b)=1 && (a,c)!=1 && (b,c)!=1
  3. (a,b)!=1 && (a,c)=1 && (b,c)=1
  4. (a,b)!=1 && (a,c)=1 && (b,c)!=1
  5. (a,b)=1 && (a,c)=1 && (b,c)!=1
  6. (a,b)!=1 && (a,c)!=1 && (b,c)=1
  ���ǿ��Է���bi*(n-1-bi)ֻ�����������1~4��������������ַ���ʣ���������������b��c������
  ��ʵ����1~6�������ÿ�������������������
  1. ��a,c����
  2. ��a,b����
  ...
  ���������еļ�����/2

  Ȼ������ͱ�����Ϊ����ÿ�������ڸ��Ӷ�����������ʵ����ĸ���������������ݳ�����Ҳ������Ī����˹��������
  ����һ����������x0
  ��f(k)Ϊgcd(x0,x)=k��x����Ŀ
  ��F(k)Ϊgcd(x0,x)Ϊk�ı�����x����Ŀ��Ȼ����F(k)Ϊӵ������k��ai����Ŀ�����������O(sqrt(ai))ö������Ԥ���������
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N=1e5+5;
vector<int> fac[N];
int tab[N];
int cnt[N];
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}
void gao(int n){
	for(int i=0;i<n;++i){
		cnt[i]=n;
		if(fac[i][0]==1){ --cnt[i]; continue; }
		for(int j=0;j<fac[i].size();++j){
			//cout<<fac[i][j]<<' ';
			cnt[i]+=mu[fac[i][j]]*tab[fac[i][j]];
		}
		//cout<<endl;
	}
	LL ans=(LL)n*(n-1)*(n-2)/6,tmp=0;
	for(int i=0;i<n;++i){
		tmp+=(LL)cnt[i]*(n-1-cnt[i]);
	}
	ans=ans-tmp/2;
	printf("%I64d\n",ans);
	//for(int i=0;i<n;++i)
	//	cout<<cnt[i]<<' ';
	//cout<<endl;
}
void init(int n){
	memset(tab,0,sizeof(tab));
	for(int i=0;i<n;++i) fac[i].clear();
}
int main(){
	getMu();
	int T;
	int n,a;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			int lim=sqrt(a);
			++tab[a];
			fac[i].PB(a);
			for(int j=2;j<=lim;++j){
				if(a%j==0){
					int tmp=a/j;
					++tab[j];
					fac[i].PB(j);
					if(tmp!=j){
						++tab[tmp];
						fac[i].PB(tmp);
					}
				}
			}
		}
		gao(n);
	}
	return 0;
}
