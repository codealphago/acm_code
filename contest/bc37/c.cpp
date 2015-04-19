/*hdu 5204 Rikka with sequence
  ���⣺
  ������֪���������������ó���ѧ��������̫������һЩ��ѧ��������ϰ��������һ���������ģ�
  ���һ�����ر����Ի�������ͼ��ÿ����ͨ�鶼����һ����·���������ͨ�������б�һ���ҽ�һ�Σ���ô�ͳ��������ͼ�������ġ�������n�����ұ���������m��������ͼ�ж��ٸ������������У�������Ϊ��n�����Ǳ��ʲ�ͬ�ģ�
  ��Ȼ������������������������˵ʵ����̫���ˣ�����԰������
  ���ƣ�
  1 <= n <= 1e5; 1 <= L <= R <= 1e18; 1 <= w <= 1e9��
  ˼·��
  ��ʵ��60���Ҹ���ͬ������
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}
void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}
void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

LL add[100005];
int cnt;
struct Dt{
	LL x;
	LL cnt;
}ele[100005];
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
LL getC(LL x){
	if(x<0) return 0;
	LL ret=x/2;
	if(x%2) ++ret;
	return ret;
}

void gao(LL l,LL r,LL k){
	for(int i=cnt-1;i>=max(0,cnt-65);--i){
		ele[cnt-1-i].x=add[i];
		ele[cnt-1-i].cnt=getC(r)-getC(l-1);
		r/=2;
		l=(l+1)/2;
	}
	sort(ele,ele+min(cnt,65),cmp);
	LL ans=0;
	for(int i=0;i<min(cnt,65);++i){
		if(ele[i].cnt<k){
			k-=ele[i].cnt;
		}
		else{
			ans=ele[i].x;
			break;
		}
	}
	Out(ans);
	puts("");
}

int main(){
	int n;
	int op;
	LL w,l,r,k;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(int i=0;i<n;++i){
			In(op);
			if(op==1){
				In(w);
				add[cnt++]=w;
			}
			else{
				In(l);
				In(r);
				In(k);
				gao(l,r,k);
			}
		}
	}
	return 0;
}
