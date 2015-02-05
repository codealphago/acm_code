/*Problem Description
Ignatius�������һ������,��ʦ�������ܶ൥��(ֻ��Сд��ĸ���,�������ظ��ĵ��ʳ���),������ʦҪ��ͳ�Ƴ���ĳ���ַ���Ϊǰ׺�ĵ�������(���ʱ���Ҳ���Լ���ǰ׺).
Input
�������ݵĵ�һ������һ�ŵ��ʱ�,ÿ��һ������,���ʵĳ��Ȳ�����10,���Ǵ��������ʦ����Ignatiusͳ�Ƶĵ���,һ�����д����ʱ�Ľ���.�ڶ�������һ����������,ÿ��һ������,ÿ�����ʶ���һ���ַ���.
ע��:����ֻ��һ���������,�����ļ�����.
Output
����ÿ������,�����Ը��ַ���Ϊǰ׺�ĵ��ʵ�����.*/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXB=26;	//�޸Ĵ�1
struct Node{
    struct Node *br[MAXB];
    int num;
};
Node *head;
void Tree_insert(char str[]){	//���뵥��
    Node *t,*s=head;
    int i,j;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a'; //�޸Ĵ�2
        if(s->br[id]==NULL){
            t=new Node;
            for(j=0;j<MAXB;j++){
                t->br[j]=NULL;
            }    
            t->num=0;	//�޸Ĵ�3
            s->br[id]=t;
        }    
        s=s->br[id];
        s->num++;	//�޸Ĵ�4
    }    
}    
int Tree_Find(char str[]){
    Node *s=head;
    int count,i;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a';	//�޸Ĵ�5
        if(s->br[id]==NULL){
            return 0;
        }    
        else{
            s=s->br[id];
            count=s->num;	//�޸Ĵ�6
        }    
    }    
    return count;
}
int main(){
    int i;
    head=new Node;
    for(i=0;i<MAXB;i++){
        head->br[i]=NULL;
        head->num=0;	//�޸Ĵ�7
    }    
    char str[12];
    while(gets(str)&&str[0])  Tree_insert(str);
    while(gets(str))  printf("%d\n",Tree_Find(str));
    return 0;
}

