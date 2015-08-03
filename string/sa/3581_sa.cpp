/*poj 3581
  ���⣺����N��������ɵ�����A1,A2,...,An������A1���������ֶ�������Ҫ��������зֳ����Σ�����ÿ�ηֱ�ת�����ܵõ����ֵ�����С��������ʲô��Ҫ��ֵõ�ÿ�ζ���Ϊ�ա�
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n,
	a[N],rev[N*2];

//��׺����ģ��
//ע��k��ȫ�ֱ�����Ҫ����
int k;	//���ڱ��������׺�����ȫ�ֱ���
int rank[N],tmp[N];
int sa[N*2];
bool cmp_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n? rank[i+k]:-1;
		int rj=j+k<=n? rank[j+k]:-1;
		return ri<rj;
	}
}
void build_sa(int *arr,int *sa){
	//n=strlen(arr);
	for(int i=0;i<=n;++i){
		sa[i]=i;
		rank[i]=i<n?arr[i]:-1;
	}
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;++i){
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp_sa(sa[i-1],sa[i])?1:0);
		}
		for(int i=0;i<=n;++i){
			rank[i]=tmp[i];
		}
	}
}
void gao(){
	reverse_copy(a,a+n,rev);
	build_sa(rev,sa);

	//ȷ����һ�εķָ�λ��
	int p1;
	for(int i=0;i<n;++i){
		p1=n-sa[i];
		if(p1>=1 && n-p1>=2) break;
	}
	//��p1֮����ַ�����ת���ظ�2�Σ��ټ������ĺ�׺����
	int m=n-p1;
	reverse_copy(a+p1,a+n,rev);
	reverse_copy(a+p1,a+n,rev+m);

	int cp=n;
	n=m*2;
	build_sa(rev,sa);

	n=cp;
	//ȷ�������εķָ�λ��
	int p2;
	for(int i=0;i<=2*m;++i){
		p2=p1+m-sa[i];
		if(p2-p1>=1 && n-p2>=1) break;
	}
	reverse(a,a+p1);
	reverse(a+p1,a+p2);
	reverse(a+p2,a+n);
	for(int i=0;i<n;++i)
		printf("%d\n",a[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	gao();
	return 0;
}
