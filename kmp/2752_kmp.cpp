#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*
这个模板 字符串是从0开始的
Next数组是从1开始的
*/
void getNext(){
    int j, k;
    j = 0; k = -1; nxt[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            nxt[++j] = ++k;
        else
            k = nxt[k];
}
int ans[N],cnt;
int main(){
	while(scanf("%s",T)!=EOF){
		tlen=strlen(T);
		getNext();
		cnt=0;
		int i=tlen;
		while(i>0){
			ans[cnt++]=i;
			i=nxt[i];
		}
		for(int i=cnt-1;i>=0;--i){
			printf("%d%c",ans[i],i==0?'\n':' ');
		}
	}
	return 0;
}
