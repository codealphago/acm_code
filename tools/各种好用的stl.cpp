//ϵͳ�Դ��ķ���
#include<algorithm>
int a[10];
int n;
reverse(a,a+n);

//���ֺ��õ�stl
//1. ȫ����
#include<algorithm>
int a[n];
sort(a,a+n);
print(a);
while(next_permutation(a,a+len)){
	print(a);
}

//2. set set���ú����ʵ�ֵ�
#include<set>
set<int> _set;
_set.clear();
if(_set.find(tmp)!=_set.end()){
	//Ԫ����_set��
}
else{
	//Ԫ�ز���_set��
}
_set.insert(x);	//��x����_set��
//��������set
set<int>::iterator it=_set.begin();
for(;it!=_set.end();it++) cout<<*it<<" ";
//ɾ��
_set.erase(10);
//��ȡset��С
int sz=_set.size();
//��ȡָ��Ԫ�ؼ���ǰһ��Ԫ��
set<int>::iterator it=_set.find(10);
cout<<*(--it)<<endl;

//3. map
#include<iostream>
#include<map>
using namespace std;
#define mp make_pair
//map<string,int> _map;
hash_map<string,int> _map;
int main(){
	_map.clear();

	//����Ԫ�ص����ַ���
	_map.insert(mp("aab",1));
	_map["aaa"]=3;
	_map["zzz"]=1;
	_map["ccc"]=10;

	if(_map.find("aac")!=_map.end()){
		//Ԫ����_map��
		cout<<_map["aaa"]<<endl;
	}
	else{
		//Ԫ�ز���_map��
		//Ԫ�ز��ڣ�Ĭ��ֵΪ0
		cout<<_map["aac"]<<endl;
	}
	
	//����map,����ֵ����
	map<string,int>::iterator it;
    for(it=_map.begin();it!=_map.end();++it)
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;

	//ɾ��
	_map.erase(10);
	
	//��С
	int sz=_map.size();

	//��ȡָ��Ԫ�ؼ���ǰһ��Ԫ��
	it=_map.find("zzz");
	--it;
	cout<<it->first<<' '<<it->second<<endl;
}

//4.˫����� deque
#include <deque>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	deque<int> ideq(20); //Create a deque ideq with 20 elements of default value 0
	deque<int>::iterator pos;
	int i;

	//ʹ��assign()��ֵ  assign�ڼ�����о��Ǹ�ֵ����˼
	for (i = 0; i < 20; ++i)
		ideq[i] = i;
	
	//���deque
	printf("���deque������:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	//��ͷβ����������
	printf("\n��ͷβ����������...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	//��ȡͷβ����
	cout<<ideq.front()<<' '<<ideq.back()<<endl;
	//���deque
	printf("\n���deque������:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');

	//����
	const int FINDNUMBER = 19;
	printf("\n����%d\n", FINDNUMBER);
	pos = find(ideq.begin(), ideq.end(), FINDNUMBER);
	if (pos != ideq.end())
		printf("find %d success\n", *pos);
	else
		printf("find failed\n");

	//��ͷβɾ������
	printf("\n��ͷβɾ������...\n");
	ideq.pop_back();
	ideq.pop_front();

	//���deque
	printf("\n���deque������:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
	return 0;
}

//5.string
string str="123456";
str.substr(2,2);
���34

//����java
import java.util.*;
Set<String> hash=new HashSet<String>();
Map<String,Integer> hash=new HashMap<String,Integer>();

String str="123456";
System.out.println(str.substring(2,5));
���345

vector
push_back();
pop_back();
erase(����дָ���Ǹ�Ԫ�صĵ�����);

unordered_map
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int main ()
{
  unordered_map<string,int> mp;
  mp["asd"]=1;
  cout<<mp["as"]<<' '<<mp["asd"]<<endl;
  return 0;
}

struct node
{
    int x, y;
    friend bool operator < (node a, node b)
    {
        return a.x > b.x; //�ṹ���У�xС�����ȼ���
    }
};
priority_queue<node>q;//���巽��
//�ڸýṹ�У�yΪֵ, xΪ���ȼ���
//ͨ���Զ���operator<���������Ƚ�Ԫ���е����ȼ���
//������"<"ʱ����ò�Ҫ����">"�����ܻᷢ���������

//λͼ
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<100> bits,tmp;
	bits[1]=1;
	tmp[10]=1;
	cout<<bits<<endl;
	cout<<tmp<<endl;
	cout<<(bits | tmp)<<endl;
	cout<<(bits & tmp)<<endl;
	return 0;
}

