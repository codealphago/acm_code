#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int i,flag,t;	//��λ��־ 
    char a[105];	//һ�㿪��һ�㣬��ֹԽ�� 
    cin>>t;
    while(t--){
    	cin>>a;		//getchar()����ո񣬻س�����Ҫ�����á� 
    	flag=1;
 		for(i=strlen(a)-1;i>=0;--i){
 			a[i]=a[i]+flag;
 			flag=0;
 			if(a[i]>'9'){
 				a[i]='0';
 				flag=1;
 			}
 		}
    	if(flag==1) cout<<flag;
    	cout<<a<<endl;
    }
    return 0;
}
