/*hdu 5193 �ֿ� ��״���� �����
  ���⣺
  ����n������a1,a2,a3,...,an������m���޸ģ�ÿ���޸��������ĳ��λ�ú������һ���������߰�ĳ��λ���ϵ����Ƴ�����ÿ���޸ĺ�����Եĸ�����
  ���ƣ�
  1 <= n,m <= 20000; 1 <= ai <= n
  ˼·��
  �����ɾ���÷ֿ������������֮����˫��������ά����ÿһ������״��������С��ĳ���������ж��ٸ���
  ������ʹ�÷ֿ�ά���±꣬������Ӻ�ɾ��Ԫ�ص�ʱ��Ҳ�ܷ��㣬ֱ�ӱ���������Ȩֵ����ʱ��ʹ����״����ȽϷ��㡣�ڲ�ͨ����״����ά��Ȩֵ��
  ÿ�θ��¼�Ϊ����ǰ����ұ�������ں�������ұ���С�Ĵ��ۡ�
  O(m*(sqrt(n)+sqrt(n)*log(n)))
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
#define LL __int64
#define PB push_back
const int N=355;
const int M=20005;
int tot;
vector<int> vec[N];
int pre[N],nxt[N];
int SZ;
int BIT[N][M];
int lowbit(int x){ return x&-x; }
int sum(int i,int x){
	int s=0;
	while(x>0){
		s+=BIT[i][x];
		x-=lowbit(x);
	}
	return s;
}
void update(int i,int x,int w){
	while(x<M){
		BIT[i][x]+=w;
		x+=lowbit(x);
	}
}
vector<int> A;
void init(){
	tot=0;
	memset(pre,-1,sizeof(pre));
	memset(nxt,-1,sizeof(nxt));
	memset(BIT,0,sizeof(BIT));
	for(int i=0;i<N;++i)
		vec[i].clear();
	A.clear();
}
LL merge_count(vector<int> &a){
	int n=a.size();
	if(n<=1) return 0;
	LL cnt=0;
	vector<int> b(a.begin(),a.begin()+n/2);
	vector<int> c(a.begin()+n/2,a.end());
	cnt+=merge_count(b);
	cnt+=merge_count(c);
	int ai=0,bi=0,ci=0;
	while(ai<n){
		if(bi<b.size() && (ci==c.size() || b[bi]<=c[ci]))
			a[ai++]=b[bi++];
		else{
			cnt+=(LL)(n/2-bi);
			a[ai++]=c[ci++];
		}
	}
	return cnt;
}
int count_left(int now,int h){
	int p=0;
	int ret=0;
	while(p!=now){
		ret+=vec[p].size()-sum(p,h);
		p=nxt[p];
	}
	return ret;
}
int count_right(int now,int h){
	int p=nxt[now];
	int ret=0;
	while(p!=-1){
		ret+=sum(p,h-1);
		p=nxt[p];
	}
	return ret;
}
void print(){
	cout<<"---"<<endl;
	int p=0;
	while(p!=-1){
			for(int j=0;j<vec[p].size();++j){
				cout<<vec[p][j]<<' ';
			}
			cout<<endl;
			p=nxt[p];
	}
	cout<<"---"<<endl;
}
int count_in(int now,int id,int h){
	int ret=0;
	for(int i=0;i<id;++i){	//
		if(vec[now][i]>h) ++ret;
	}
	for(int i=id;i<vec[now].size();++i){	//
		if(vec[now][i]<h) ++ret;
	}
	return ret;
}
int ins(int id,int h){
	int p=0;
	while(id>vec[p].size()){
		id-=vec[p].size();
		p=nxt[p];
	}
	vec[p].insert(vec[p].begin()+id,h);
	update(p,h,1);
	int left=count_left(p,h);
	int right=count_right(p,h);
	int in=count_in(p,id,h);
	if(vec[p].size()>SZ){
		int dy=vec[p][vec[p].size()-1];
		vec[p].pop_back();
		update(p,dy,-1);
		if(nxt[p]==-1 || vec[nxt[p]].size()==SZ){
			int q=nxt[p];
			nxt[p]=++tot;
			pre[tot]=p;
			nxt[tot]=q;
			pre[q]=tot;

			vec[tot].push_back(dy);
			update(tot,dy,1);
		}
		else{
			int q=nxt[p];
			vec[q].insert(vec[q].begin(),dy);
			update(q,dy,1);
		}
	}
	return left+in+right;
}
int qui(int id){
	int p=0;
	while(id>vec[p].size()){
		id-=vec[p].size();
		p=nxt[p];
	}
	int h=vec[p][id-1];
	int left=count_left(p,h);
	int right=count_right(p,h);
	int in=count_in(p,id,h);
	vec[p].erase(vec[p].begin()+id-1);	//
	update(p,h,-1);
	return left+right+in;
}
int main(){
	int n,m;
	int a;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		SZ=sqrt(n+m);
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			A.PB(a);
			vec[tot].PB(a);
			update(tot,a,1);
			if(vec[tot].size()==SZ){
				nxt[tot]=tot+1;
				++tot;
				pre[tot]=tot-1;
			}
		}


		LL ans=merge_count(A);
		int cm,x,y;
		for(int i=0;i<m;++i){
			scanf("%d",&cm);
			if(cm==0){
				scanf("%d%d",&x,&y);
				ans+=(LL)ins(x,y);
				printf("%I64d\n",ans);
			}
			else{
				scanf("%d",&x);
				ans-=(LL)qui(x);
				printf("%I64d\n",ans);
			}
			//print();
		}
	}
	return 0;
}
