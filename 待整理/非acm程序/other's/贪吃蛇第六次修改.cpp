#include <iostream.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>  //ʹ�õ�ǰʱ��������;
#include <iomanip.h>
#pragma  comment(lib,"winmm.lib")
enum dir{up,down,left,right};  //ö������enum dir;
char pp=0;
int aa=0,bb=0;
float tt=0;
class player{
public:
	char name[2][20];
	int scordrember[2][100];
	char woner[100];
}p;
class Fence{
public:
	void InputFence();
	void OutputFence();
public:
	char game[20][20];
}f; //�������;
//�����;
void Fence::InputFence()
{
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
		{
			if(i==0||i==19)
				game[i][j]= '-';
			else 
				if(j==0||j==19)
					game[i][j]='|';
				else 
					game[i][j]=' ';
		}
	game[8][8]='*';game[8][9]='*';game[8][10]='*';game[9][10]='*';game[10][10]='*';game[11][10]='*';
}
//�߽��;
class SnakeNode1{
private:
	int x1,y1;
	SnakeNode1 *prior1,*next1;
public:
	int Scord1;
	void add_head1(int x1,int y1);
	int get_x1();
	int get_y1();
	void delete_tail1();
	void SCORD1();
	void Delete1(SnakeNode1 *root);
}player1,*head1=NULL,*tail1=NULL;
void SnakeNode1::Delete1(SnakeNode1 *root)
{
	if (root!=NULL)
		Delete1(root->next1);
	delete root;
} 
class SnakeNode2{
private:
	int x2,y2;
	SnakeNode2 *prior2,*next2;
public:
	int Scord2;
	void add_head2(int x2,int y2);
	int get_x2();
	int get_y2();
	void delete_tail2();
	void SCORD2();
	void Delete2(SnakeNode2 *root);
}player2,*head2=NULL,*tail2=NULL;
void SnakeNode2::Delete2(SnakeNode2 *root)
{
	if (root!=NULL)
		Delete2(root->next2);
	delete root;
}
//��ʾ���;
void Fence::OutputFence(){
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<=20; j++)
			if (j!=20)
				cout<<game[i][j]<<' ';
			else
			{
				if (i==2)
					cout<<"ʣ��ʱ�䣺"<<tt;
				if (i==3)
					cout<<p.name[0]<<"�ĵ�ǰ������::"<<player1.Scord1;
				if (i==4)
					cout<<p.name[1]<<"�ĵ�ǰ������::"<<player2.Scord2;
			}
		cout<<endl;
	}
}
void SnakeNode1::SCORD1()
{
	player1.Scord1=0;
}
void SnakeNode2::SCORD2()
{
	player2.Scord2=0;
}
//����ͷ���;
void SnakeNode1::add_head1(int x,int y){
	SnakeNode1 *q=new SnakeNode1;

	q->x1 =x; q->y1 =y;
	q->next1 =head1;
	q->prior1 =NULL;
	if(head1) head1->prior1 =q;
	head1=q;
	if(!tail1) tail1 =head1;
	f.game[x][y]= '*';  //f��������ڶ���Fence��ʱ����; ��Fence����SnakeNode��ǰ����;
}
void SnakeNode2::add_head2(int x,int y){
	SnakeNode2 *q=new SnakeNode2;
	q->x2 =x; q->y2 =y;
	q->next2 =head2;
	q->prior2 =NULL;
	if(head2) head2->prior2 =q;
	head2=q;
	if(!tail2) tail2 =head2;
	f.game[x][y]= '*';  //f��������ڶ���Fence��ʱ����; ��Fence����SnakeNode��ǰ����;
}

int SnakeNode1::get_x1(){
	return x1;
}
int SnakeNode2::get_x2(){
	return x2;
}

int SnakeNode1::get_y1(){
	return y1;
}
int SnakeNode2::get_y2(){
	return y2;
}

//ɾ��β���;
void SnakeNode1::delete_tail1(){
	SnakeNode1 *p =tail1;
	f.game[tail1->get_x1()][tail1->get_y1()]= ' ';//��β���������ʾ��'*'��Ϊ�ո�;
	if(tail1==head1)
	tail1=head1=NULL;
	else{
		tail1=tail1->prior1;
		tail1->next1=NULL;
	}
	delete p;
}
void SnakeNode2::delete_tail2(){
	SnakeNode2 *p =tail2;
	f.game[tail2->get_x2()][tail2->get_y2()]= ' ';//��β���������ʾ��'*'��Ϊ�ո�;
	if(tail2==head2)
	tail2=head2=NULL;
	else{
		tail2=tail2->prior2;
		tail2->next2=NULL;
	}
	delete p;
}

