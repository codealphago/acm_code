#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int size;
struct node{
	node *left,*right;
	int pri,num;
};
node *splay(int pri,node *rt){
	node h,*l,*r,*p;
	if(rt==NULL)
		return rt;
	h.left=h.right=NULL;
	l=r=&h;
	while(1){
		if(pri<rt->pri){
			if(rt->left==NULL)
				break;
			//���������˵���ǡ�һ���͡���ת
			if(pri<rt->left->pri){
				p=rt->left;	/*rotate right*/
				rt->left=p->right;
				p->right=rt;
				rt=p;
				if(rt->left==NULL)
					break;
			}
			//��̬�Ľ��м����ġ���ǰ�ڵ㡱׷�ӵ�r���У�ͬʱ������h��
			r->left=rt;	/*link right*/
			r=rt;
			rt=rt->left;
		}
		else if(pri>rt->pri){
			if(rt->right==NULL)
				break;
			if(pri>rt->right->pri){
				p=rt->right;
				rt->right=p->left;
				p->left=rt;
				rt=p;
				if(rt->right==NULL)
					break;
			}
			l->right=rt;
			l=rt;
			rt=rt->right;
		}
		else
			break;
	}
	l->right=rt->left;
	r->left=rt->right;
	rt->left=h.right;
	rt->right=h.left;
	return rt;
}
node *insert(int pri,int num,node *rt){
	node *p=new node();
	p->pri=pri;
	p->num=num;
	if(rt==NULL){
		p->left=p->right=NULL;
		size=1;
		return p;
	}
	rt=splay(pri,rt);
	if(pri<rt->pri){
		p->left=rt->left;
		p->right=rt;
		rt->left=NULL;
		++size;
		return p;
	}
	else if(pri>rt->pri){
		p->right=rt->right;
		p->left=rt;
		rt->right=NULL;
		++size;
		return p;
	}
	else{
		delete p;
		return rt;
	}
}
node *getMax(node *p){
	while(p->right){
		p=p->right;
	}
	return p;
}
node *getMin(node *p){
	while(p->left){
		p=p->left;
	}
	return p;
}
/*��Ҫɾ���Ľڵ���������
ɾ������ʣ����������L������������R������������
ʹ��DeleteMax����L�����ڵ㣬��ʱ��L�ĸ�û����������
ʹR��ΪL�ĸ�����������*/
node *deleteSplayTree(int pri,node *rt){
	node *x;
	if(rt==NULL){
		return NULL;
	}
	rt=splay(pri,rt);
	if(pri==rt->pri){
		if(rt->left==NULL){
			x=rt->right;
		}
		else{
			//x=splay(pri,rt->left);	//������������д�
			x=splay(getMax(rt->left)->pri,rt->left);
			x->right=rt->right;
		}
		--size;
		delete rt;
		return x;
	}
	return rt;
}
int main(){
	int n,num,pri;
	node *_max,*_min;
	node *rt=NULL;
	int i;
	size=0;
	while(scanf("%d",&n) && n){
		switch(n){
			case 1:
				scanf("%d%d",&num,&pri);
				rt=insert(pri,num,rt);
				break;
			case 2:
				if(rt==NULL)
					printf("%d\n",0);
				else{
					_max=getMax(rt);
					printf("%d\n",_max->num);
					rt=deleteSplayTree(_max->pri,rt);
				}
				break;
			case 3:
				if(rt==NULL)
					printf("%d\n",0);
				else{
					_min=getMin(rt);
					printf("%d\n",_min->num);
					rt=deleteSplayTree(_min->pri,rt);
				}
				break;
		}
	}
	return 0;
}

