/*hust 1017
   ���⣺����һ����0��1��ɵľ����Ƿ����ҵ�һ���еļ��ϣ�ʹ�ü�����ÿһ�ж�ǡ�ð���һ��1��
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int maxnode = 100010;
const int MaxM = 1010;
const int MaxN = 1010;
struct DLX{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN], S[MaxM];
    int ansd, ans[MaxN];	//ansd��ʾ��������Ҫ��������ans���渲������Ҫ�Ĳ���
    void init(int _n,int _m){
		ansd=-1;
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++){
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c){
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else{
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c){
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c];i != c;i = D[i])
            for(int j = R[i];j != i;j = R[j]){
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }
    void resume(int c){
        for(int i = U[c];i != c;i = U[i])
            for(int j = L[i];j != i;j = L[j])
                ++S[Col[U[D[j]]=D[U[j]]=j]];
        L[R[c]] = R[L[c]] = c;
    }
	void Dance(int d){
        //��֦��
        //if(ansd != -1 && ansd <= d) return;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
        if(R[0] == 0){
            //if(ansd == -1)ansd = d;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
            //else if(d < ansd)ansd = d;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
            ansd = d;
			return;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        remove(c);
        for(int i = D[c];i != c;i = D[i]){
			ans[d] = Row[i];
            for(int j = R[i];j != i;j = R[j])remove(Col[j]);
            Dance(d+1);
			if(ansd!=-1) return ;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�������ȥ��
            for(int j = L[i];j != i;j = L[j])resume(Col[j]);
        }
        resume(c);
    }
};
DLX g;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) == 2){
        g.init(n,m);
        for(int i = 1;i <= n;i++){
            int num,j;
            scanf("%d",&num);
            while(num--){
                scanf("%d",&j);
                g.Link(i,j);
            }
        }
		g.Dance(0);
        if(g.ansd==-1)printf("NO\n");
        else{
            printf("%d",g.ansd);
            for(int i = 0;i < g.ansd;i++)
                printf(" %d",g.ans[i]);
            printf("\n");
        }
    }
    return 0;
}
