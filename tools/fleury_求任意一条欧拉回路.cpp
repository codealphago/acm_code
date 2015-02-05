/*codeforces 508 D. Tanya and Password
  ���⣺
  ����n������Ϊ3���ַ������磺abc bca aab ���һ���ַ����ĳ���Ϊ2�ĺ�׺���ڣ�����һ���ַ����ĳ���Ϊ2��ǰ׺�����������ַ����������������磺aabca��Ȼ����n���ַ��������γ�һ��ͼ����ͼ�ϵ�һ��ŷ��ͨ·��
  ���ƣ�
  1 <= n <= 2*10^5���ַ��������д�д��ĸ��Сд��ĸ
  ˼·��
  ��ÿ���ַ������ɱߣ���ǰ׺��׺�����㣬�磺abc -> ab��bc��
  ��������⻯Ϊ����62*62���㣬2*10^5���ߵ�ͼ����һ��ŷ��ͨ·����Ŀ��
  ��fleury(������)�����˸о����ڽӱ�ʵ��Ч�ʱ��ڽӾ���
  ps:�����dfs�ᱬջ�������ĳɷǵݹ�ľ��С�
  */
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<stack>
using namespace std;
const int M=200005;
const int N=65*65;
vector<int> mp[N];
int fa[N];
int in[N],out[N];
char ans[M],rev[M];
int len=0;
string i2s[N];
map<string,int> s2i;
int stk[M],top=0;

int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}
void dfs(int x){
	while(mp[x].size()>0){
		stk[++top]=x;
		int ch=mp[x][mp[x].size()-1];
		mp[x].pop_back();
		x=ch;
	}
	stk[++top]=x;
}
void fleury(int S){
	int brige;
	stk[++top]=S;
	int flag=0;
	int tp;
	while(top>0){
		tp=stk[top--];
		brige=(mp[tp].size()==0);
		if(brige){
			if(flag)
				ans[len++]=i2s[tp][0];
			else{
				ans[len++]=i2s[tp][1];
				ans[len++]=i2s[tp][0];
				flag=1;
			}
		}
		else
			dfs(tp);
	}
}

int main(){
	int n,m;
	char str[5];
	string fr,to;
	n=0;
	scanf("%d",&m);
	for(int i=0;i<65*65;++i)
		fa[i]=i;
	for(int i=0;i<m;++i){
		int x,y;
		int fx,fy;
		scanf("%s",str);
		fr=str[0];
		fr+=str[1];
		to=str[1];
		to+=str[2];

		x=s2i[fr];
		if(x==0){ s2i[fr]=++n; i2s[n]=fr; x=n; }
		y=s2i[to];
		if(y==0){ s2i[to]=++n; i2s[n]=to; y=n; }

		mp[x].push_back(y);
		fx=getFa(x);
		fy=getFa(y);
		if(fx!=fy)
			fa[fy]=fx;
		++out[x];
		++in[y];
	}
	int lt=1;
	int root=getFa(1);
	for(int i=2;i<=n;++i){
		if(getFa(i)!=root){ lt=0; break; }
	}
	int S=0,T=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(in[i]==out[i]) continue;
		else{
			cnt++;
			if(in[i]-out[i]==1) T=i;
			else if(in[i]-out[i]==-1) S=i;
			else{ cnt=-1; break; }
		}
	}
	if(lt && ((cnt==2 && S!=T) || cnt==0)){
		puts("YES");
		if(cnt==0) S=1;
		fleury(S);
		int len=strlen(ans);
		for(int i=0;i<len;++i){
			rev[len-1-i]=ans[i];
		}
		puts(rev);
	}
	else{
		puts("NO");
	}
	return 0;
}
