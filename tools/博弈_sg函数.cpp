/*sg(Sprague-Grundy)����
  sgֵ��һ�����SGֵ����һ�����������ĺ�̵��SG���Ҵ��ڵ��������С������
  ��̵㣺Ҳ���ǰ�����ĿҪ����߷����ܹ���һ���ﵽ���Ǹ��㡣

  sg����ֵ�����ʣ�
  sg(x)==0 �ذܵ�
  sg(x)>0 ��ʤ��
 */

//�󵥸�sg����ֵ
int sg[MAXN];
int get_sg(int x, int n){
	if(sg[x]!=-1)
		return sg[x];
	bool vis[105]={0};
	for(int i=0;i<n;++i){
		int tmp = a[i]; //tmp��ת�Ƶ���һ��״̬�Ĳ���
		if(x >= tmp){
			sg[x - tmp] = get_sg(x - tmp, n);
			vis[sg[x - tmp]] = 1;
		}
	}
	for(int i=0;;++i)
		if(!vis[i]) return sg[x]=i;
}
void init(){
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
}

//Ԥ����sgֵ
void get_sg(){
	sg[0]=0;
	for(int i=1;i<N;++i){
		set<int> s;
		for(int j=0;j<10;++j){
			int tmp=(1<<j); //tmp��ת�Ƶ���һ��״̬�Ĳ���
			if(i >= tmp)
				s.insert(sg[i - tmp]);
		}
		int g=0;
		while(s.count(g)!=0) ++g;
		sg[i]=g;
	}
}

/*hdu 1847
  ���⣺
  1. �ܹ�n����;
  2. ˫������ץ�ƣ�
  3. ÿ��ÿ��ץ�Ƶĸ���ֻ����2���ݴΣ�����1��2��4��8��16����
  4. ץ���ƣ�ʤ�����Ҳ�����ˣ����ץ���Ƶ���Ϊʤ�ߣ�
  ����Kiki��Cici�����㹻����������ÿ�ζ���Kiki��ץ�ƣ�����˭��Ӯ�أ�
  ���ƣ�
  1 <= n <= 1000
  ˼·��
  sg����
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int N=1005;
const int M=105;
int sg[N];

/*int get_sg(int x){
	if(sg[x]!=-1)
		return sg[x];
	bool vis[M];
	memset(vis,0,sizeof(vis));

	for(int i=0;i<10;++i){
		int tmp = (1<<i);
		if(x >= tmp){
			sg[x - tmp] = get_sg(x - tmp);
			vis[sg[x - tmp]] = 1;
		}
	}
	for(int i=0;;++i)
		if(!vis[i]) return i;
}
void get_sg(){
	sg[0]=0;
	for(int i=1;i<=1000;++i){
		sg[i]=get_sg(i);
	}
}*/

void get_sg(){
	sg[0]=0;
	for(int i=1;i<N;++i){
		set<int> s;
		for(int j=0;j<10;++j){
			int tmp=(1<<j);
			if(i >= tmp)
				s.insert(sg[i - tmp]);
		}
		int g=0;
		while(s.count(g)!=0) ++g;
		sg[i]=g;
	}
}

void init(){
	memset(sg,-1,sizeof(sg));
}

int main(){
	init();
	
	get_sg();

	int n;
	while(scanf("%d",&n)!=EOF){
		if(sg[n]==0)
			puts("Cici");
		else
			puts("Kiki");
	}
	return 0;
}
