/*bc24c
  ���⣺����һ������ΪN�����У�����ΪA1,A2,A3,...AN��Ȼ����M��������ÿ������Ϊ�������ֲ���������һ����
  1. �������������l,r�������i=lrAi��ֵ��
  2. �޸Ĳ���������x����Ax�޸�Ϊ2Ax
  3. �ӷ�����������l,r,x����Ai(l��i��r)����x
  ������������Ľ�����ܴܺ���������2333333ȡģ��
  ���ƣ�0 <= n,m <= 50000	0 <= ai <= 1e9
  ˼·�������ǣ��������Ҫ������2����ʽx >= Phi(C), A^x = A ^ (x%Phi(C) + Phi(C)) (mod C)
  Ȼ��ֵ��ע���ǣ�������Phi(c)����һ����һ��ġ�
  �����Ŀ����2333333������Phi(c)�����ֻ��18�㡣
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
#define ls (n<<1)
#define rs (n<<1 | 1)
#define pb push_back
const int MAXN = 100005;
const int MOD = 2333333;
int mo[19] = { 2333333 , 2196720 , 580608 , 165888 , 55296 , 18432 , 6144 , 2048 , 1024 , 512 , 256 , 128 , 64 , 32 , 16 , 8 , 4 , 2 , 1 };
LL sum[MAXN << 2];
LL len[MAXN << 2];
LL add[MAXN << 2];
LL a[MAXN];
vector<LL> tab[MAXN];
int n,m;
int fpow(LL a,LL b,LL mod){
	LL ret = 1;
	a %= MOD;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
void down(int n){
	if(add[n]){
		add[ls] += add[n];
		add[rs] += add[n];
		sum[ls] = (sum[ls] + add[n] * len[ls] % MOD) % MOD;
		sum[rs] = (sum[rs] + add[n] * len[rs] % MOD) % MOD;
		add[n] = 0;
	}
}
void up(int n){
	sum[n] = (sum[ls] + sum[rs]) % MOD;
}
void build(int l,int r,int n){
	add[n] = 0;
	len[n] = r - l + 1;
	if(l == r){
		sum[n] = a[l]%MOD;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	up(n);
}
void update(int L,int R,int l,int r,int n,LL v){
	if(L <= l && r <= R){
		add[n] += v;
		sum[n] = (sum[n] + len[n] * v) % MOD;
		return ;
	}
	down(n);
	int mid = (l + r) >> 1;
	if(L <= mid) update(L,R,l,mid,ls,v);
	if(mid < R) update(L,R,mid+1,r,rs,v);
	up(n);
}
LL cal(int i,int t){
	if(t == 19) return 0;
	LL tmp;
	int ch = tab[i].size()-1-t;
	if(t+1 == tab[i].size()) tmp = tab[i][ch];
	else tmp = fpow(2,cal(i,t+1),mo[t]) + tab[i][ch];
	if(tmp >= mo[t]) tmp = tmp % mo[t] + mo[t];
	return tmp;
}
void modify(int x,int l,int r,int n){
	if(l == r){
		tab[x][tab[x].size()-1]+=add[n];
		add[n] = 0;
		tab[x].pb(0);
		sum[n] = cal(x,0) % MOD;
		return ;
	}
	down(n);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(x,l,mid,ls);
	else modify(x,mid+1,r,rs);
	up(n);
}
LL query(int L,int R,int l,int r,int n){
	if(L <= l && r <= R) return sum[n];
	down(n);
	int mid = (l + r) >> 1;
	LL ret = 0;
	if(L <= mid) ret = (ret + query(L,R,l,mid,ls)) % MOD;
	if(mid < R) ret = (ret + query(L,R,mid+1,r,rs)) % MOD;
	return ret;
}
void init(){
	for(int i=0;i<=n;++i)
		tab[i].clear();
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
			tab[i].pb(a[i]);
		}
		build(1,n,1);
		int op,u,v;
		LL w;
		for(int i=0;i<m;++i){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&u,&v);
				printf("%I64d\n",query(u,v,1,n,1));
			}
			else if(op == 2){
				scanf("%d",&u);
				modify(u,1,n,1);
			}
			else{
				scanf("%d%d%I64d",&u,&v,&w);
				update(u,v,1,n,1,w);
			}
		}
	}
	return 0;
}
