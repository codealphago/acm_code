/*****1. ϵͳ�Դ��ķ���*****/
#include<algorithm>
int a[10];
int n;
reverse(a,a+n);

/*****2. ȫ����*****/
#include<algorithm>
int a[n];
sort(a,a+n);
print(a);
while(next_permutation(a,a+len)){
	print(a);
}

/*****3. set set���ú����ʵ�ֵ�*****/
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

/*****4. map*****/
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

/*****5.˫����� deque*****/
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

/*****6.string*****/
string str="123456";
str.substr(2,2); //���34

string str="1243454";
string tmp="4";
cout<<str.find(tmp)<<endl; //���2, find������ǵ�һ���ҵ����±�, ���û���ҵ������һ��<0 ����>=len����
cout<<str.find(tmp,3)<<endl; //���4, ���±�3��ʼ��
cout<<str.rfind(tmp)<<endl; //���6

//find_first_of��������flag�������ַ���str�е�һ�γ��ֵ��±�λ��
string str="123456";
string flag = "43";
cout<<str.find_first_of(flag)<<endl; //���2
//����flag����str��һ����ƥ���λ��
cout<<str.find_first_not_of(flag)<<endl; //���0

string str="12345678";
//str.erase(1,2); //���145678, ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
//str.erase(str.begin()); //���2345678, ɾ��position����һ���ַ�(position�Ǹ�string���͵ĵ�����)
str.erase(str.begin()+1,str.end()); //���1, ɾ����first��last֮����ַ�(first��last���ǵ�����), ����ҿ�

string str="to be question";
string str2="the ";
string str3="or not to be";
string::iterator it;

// used in the same order as described above:
str.insert(6,str2);                 // to be (the )question
str.insert(6,str3,3,4);             // to be (not )the question
str.insert(10,"that is cool",8);    // to be not (that is )the question
str.insert(10,"to be ");            // to be not (to be )that is the question
str.insert(15,1,':');               // to be not to be(:) that is the question
it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
str.insert (it+2,str3.begin(),str3.begin()+3); // (or )

/*****7. ����java*****/
import java.util.*;
Set<String> hash=new HashSet<String>();
Map<String,Integer> hash=new HashMap<String,Integer>();

String str="123456";
System.out.println(str.substring(2,5));
���345

/*****8. vector*****/
push_back();
pop_back();
erase(����дָ���Ǹ�Ԫ�صĵ�����);

/*****9. unordered_map*****/
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int main (){
  unordered_map<string,int> mp;
  mp["asd"]=1;
  cout<<mp["as"]<<' '<<mp["asd"]<<endl;
  return 0;
}

/*****10. ���������*****/
struct node{
    int x, y;
    friend bool operator < (node a, node b){
        return a.x > b.x; //�ṹ���У�xС�����ȼ���
    }
};
priority_queue<node>q;//���巽��
//�ڸýṹ�У�yΪֵ, xΪ���ȼ���
//ͨ���Զ���operator<���������Ƚ�Ԫ���е����ȼ���
//������"<"ʱ����ò�Ҫ����">"�����ܻᷢ���������

/*****11. λͼ*****/
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

/*****set_union/set_intersection*****/
vector<int> vec1;
vector<int> vec2;
vector<int> vec12;
for(int i=0;i<=4;++i)
vec1.push_back(4-i);
for(int i=3;i<=5;++i)
vec2.push_back(i);
sort(vec1.begin(),vec1.end());
sort(vec2.begin(),vec2.end());
set_union(vec1.begin(),vec1.end(),
		vec2.begin(),vec2.end(),
		inserter(vec12,vec12.begin()));	//�󲢼���Ҫ���⿪һ��vector
set_intersection(vec1.begin(),vec1.end(),
			vec2.begin(),vec2.end(),
			inserter(vec12,vec12.begin()));	//�󽻼���Ҫ���⿪һ��vector
for(int i=0;i<vec12.size();++i)
cout<<vec12[i]<<' ';
cout<<endl;
//setҲ��ͬ�����÷�
