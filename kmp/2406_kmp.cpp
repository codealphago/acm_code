/*poj 2406
  ���⣺
  ����һ���ַ�����������ַ�������ɶ��ٸ��ظ����Ӵ����ɡ�
  ���ƣ�
  1 <= len <= 1e6
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*
���ģ�� �ַ����Ǵ�0��ʼ��
Next�����Ǵ�1��ʼ��
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

int main(){
	while(scanf("%s",T)!=EOF){
		if(T[0]=='.') break;
		tlen=strlen(T);
		getNext();
		int zq=tlen-nxt[tlen];
		if(tlen%zq==0)
			printf("%d\n",tlen/zq);
		else 
			puts("1");
	}
	return 0;
}
