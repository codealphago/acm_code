/*1. ������next����ĳ����÷�
  ����ģʽ��T���������״γ��ֵ�λ��(��0��ʼ)
  ����ģʽ��T���������״γ��ֵĴ���
 */
#include<iostream>
#include<cstring>
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
/*
����ģʽ��T������S���״γ��ֵ�λ��
���ص�λ���Ǵ�0��ʼ�ġ�
*/
int KMP_Index(){
    int i = 0, j = 0;
    while(i < slen && j < tlen){
        if(j == -1 || S[i] == T[j]){
            i++; j++;
        }
        else
            j = nxt[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
����ģʽ��������S�г��ֵĴ���
*/
int KMP_Count(){
    int ans = 0;
    int j = 0;
    for(int i = 0; i < slen; i++){
        while(j > 0 && S[i] != T[j])
            j = nxt[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen){
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}
int main(){
    int TT;
    cin>>TT;
    while(TT--){
        cin>>T>>S;
        slen = strlen(S);
        tlen = strlen(T);
		getNext();
		for(int i=1;i<=tlen;++i){
			cout<<nxt[i]<<' ';
		}
		cout<<endl;
        cout<<"ģʽ��T������S���״γ��ֵ�λ����: "<<KMP_Index()<<endl;
        cout<<"ģʽ��T������S�г��ֵĴ���Ϊ: "<<KMP_Count()<<endl;
    }
    return 0;
}
/*
1
abcabcabc abc

nxt[1~n]Ϊ��
0 0 0 1 2 3 4 5 6
*/


/*2. ��������һ���ַ�����������ַ�������ɶ��ٸ��ظ����Ӵ����ɡ�
  �Ӵ�����=len-next[len]
  �磺
  aaaa �Ӵ�����=1
  aaab �Ӵ�����=4
  ababa �Ӵ�����=2
  aabaabaa �Ӵ�����=3
  ��һ������
 */
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


/*3. ��һ������һ���ַ���������ͬ��ǰ׺�ͺ�׺
  �磺
  ababab
  ��ͬ��Ǯ��׺Ϊ��
  ab
  abab
  ababab
 */
#include<iostream>
#include<cstdio>
#include<cstring>
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


/*4. �����ȳ��������ַ�������������ͬ��ǰ��׺
  ����:S="aaa"��T="aab"
  len=3
  ��i=3ʱ:
  aaa
  aab
  ����:ans[0]=0

  ��i=2ʱ:
  aaa
   aab
  ����:ans[1]=1

  ��i=1ʱ:
  aaa
    aab
  ����:ans[2]=1
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
int next[N];
void getNext(char T[],int len){
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<len){
		if(j==-1 || T[i]==T[j]) next[++i]=++j;
		else j=next[j];
	}
}
void deal(char S[],char T[],int len,char res[]){
	for(int i=0;i<len;++i) res[i]='0'; res[len]=0;
	int i=0,j=0;
	getNext(T,len);
	while(i<len){
		if(j==-1 || S[i]==T[j]){
			++i; ++j;
			if(i==len && j!=0){
				res[len-1-(j-1)]='1';
				--i;
				j=next[j-1];
			}
		}
		else j=next[j];
	}
}
char S[N],T[N],ans[N];
int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%s%s",S,T);
		int len=strlen(S);
		deal(S,T,len,ans);
		puts(ans);
	}
	return 0;
}
