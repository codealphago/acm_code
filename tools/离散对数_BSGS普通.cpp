/*poj 2417
  ���⣺
  B^L==N(MOD P), ����P,B,N, ����С�ķǸ�L��
  ���ƣ�
  2 <= P < 2^31 && PΪ����; 2 <= B <P; 1 <= N < P
  ˼·��
  ��ɢ��������giant-step baby-step�����

  ��ͨgiant-step baby-step���̣�Ҫ��PΪ������
  ��s = ceil(sqrt(P)), ��L = b * s + r (0 <= b, r < s),
  ��B^L = B^(b * s) * B^r��������B^r����hash���У���С����ö��b���õ�N^(b * s) * B^r = n��


  ����С����a^(m-1)=1(mod m), mΪ����, �ɵã�
  1) a^0=1,����ѭ����С�ڵ���m,��������ڽ�,����С��x<=m
  2) ����a^sģm����ԪΪa^(m-s-1)

  ����K^D = 1(MOD P)���������Ӧ�����ȿ���ŷ�������������
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64

const int HASH_MOD=76543;
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], next[HASH_MOD];
struct Hash{
	int tot;
	void init(){
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	LL insert(LL x, LL y){
		int k = x % HASH_MOD;
		key[tot] = x;
		val[tot] = y;
		next[tot] = head[k];
		head[k] = tot++;
	}
	LL find(LL x){
		int k = x % HASH_MOD;
		for(int i = head[k]; i != -1; i = next[i])
			if(key[i] == x)
				return val[i];
		return -1;
	}
}hs;


LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
//���ģ����a^x=b(mod m),nΪ����,�޽ⷵ��-1  
//ע�⣺Ҫ��0 < a < m; 0 <= b < m; ���������Լ�ת����
//���Ӷ�O(sqrt(m))
LL log_mod(LL a, LL b, LL m){
	hs.init();
	LL s = ceil(sqrt(m));
	LL cur = 1;
	for (int i = 0; i < s; ++i){
		if(hs.find(cur)==-1) hs.insert(cur,i);	//�ǵ������أ��ڲ���
		cur = cur * a % m;
	}
	LL v = a_b_MOD_c(a, (m - s - 1 + m) % m, m);
	for(int i = 0; i < s; ++i){
		LL tmp = hs.find(b);
		if(tmp!=-1)
			return s * i + tmp;
		b=b*v%m;
	}
	return -1;
}

int main(){
	int p, b, n;
	while(scanf("%d%d%d", &p, &b, &n) != EOF){
		LL ans = log_mod(b,n,p);
		if(ans == -1) puts("no solution");
		else printf("%I64d\n", ans);
	}
	return 0;
}

/*����һ��������ɢ��������Ŀ����Ҫ��ŷ�����������
  (A ^ x) % B = 1����x
 */
void gao(LL A, LL B) {
	LL phi = get_phi(B);
	LL ans = phi;
	for (LL i = 2; i * i <= phi; ++i) {
		if (phi % i == 0) {
			while (phi % i == 0)
				phi /= i;
			while (ans % i == 0 && a_b_MOD_c(A, ans / i, B) == 1)
				ans /= i;
		}
	}
	if (phi > 1 && a_b_MOD_c(A, ans / phi, B) == 1)
		ans /= phi;
	printf("%I64d\n", ans);
}
