/*hdu 5168 Legal path
  ���⣺
  һ������ͼ����������յ㣬ÿ��������Ȩֵ��
  һ���Ϸ���·������Ϊ���ڱߵ�Ȩֵ֮�С��K��·������·����ÿ���ߵ�Ȩֵ����Ҫ����һ���ߵ�Ȩֵ��K�������һ���ߴ��ڡ��Ϸ�·���ĳ��ȶ���Ϊ·���ϵı�Ȩֵ�ܺ͡�
  �����㵽�յ�ĺϷ�·������̳��ȡ�
  ���ƣ�
  �ж������ݣ���һ��Ϊ��������T��T��10����
  ����ÿ�����ݣ���һ��Ϊ��������n,m,K��n,m�ֱ��ʾ�������ݵ�����ͼ�ĵ��������������Ϊ1�ŵ㣬�յ�Ϊn�ŵ㡣
  �ڽ�������m�У�ÿ������������x,y,z����ʾ��x��y��һ��ȨֵΪz�ıߡ�
  2 <= n <= 100,000
  0 <= m <= 200,000
  1 <= K,z <= 1,000,000,000
  1 <= x,y <= n
  ˼·��
  �Ȱ����б߰�Ȩֵ��С����������ΪȨֵ��ı��ǲ���������ȨֵС�ı��ϡ�
  Ȼ�󰴱߸���dp����
  
  dp[i]��һ��vector�����汣���ţ�(ԭ�㵽��i�����һ���ߵ�Ȩֵc , ԭ�㵽��i�ľ���s)
  ps�������ϢӦ��Ҫ����һ����ϵ����vector�������ϢΪ��
  (c1,s1),(c2,s2),...,(ci,si),...,(cj,sj)
  ��������i<j��Ӧ����ci<cj && si>sj�����Ǹ��ؼ��㡣

  ÿ��һ�������Ƕ�����֪�������ߵĳ�����fr�������to���ͱ�Ȩc��
  Ȼ���ձ�Ȩc-k��dp[fr]�ж��ֲ��Һ��ʵ���Ϣ��Ȼ����������dp[to]��
  ����m���߾��ܵõ��𰸣����Ӷ�ΪO(mlog(m))��
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
#define MP make_pair
#define PB push_back
const int N=100005;
const LL INF=(LL)0x3f3f3f3f*0x3f3f3f3f;
struct Edge{
	int fr,to;
	LL c;
	Edge(){};
	Edge(int _fr,int _to,LL _c){
		fr=_fr;
		to=_to;
		c=_c;
	}
}E[2*N];
bool cmp1(Edge a,Edge b){
	return a.c<b.c;
}
struct Dt{
	LL c,s;
	Dt(){}
	Dt(LL _c,LL _s){
		c=_c;
		s=_s;
	}
};
bool cmp2(Dt a,Dt b){
	if(a.c==b.c) return a.s>b.s;
	return a.c<b.c;
}
vector<Dt> dp[N];
int n,m,k;
void init(){
	for(int i=1;i<=n;++i)
		dp[i].clear();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i=0;i<m;++i){
			scanf("%d%d%I64d",&E[i].fr,&E[i].to,&E[i].c);
		}
		sort(E,E+m,cmp1);
		for(int i=0;i<m;++i){
			int fr=E[i].fr,to=E[i].to;
			LL c=E[i].c;
			if(fr==1){
				if(dp[to].size()==0)
					dp[to].PB(Dt(E[i].c,E[i].c));
				else if(dp[to][dp[to].size()-1].s>E[i].c)
					dp[to].PB(Dt(E[i].c,E[i].c));
			}
			else{
				if(dp[fr].size()==0) continue;
				int p=upper_bound(dp[fr].begin(),dp[fr].end(),Dt(E[i].c-k,-INF),cmp2)-dp[fr].begin();
				if(p==0) continue;
				else if(p>0 && p<dp[fr].size()) --p;
				else if(dp[fr][dp[fr].size()-1].c<=E[i].c-k) p=dp[fr].size()-1;
				else continue;
				if(dp[to].size()==0)
					dp[to].PB(Dt(E[i].c,dp[fr][p].s+E[i].c));
				else if(dp[to][dp[to].size()-1].s>dp[fr][p].s+E[i].c)
					dp[to].PB(Dt(E[i].c,dp[fr][p].s+E[i].c));
			}
		}
		if(dp[n].size()==0) puts("-1");
		else printf("%I64d\n",dp[n][dp[n].size()-1].s);
	}
	return 0;
}
