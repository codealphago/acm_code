/*hdu 5176 The Experience of Love
  ��Ŀ��
  һ����Gorwin��Ů����һ����Vivin���к���һ�����¡���������һ���а���Ĺ��ң����������N��������ɶ���ֻ��N-1��С��(��һ����)��ÿ��С����һ��ֵ��ʾ�������м�ľ��롣����ѡ����������ס�£�Gorwin��һ������Vivin������һ������һ��Լ�ᣬGorwinȥ��Vivin������д��·�������һ��С��(maxValue)���ڶ���Լ�ᣬVivinȥ��Gorwin������д��·������̵�һ��С��(minValue)��Ȼ�����maxValue��ȥminValue�Ľ����Ϊ���龭��ֵ����Ȼ������ѡ���������о�ס���Ҽ����µİ��龭��ֵ���ظ�һ����һ�Ρ�
  ������ѡ������е��������������Ǽ���һ�°��龭��ֵ���ܺ͡�
  ���ƣ�
  1 < N <= 150000; 1 <= a,b <= N; 1 <= c <= 1e9
  ˼·��
  1. ���߿��ǣ���һ���߱��������ֵ���ٴΣ�������Сֵ���ٴΡ�
  2. �����ֵΪ�����Ȱѱߴ�С�������򣬴�С������ͼ��ӱߣ�ÿ�μӱ�(u,v,w)ǰ������u�������ж��ٸ���(����t1����)����v�������ж��ٸ���(����t2����)(��������ò��鼯��ʵ��)��t1*t2���������߱��������ֵ���ٴ��ˡ�
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
#define LL __int64
#define ULL unsigned __int64
const int N=150005;
struct Edge{
	int fr,to,w;
	Edge(){}
	Edge(int _fr,int _to,int _w){
		fr=_fr;
		to=_to;
		w=_w;
	}
}e[N];
bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}
bool cmp2(Edge a,Edge b){
	return a.w>b.w;
}
int fa[N],cnt[N];
int stk[3*N],top;
int getFa(int x){
	top=-1;
	while(x!=fa[x]){ stk[++top]=x; x=fa[x]; }
	int now=x;
	while(top>=0){ now=stk[top--]; fa[now]=x; }
	return fa[now];
}
void init(int n){
	for(int i=0;i<=n;++i){
		fa[i]=i;
		cnt[i]=1;
	}
}
void gao(int n){
	ULL ans=0;
	init(n);
	sort(e,e+n-1,cmp1);
	for(int i=0;i<n-1;++i){
		int fx=getFa(e[i].fr);
		int fy=getFa(e[i].to);
		ans+=(ULL)cnt[fx]*cnt[fy]*e[i].w;
		cnt[fx]+=cnt[fy];
		fa[fy]=fx;
	}
	init(n);
	sort(e,e+n-1,cmp2);
	for(int i=0;i<n-1;++i){
		int fx=getFa(e[i].fr);
		int fy=getFa(e[i].to);
		ans-=(ULL)cnt[fx]*cnt[fy]*e[i].w;
		cnt[fx]+=cnt[fy];
		fa[fy]=fx;
	}
	printf("%I64u\n",ans);
}
int main(){
	int n;
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n-1;++i)
			scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].w);
		printf("Case #%d: ",++cas);
		gao(n);
	}
	return 0;
}
