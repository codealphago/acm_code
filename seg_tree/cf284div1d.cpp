/*cf284div1d
  ���⣺��n+1�����У�n��·��ÿ��·���ŵ�n���͵�n+1�����У�Ȼ��ÿ��·��һ��·����Ϣa[i]��������ڵ�ʱ��t��t%a[i]==0������ͨ������·��Ҫ�ȵ���һ��t+1���������ʱ��t��t%a[i]!=0����ͨ������·������ʱ��Ϊ1��������q�����������������������������ͣ�
  A x y ѯ�ʴӳ���x������yҪ���Ѷ���ʱ��
  C x y ��a[x]��Ϊy
  ���ƣ�1 <= n <= 1e5 , 2 <= ai <= 6 , 1 <= q <= 1e5
  ˼·���߶���
  Ҫ�����������O(logn)��ѯ������x��y��ʱ�䡣
  ��Ϊaiֻ�� 2 3 4 5 6 �⼸��ȡֵ����С������Ϊ60��Ҳ����˵�������Ķ�·��������60Ϊ���ڡ�
  ���Զ�·����
  �߶���������һ��t[60]�����飬��ʾ��l������tʱ�̳�����r+1����Ҫ����ʱ�䡣
  ���Ǻ�����ά����������ܹ��ˡ�
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int a[N];
struct Seg{
	int l,r,mid;
	int t[60];
}seg[3*N];
void up(int n){
	for(int i=0;i<60;++i){
		int tmp=i+seg[2*n].t[i];	//ע��ĵط�
		seg[n].t[i]=tmp-i+seg[2*n+1].t[tmp%60];
	}
}
void build(int l,int r,int n){
	seg[n].l=l; seg[n].r=r; seg[n].mid=(l+r)>>1;
	if(l==r){
		for(int i=0;i<60;++i)
			if(i%a[l]==0) seg[n].t[i]=2;
			else seg[n].t[i]=1;
		return ;
	}
	build(l,seg[n].mid,2*n);
	build(seg[n].mid+1,r,2*n+1);
	up(n);
}
void update(int u,int n,int x){
	if(seg[n].l==seg[n].r){
		a[u]=x;
		for(int i=0;i<60;++i)
			if(i%a[u]==0) seg[n].t[i]=2;
			else seg[n].t[i]=1;
		return ;
	}
	if(u<=seg[n].mid) update(u,2*n,x);
	else update(u,2*n+1,x);
	up(n);
}
int query(int l,int r,int n,int t){
	if(l <= seg[n].l && seg[n].r <= r){
		return t+seg[n].t[t%60];
	}
	if(seg[n].mid>=l) t=query(l,r,2*n,t);
	if(seg[n].mid<r) t=query(l,r,2*n+1,t);
	return t;
}
void debug(int n){
	cout<<"---"<<endl;
	for(int i=1;i<=n;++i)
		cout<<query(i,i,1,0)<<' ';
	cout<<endl;
	cout<<"---"<<endl;
}
void debug1(int n){
	cout<<seg[n].l<<' '<<seg[n].r<<' '<<seg[n].t[0]<<endl;
	if(seg[n].l==seg[n].r) return ;
	debug1(2*n);
	debug1(2*n+1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,n,1);
	int m;
	scanf("%d",&m);
	char op[2];
	int u,v;
	for(int i=0;i<m;++i){
		scanf("%s%d%d",op,&u,&v);
		if(op[0]=='A'){
			printf("%d\n",query(u,v-1,1,0));
		}
		else{
			update(u,1,v);
		}
	}
	return 0;
}
