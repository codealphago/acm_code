/*hdu 5164 Matching on Array
  ���⣺
  ��������Ϊnһ��ĸ��������m������Ϊki�Ӵ���ƥ��������Ǳ�����ͬ�����Ӵ�4 8 �ܺ� 1 2 4ƥ�䡣�������Ӵ���ĸ���г��ֶ��ٴΡ�
  ���ƣ�
  1 <= n,m <= 1e5
  1 <= ki <= 300000
  ˼·��
  �������ac�Զ�����������next������map��ʵ�֣��������Զ����
  ������һ�㻹Ҫע�⣬hdu��g++���ṹ�����治�ܿ�̫��Ķ�����Ҫ��Ȼ��ce�˻��������㣬���԰�ac�Զ����ṹ������Ķ���ȫ�ᵽ����Ϳ����ˡ�
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=1000005;
LL ans;
int s[N],p[3*N];
int n,m,q;

map<int,int> next[N];
map<int,int> :: iterator it;
int que[N],head,tail;
int cnt,root,null;
int fail[N],end[N];
struct acm{
    int newNode(){
        next[cnt].clear();
        end[cnt]=0;
        return cnt++;
    }
    void init(){
        cnt=0;
        null=cnt++;
        root=newNode();
    }
    void insert(int n){
        int now=root;
        for(int i=0;i<n-1;++i){
            int d=__gcd(p[i],p[i+1]);
            int t=p[i]/d*10001+p[i+1]/d;
            int nxt=next[now][t];
            if(nxt==0) nxt=next[now][t]=newNode();
            now=nxt;
        }
        ++end[now];
    }
    void build(){
        head=tail=0;
        fail[root]=null;
        for(it=next[root].begin();it!=next[root].end();++it){
            fail[it->second]=root;
            que[tail++]=it->second;
        }
        while(head!=tail){
            int now=que[head++];
            end[now]+=end[fail[now]];   //
            for(it=next[now].begin();it!=next[now].end();++it){
                int tmp=fail[now];
                int nxt=next[tmp][it->first];
                while(tmp!=null && !nxt){ tmp=fail[tmp]; nxt=next[tmp][it->first]; }
                if(tmp!=null) fail[it->second]=nxt;
                else fail[it->second]=root;
                que[tail++]=it->second;
            }
        }
    }
    void debug(){
        for(int i=0;i<=cnt;i++){
            printf("id=%3d,fail=%3d,sum=%3d\n",i,fail[i],end[i]);
            for(it=next[i].begin();it!=next[i].end();++it)
                printf("(%d,%d) ",it->first,it->second);
            puts("");
        }
    }

    void query(int n){
        int now=root;
        for(int i=0;i<n-1;++i){
            int d=__gcd(s[i],s[i+1]);
            int t=s[i]/d*10001+s[i+1]/d;

            int nxt=next[now][t];
            while(now!=null && !nxt){ now=fail[now]; nxt=next[now][t]; }
            if(now!=null) now=nxt;
            else now=root;
            //for(int j=now;j;j=fail[j]){
            //  ans+=end[j];
            //}
            ans+=end[now];
        }
    }
}acm;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        acm.init();
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;++i)
            scanf("%d",&s[i]);
        while(q--){
            scanf("%d",&m);
            for(int i=0;i<m;++i)
                scanf("%d",&p[i]);
            if(m>1) acm.insert(m);
            else ans+=n;
        }
        acm.build();
        //acm.debug();
        acm.query(n);
        printf("%I64d\n",ans);
    }
    return 0;
}
