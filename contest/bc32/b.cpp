/*bc32 1002 Ԥ���� + ��ϣ
  ���⣺
  ����һ������(a[0],a[1],a[2],a[n-1])��һ������K�������ж�һ���Ƿ���ڶ�Ԫ��(i,j)(0 <= i <= j < n)ʹ�� NP-sum(i,j) �պ�ΪK������NP-sum(i,j)=a[i]-a[i+1]+a[i+2]+...+(-1)^(j-i)a[j]��
  ���ƣ�
  1 <= n <= 1e6; -1e9 <= a[i] <= 1e9; -1e9 <= K <= 1e9
  ˼·��
  �ȴ�ǰ������sum[i]��Ȼ��Ӻ���ǰɨ��ÿ��һ��sum[i]���ж�sum[i]+k�Ƿ��ں����sum[j](j>i)���ֹ���������ֹ���yes�������sum[i]����hash�������ں����Ĳ�ѯ��
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int N=1e6+5;
#define LL __int64
LL a[N];
int n;
LL k;
const int HASH_MOD=1876543;
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], nxt[HASH_MOD];
struct Hash{
    int tot;
    void init(){
        memset(head, -1, sizeof(head));
        tot = 0;
    }
    LL insert(LL x, LL y){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        key[tot] = x;
        val[tot] = y;
        nxt[tot] = head[k];
        head[k] = tot++;
    }
    LL find(LL x){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        for(int i = head[k]; i != -1; i = nxt[i])
            if(key[i] == x)
                return val[i];
        return -1;
    }
}hs;

LL sum[N];
bool gao(){
	hs.init();
    LL f=-1;
	sum[0]=a[0];
	for(int i=1;i<n;++i){
		sum[i]=sum[i-1]+f*a[i];
		f=-f;
	}
	if(sum[n-1]==k) return true;
	for(int i=n-1;i>=0;--i){
        if((i&1)==0){
			//cout<<sum[i]-k<<endl;
			if(hs.find(sum[i]-k)!=-1) return true;
		}
        else{
			//cout<<sum[i]+k<<endl;
			if(hs.find(sum[i]+k)!=-1) return true;
        }
		hs.insert(sum[i],1);
    }
    return false;
}

int In(){
    char c;int ret=0;c=getchar();
    int sign=1;
    while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
    if (c=='-') sign=-1,c=getchar();
    while (c>='0'&&c<='9'){
        ret=(ret<<3)+(ret<<1)+c-'0';
        c=getchar();
    }
    return ret*sign;
}

int main(){
    int T;
    int cas=0;
    T=In();
    while(T--){
        n=In();
        k=(LL)In();
        for(int i=0;i<n;++i)
            a[i]=(LL)In();
        printf("Case #%d: ",++cas);
        if(gao()) puts("Yes.");
        else puts("No.");
    }
    return 0;
}
