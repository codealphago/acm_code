#include<iostream>
#include<cstring>
using namespace std;
template <typename T,int SIZE>
class Array{
	private:
		T *data;
		int len;
	public:
		void overflow(){
			T *tmp=new T[len+1];
			memcpy(tmp,data,sizeof(T)*len);
			data=tmp;
			return ;
		}
		void insert(T num){
			data[len++]=num;
			return ;
		}
		void create(){
			T num;
			len=0;
			data=new T[SIZE];
			cout<<"����˳�������(��-1����): "<<endl;
			while(cin>>num && num!=-1)
				data[len++]=num;
			return ;
		}
		void print(){
			int i;
			cout<<"��ǰ��������: "<<endl;
			for(i=0;i<len;++i){
				cout<<data[i]<<' ';
			}
			cout<<endl;
			return ;
		}
};
int main(){
	int num;
	Array<int,50> a;
	a.create();
	a.print();
	cout<<"�����������: "<<endl;
	while(cin>>num){
		a.insert(num);
		a.print();
		cout<<"�����������: "<<endl;
	}
	return 0;
}
