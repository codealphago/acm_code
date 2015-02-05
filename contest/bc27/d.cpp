/*hdu 5165
  ���⣺
  Bob��һ������{a1,a2,...,an}�������е�ÿ��Ԫ�ض��ǽ���1��n֮���������Bob����m�����������ǵĶ������ֵ���Ǽ���{1,2,...,n}��Bob��Alice������ʼ����Ϸ��Alice�ȿ�ʼ������ÿһ�֣���ҿ���ѡ��һ������fʹ��������ÿ��Ԫ�� ai(1 <= i <= n)���f(ai)�����磬һ��ʼ������{1,1,2,4,5}����һ������f(1)=1,f(2)=3,f(3)=4,f(4)=1,f(5)=2����ô����һ�β����������Ϊ{1,1,3,1,2}����������е�����Ԫ�ض���ͬ�����۵�ǰ����Bob����Alice������ôAliceʤ����Ϸ������Ȼ��Bob��Ŀ������ֹAliceʤ���� ����Alice��Bob���㹻������ÿ�ζ���ȡ���Ų��ԡ��ʣ���������ĳ�ʼ״̬��ʲô��Alice�Ƿ��ܹ���ʤ��
  ����������
  �����һ�а���һ������T(1 <= T <= 200)��ʾ������������������ÿ��������ݣ���һ�а�����������n��m(1 <= n,m <= 100)��ʾ����Ĵ�С�ͺ����ĸ�����������m�У�ÿ�а���n������f(1),f(2),...,f(n) (1 <= f(i) <= n,1 <= i <= n)��
  ���������
  ����ÿ�����ݣ����Aliceһ���ܹ���ʤ�����YES���������NO��
  ˼·��
  
  1.����Alice���������ÿ������(x,y),����ͨ��ĳЩ�����������(z,z),��Alice��ʤ����Ϊ���ں�������һ�Զ࣬������������ǲ�����ģ����Ե�Alice��(x,y)���(z,z)��Bob���ܰ�����ԭ�����߱�ɲ�һ��������

  2.��(x,y)ͨ��ĳЩ����ת��Ϊ(z,z)Ϊ����1��
  �ɱ�ʤ̬���ƣ����Կ������x==y������1���ǿ��Գɹ��ġ�
  ��dp[x][y][0/1]Ϊ��������(x,y)��Alice����0������1������1�ɹ���dp[x][y][0/1]=1������dp[x][y][0/1]=0��
  ���ԣ��������ʱ��dp[i][i][0/1]==1��
  ���ǰ�dp[x][y][0/1]==1��ȫ����ӣ�ÿ��ȡ��ǰ���һ�������и��£����·ֳ����������
  
  a)���Alice��ʱΪ���֣�������ǰ��ΪBob���֡�
  ��Bob����Ϊ�¼�A��Ҫʹ�¼�A�Ĺ���1���Գɹ������¼�A�����к�̵Ĺ���1���ǳɹ��ġ�
  
  b)���Alice��ʱΪ���֣�������ǰ��ΪAlice���֡�
  ��Alice����Ϊ�¼�B��Ҫʹ�¼�B�Ĺ���1���Գɹ������¼�B��һ����̵Ĺ���1���Գɹ������ˡ�

  ����һ��ʼ��ͼ��ʱ��Ҫ��һ�������ͼ��һ�������ͼ��
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
#define MP make_pair
#define PB push_back
const int N=10005;
vector<int> mp[N],rv[N];
map< pair<int,int>,int > vis;
int f[N],p2i[N][N];
int dp[N*N][2];
int n,m;
struct Dt{
	int v,turn;
	Dt(){}
	Dt(int _v,int _turn){ v=_v; turn=_turn; }
};
queue<Dt> que;
void init(){
	int id=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			p2i[j][i]=p2i[i][j]=id++;
	for(int i=0;i<id;++i){
		mp[i].clear();
		rv[i].clear();
	}
	vis.clear();
	for(int i=0;i<id;++i){
		dp[i][0]=dp[i][1]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=0;i<m;++i){
			for(int j=1;j<=n;++j)
				scanf("%d",&f[j]);
			for(int j=1;j<=n;++j)
				for(int k=j+1;k<=n;++k){
					int fr=p2i[j][k];
					int to=p2i[f[j]][f[k]];
					if(vis[MP(fr,to)]==0){
						mp[fr].PB(to);
						rv[to].PB(fr);
						vis[MP(fr,to)]=1;
					}
				}
		}
		for(int i=1;i<=n;++i){
			que.push(Dt(p2i[i][i],0));
			que.push(Dt(p2i[i][i],1));
			dp[p2i[i][i]][0]=dp[p2i[i][i]][1]=1;
		}
		while(!que.empty()){
			Dt now=que.front();
			que.pop();
			if(now.turn==0){
				int to=now.v;
				for(int i=0;i<rv[to].size();++i){
					int fr=rv[to][i];
					if(dp[fr][1]==0){
						int st=1;
						for(int i=0;i<mp[fr].size();++i)
							st&=dp[mp[fr][i]][0];
						dp[fr][1]=st;
						if(dp[fr][1])
							que.push(Dt(fr,1));
					}
				}
			}
			else{
				int to=now.v;
				for(int i=0;i<rv[to].size();++i){
					int fr=rv[to][i];
					if(dp[fr][0]==0){
						dp[fr][0]=1;
						que.push(Dt(fr,0));
					}
				}
			}
		}
		int ans=1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				ans&=dp[p2i[i][j]][0];
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