//move�ƶ�;
class move1{
public:
	dir point1,point2;    //ö�ٱ���point: ���Ʒ���;
	int food_x1;
	int food_y1;
	move1()
	{
		point1=down;
		point2=up;
	}
	int moving1();
	int moving2();
	void change_point1(int &);  //�ı䷽��;	//��
	void get_food1();
};
int move1::moving1(){
	int a,b;
	a= head1->get_x1();  //ȡ��ͷ��������
	b= head1->get_y1();  //ͷ���������
	switch(point1)
	{
		case up: --a; 
			break;
		case down: ++a;
			break;
		case left: --b; 
			break;
		case right: ++b; 
			break;
	}
	if(a==19||b==19||a==0||b==0||f.game[a][b]=='*'){//�ж��Ƿ�ײǽ;
		for(int i=0;i<100;i++){
			if(p.scordrember[0][i]==0){
				p.scordrember[0][i]=player1.Scord1;}
		}
		for(int j=0;j<100;j++)
			{
				if(p.scordrember[1][j]==0)
					p.scordrember[1][j]=player2.Scord2;
			}
	//	player2.Scord2=0;
	//	player1.Scord1=0;
		player1.Scord1-=5;
		cout<<p.name[0]<<"ײ��!!!��5��"<<endl;
		cout<<p.name[1]<<"���ٽ�����!!!"<<endl;
		if(tt>0){
		while(1){
		cout<<"�����y�����ڶ�����Ϸ:";
		cin>>pp;
		if(pp=='y'||pp=='Y'){
			return 1;
		    break;}
		else
			cout<<"�����������������...";
		}
		}
		/*if(tt<=0)
			return 0;*/
	}
	if(a==food_x1 && b==food_y1){					//��food;
		head1->add_head1(a,b);
		player1.Scord1++;
		get_food1();
		return 3;
	}
	else if(a==aa&&b==bb){
	head1->add_head1(a,b);
	player1.Scord1+=4;
	return 3;
	}
	else{
		head1->add_head1(a,b); //����ͷ���;
	    head1->delete_tail1(); //ɾ��β���;
		return 3;
	}
}
int move1::moving2()
{
	int a;int b;
	a= head2->get_x2();  //ȡ��ͷ��������
	b= head2->get_y2();  //ͷ���������
	switch(point2)
	{	
		case up: --a; 
			break;
		case down: ++a;
			break;
		case left: --b; 
			break;
		case right: ++b; 
			break;
		case 'n':break; 
	}
	if(a==19||b==19||a==0||b==0||f.game[a][b]=='*'){//�ж��Ƿ�ײǽ;	
		for(int i=0;i<100;i++){
			if(p.scordrember[0][i]==0){
				p.scordrember[0][i]=player1.Scord1;}
		}
		for(int j=0;j<100;j++)
			{
				if(p.scordrember[1][j]==0)
					p.scordrember[1][j]=player2.Scord2;
			}
		//player2.Scord2=0;
		//player1.Scord1=0;
		player2.Scord2-=5;
		cout<<p.name[1]<<"ײ��!!!��5��"<<endl;
		cout<<p.name[0]<<"���ٽ�����!!!"<<endl;
		if(tt>0){
		while(1){
		cout<<"�����y�����ڶ�����Ϸ:";
		cin>>pp;
		if(pp=='y'||pp=='Y'){
			return 1;
		    break;}
		else
			cout<<"�����������������...";
		}
		}
	/*	if(tt<=0)
			return 0;*/
	}
	if(a==food_x1 && b==food_y1){					//��food;
		head2->add_head2(a,b);
		player2.Scord2++;
		get_food1();
		return 3;
	}
	else if(a==aa&&b==bb){
	head2->add_head2(a,b);
	player2.Scord2+=4;
	return 3;}
	else{
		head2->add_head2(a,b); //����ͷ���;
	    head2->delete_tail2(); //ɾ��β���;
		return 3;
	}
}

