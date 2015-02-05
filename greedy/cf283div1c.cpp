/*cf283div1c
  ���⣺����n������(a1,b1),(a2,b2),...,(an,bn),����m����(c1,d1,k1),(c2,d2,k2),...,(cn,dn,kn),ֻ��c<=a<=b<=dʱ������˲����������������˿������k�������ʷ�������Ŀ����Է�����
  ���ƣ�
  0<=n,m<=1e5 0<=a,b,c,d<=1e9
  ��⣺
  ̰��
  ��������һ������ѡ��һ�����������������ȥ�����
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define mp make_pair
const int N=100005;
struct Data{
	int l,r,k,id;
}d[2*N];
int ans[N];
map< pair<int,int>,int > _map;
map< pair<int,int>,int >::iterator it;
bool cmp(Data a,Data b){
	if(a.l==b.l){
		if(a.r==b.r) return a.id>b.id;
		return a.r>b.r;
	}
	return a.l<b.l;
}
int main(){
	int n,m;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i){
		scanf("%d%d",&d[i].l,&d[i].r);
		d[i].id=-i;
	}
	scanf("%d",&m);
	for(;i<n+m;++i){
		scanf("%d%d%d",&d[i].l,&d[i].r,&d[i].k);
		d[i].id=i;
	}
	sort(d,d+n+m,cmp);
	for(int i=0;i<n+m;++i){
		if(d[i].id>0)
			_map[mp(d[i].r,d[i].id-n+1)]=d[i].k;
		else{
			it=_map.lower_bound(mp(d[i].r,0));
			if(it==_map.end()){
				puts("NO");
				return 0;
			}
			else{
				ans[-d[i].id]=it->first.second;
				--it->second;
				if(it->second==0)
					_map.erase(it);
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;++i)
		printf("%d%c",ans[i],i!=n-1?' ':'\n');
	return 0;
}

