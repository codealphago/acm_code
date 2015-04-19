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
	int j, k;
	j = 0; k = -1; nxt[0] = -1;
	while(j < tlen)
		if(k == -1 || T[j] == T[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];

}
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
		int bl=p/(p-nxt[p]);
		if(p%(p-nxt[p])==0){
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
