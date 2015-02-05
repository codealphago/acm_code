#include<iostream>
using namespace std;
struct ArcNode{
	int adjvex,info;
	ArcNode *nextarc;
};
void addarc(ArcNode *head[],int u,int v){
	ArcNode *p=new ArcNode();
	p->adjvex=v;
	p->nextarc=head[u-1];
	head[u-1]=p;
}
void delarc(ArcNode *head[],int u,int v){
	ArcNode *p,*q;
	for(p=head[u-1];p;p=p->nextarc){
		if(p->nextarc && p->nextarc->adjvex==v){
			q=p->nextarc;
			p->nextarc=q->nextarc;
			delete q;
			break;
		}
	}
}
void create(ArcNode *head[],int n,int e){
	int i,u,v;
	for(i=0;i<n;++i){
		head[i]=NULL;
	}
	for(i=0;i<e;++i){
		cin>>u>>v;
		addarc(head,u,v);
	}
}
void print(ArcNode *head[],int n){
	int i;
	ArcNode *p;
	for(i=0;i<n;++i){
		for(p=head[i];p;p=p->nextarc){
			cout<<i+1<<' '<<p->adjvex<<endl;
		}
	}
}
int main(){
	int n,e,u,v;
	cout<<"����ͼ: "<<endl;
	cin>>n>>e;
	ArcNode **head=new ArcNode *[n];
	create(head,n,e);
	cout<<"ԭͼ: "<<endl;
	print(head,n);
	cout<<"����Ҫ�ӵı�: "<<endl;
	cin>>u>>v;
	addarc(head,u,v);
	cout<<"�ӱߺ��ͼ: "<<endl;
	print(head,n);
	cout<<"����Ҫɾ�ı�: "<<endl;
	cin>>u>>v;
	delarc(head,u,v);
	cout<<"ɾ�ߺ��ͼ: "<<endl;
	print(head,n);
	return 0;
}
