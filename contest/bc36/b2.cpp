#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//手写哈希表
const int HASH_MOD=3876543;	//看题目，调大小
int key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], nxt[HASH_MOD];	//next为系统关键字
struct Hash{
    int tot;
    void init(){
        memset(head, -1, sizeof(head));
        tot = 0;
    }
    int insert(int x, int y){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        key[tot] = x;
        val[tot] = y;
        nxt[tot] = head[k];
        head[k] = tot++;
    }
    int find(int x){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        for(int i = head[k]; i != -1; i = nxt[i])
            if(key[i] == x)
                return val[i];
        return -1;
    }
}hs;
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

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

int main(){
	int n,m;
	int a;
	while(scanf("%d%d",&n,&m)!=EOF){
		hs.init();
		for(int i=0;i<n;++i){
			In(a);
			int tmp=hs.find(a);
			if(tmp==-1){
				hs.insert(a,1);
			}
			else{
				hs.insert(a,tmp+1);
			}
		}
		for(int i=0;i<m;++i){
			In(a);
			int tmp=hs.find(a);
			if(tmp==-1 || tmp==0) puts("0");
			else{
				Out(tmp);
				puts("");
				hs.insert(a,0);
			}
		}
	}
	return 0;
}