void move1::change_point1(int &flag)	//��
{
	switch(getch())
	{
		case 'W':	case 'w':if (point1!=down)
								point1=up;
							break;
		case 'S':	case 's':if (point1!=up)
								point1=down;
							break;
		case 'A':	case 'a':if (point1!=right)
								point1=left;
							break;
		case 'D':	case 'd':if (point1!=left)
								point1=right;
							break;
				case 72:if (point2!=down)
							point2=up;
						break;
				case 80:if (point2!=up)
							point2=down;
						break;
				case 75:if (point2!=right)
							point2=left;
						break;
				case 77:if (point2!=left)
							point2=right;
						break;
				case 'n':flag=1;	//��
						 break; 
	}
}
void move1::get_food1(){
	while(1)
	{
		srand((unsigned int) time(NULL)); //������(��������ʱ��); 
		food_x1= rand()%18+1; 
		food_y1= rand()%18+1;
		if(f.game[food_x1][food_y1]==' ')
		{
			f.game[food_x1][food_y1]=3;
			if((food_x1==3||food_y1==18||food_x1==4||food_x1==5)&&f.game[aa][bb]!=4)
			{
				aa=rand()%18+1;
				bb=rand()%18+1;
				if(f.game[aa][bb]==' ')
					f.game[aa][bb]=4;
			}
			break;
		}
		else
			continue;
	}
}
void judgewoner()
{
	int a,b;
	a=player1.Scord1;
	b=player2.Scord2;
	if(a>b)
		cout<<p.name[0]<<"��ʤһ��";
    if(a<b)
		cout<<p.name[1]<<"��ʤһ��";
    if(a=b)
	   cout<<p.name[0]<<"��"<<p.name[1]<<"������";
}
int main(){
	char x,y;
	int cc=4,dd=4;
	int flag;	//��
	cout<<"********************************************************"<<endl;
	cout<<"     *****   *        *       *       *   *   ******    "<<endl;
	cout<<"    *        * *      *     *   *     *  *    *         "<<endl;
	cout<<"      ***    *   *    *    *******    * *     *****     "<<endl;
	cout<<"          *  *     *  *   *       *   * *     *         "<<endl;
	cout<<"    ******   *        *  *         *  *    *  ******    "<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"���1ʹ��"<<"w,s,a,d"<<"������С�ߵķ���!!!"<<endl;
	cout<<"���2ʹ�÷����������С�ߵķ���!!!"<<endl;
	void SnakeNode1::SCORD1();
	void SnakeNode2::SCORD2();
	cout<<"���������������"<<endl;
	cout<<"���1:";
	cin>>p.name[0];
	cout<<"���2:";
	cin>>p.name[1];
	cout<<"�������Ϸʱ��(��λ��s):";
	char ttp[1000];
	while (cin>>ttp)
	{
		int i=0;
		for (i=0;i<strlen(ttp);i++)
			if (ttp[i]>'9' || ttp[i]<'0')
				break;
		if (i==strlen(ttp))
			break;
		else
			cout<<"������Ĳ����������ݣ����������룺"<<endl;
	}
	sscanf(ttp,"%f",&tt);
	flag=0;	//��
	while(1)
	{
	mciSendString("play 1.mp3 repeat",NULL,0,NULL);
	move1 m;
	f.InputFence();
	player1.add_head1(4,3);
	player1.add_head1(4,4);
	player1.add_head1(4,5);
	
	player2.add_head2(14,14);
	player2.add_head2(14,15);
	player2.add_head2(14,16);
	
	m.get_food1();
	f.OutputFence();
	while (true)
	{
		if (kbhit())
		{
			m.change_point1(flag);	//��
			if(flag) break;	//��
		}
		if (!kbhit())//�ж���û�а�������;
		{
			if(tt<=0){
				cout<<p.name[0]<<"�ķ�����"<<player1.Scord1<<endl;
				cout<<p.name[1]<<"�ķ�����"<<player2.Scord2<<endl;
				if(player1.Scord1>player2.Scord2){
					cout<<p.name[0]<<"��ʤһ��"<<endl;}
				else if(player1.Scord1<player2.Scord2){
					cout<<p.name[1]<<"��ʤһ��"<<endl;}
				else if(player1.Scord1==player2.Scord2){
					cout<<p.name[0]<<"��"<<p.name[1]<<"������"<<endl;}
				exit(0);
				}
			system("cls");  //��������;
			cc=m.moving1();
		   if(cc==1)
			{
			   dd=1;
			   break;
			}
			cc=m.moving2();
			if(cc==1)
			{
				dd=1;
				break;
			}
			f.OutputFence();
			Sleep(500);//��ͣʱ�䣬������Ϸ�ٶȣ�
			tt-=0.5;
		}
	}
	if(flag) break;
    if(dd==1){
	head1=NULL;
	head2=NULL;
	tail1=NULL;
	tail2=NULL;
	continue;
	}
	else
		break;
	}
	return 0;
}
//void T_game::savegame(void)//������Ϸ
//{
//	freopen("Save\\savegame.txt","w",stdout);
	
//	printf("%d %d\n",pr,pl);
//	for (int i=0;i<=high;i++)
//	{
//		for (int j=0;j<=width;j++)
//			if (j!=width)
//				printf("%d ",scr[i][j]);
//			else
//				printf("%d",scr[i][j]);
//		printf("\n");
//	}
//	printf("%d\n",score);
//	printf("%d\n",life);
//	FINISH=clock();
//	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
//	printf("%.2lf\n",totaltime);

//	fclose(stdout);
//}
//*void T_game::loadgame()//������Ϸ����
//{
//	freopen("Save\\savegame.txt","r",stdin);
//	scanf("%d%d",pr,pl);
//	for (int i=0;i<=high;i++)
//	{
//		for (int j=0;j<=width;j++)
//			scanf("%d",scr[i][j]);
//	}
//	scanf("%d",score);
//	scanf("%d",life);
//	printf("%.2lf",START);
//	
//	fclose(stdin);
//}