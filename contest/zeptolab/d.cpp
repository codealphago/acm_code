/*codeforces 526 d Om Nom and Necklace
  ���⣺
  ����һ���ַ������ʶ����ַ�����ÿ��λ��p�����0��p���ַ����Ƿ���ϸ�ʽ��S=A+B+A+B+A+...+A+B+A������A,B���ַ������ҿ����ǿմ���
  ���ƣ�
  �ַ�������1e6
  ˼·��
  next�����������á�
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
void getNext(){
	int i,j;
	j=nxt[0]=-1;
	for(int i=1;i<tlen;++i){
		while(j!=-1 && T[i]!=T[j+1]) j=nxt[j];
		if(T[j+1]==T[i]) j++;
		nxt[i]=j;
	}
}
char ans[N];
bool zc[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",T);
	tlen=n;
	getNext();
	//for(int i=1;i<=n;++i){
	//	cout<<i<<' '<<nxt[i]<<endl;
	//}
	for(int i=0;i<n;++i){
		int p=i+1;
		int bl=p/(p-1-nxt[p-1]);
		if(p%(p-1-nxt[p-1])==0){
			if(bl/k>=bl%k) putchar('1');
			else putchar('0');
		}
		else{
			if(bl/k>bl%k) putchar('1');
			else putchar('0');
		}
	}
	puts("");
	return 0;
}
