#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#define N 35
using namespace std;
clock_t START,FINISH;
const char gameover[10][57]={
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                            {' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{'*',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ','.','.','.','.','.',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.',' ','.','.','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ','.',' ','.',' ','.',' ',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ','*'},
							{'*',' ','.',' ','.','.','.',' ',' ','.','.','.','.','.',' ',' ','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',':',' ',' ',' ',':',' ',' ','.',' ',' ',' ','.',' ',' ','.','.','.','.','.',' ','.',' ','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ','.',' ',' ','.',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ',' ',' ','.',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ','.',' ',' ','.',' ',' ','*'},
							{'*',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.','.','.','.','.',' ','.',' ',' ',' ','.',' ','*'},
							{' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, 
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							};
const char startgame[10][57]={
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                            {' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{'*',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ','.','.','.','.','.',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.',' ','.','.','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ','.',' ','.',' ','.',' ',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ','*'},
							{'*',' ','.',' ','.','.','.',' ',' ','.','.','.','.','.',' ',' ','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',':',' ',' ',' ',':',' ',' ','.',' ',' ',' ','.',' ',' ','.','.','.','.','.',' ','.',' ','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ','.',' ',' ','.',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ',' ',' ','.',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ','.',' ',' ','.',' ',' ','*'},
							{'*',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.','.','.','.','.',' ','.',' ',' ',' ','.',' ','*'},
							{' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, 
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							};     
int new_or_continue;//1Ϊnew,0Ϊcontinue; 
int new_or_exit;////1Ϊnew,0Ϊexit;                
char name[1000];
class T_game
{
private:
	int scr[22][N],pl,pr,width,high,speed,density,score,life,pp,dp;
	int num,nm,nu,np,npt,nl; 
	int pll,plr,pru,prd;
public:
	T_game()
	{
		memset(scr,0,sizeof(scr));
		/*scr[22][N]={0};*/
		width=24;high=21;speed=3;density=15;score=0;life=3;pp=0;dp=0;
		pr=21;pl=width/2;
		num=0;nm=0;nu=0;np=0;npt=100/*20��������ʱ��*/;nl=0; 
		pll=0;plr=width-2;pru=0;prd=high;
		scr[21][pl]=1;
		scr[0][5]=3;
	}
	void printstartgame(void);//�����Ϸ��ʼ����
	void printgameover(void);//�����Ϸ�������� 
	void print(int [][N]);//�������
	void movebul(int [][N]);//�ӵ��ƶ����� 
	void movepla(int [][N]);//�л��ƶ����� 
	void setting();//���ú��� 
	void menu(void);//�˵�����
	void Up(void);//�ϵĲ���
	void Down(void);//�µĲ���
	void Left(void);//��Ĳ���
	void Right(void);//�ҵĲ���
	void Black(void);//�ո������
	void Play(void);//��Ϸȫ�ֿ���
	void savegame(void);//������Ϸ
	void loadgame(void);//������Ϸ����
	void newrank(void);//�������а�
	void loadrank(void);//�������а�
	void setnewgame(void);//����Ϸ����
	void nowtime(void);//��ʾ��ǰʱ�� 
};
void T_game::Up()//�ϵĲ���
{
	if (dp==0) 
		pru=0;
	else
		pru=1;
	if(pr>pru) 
	{
		if (scr[pr-1][pl]==3)
		{
			scr[pr-1][pl]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[--pr][pl]=1;
			if (dp==1)
			{
				scr[pr+2][pl-1]=0,scr[pr+2][pl+1]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//�����ɻ���ʧʱ���µĲ�Ӱ
			{
				if (scr[pr+2][pl-1]==1) scr[pr+2][pl-1]=0;
				if (scr[pr+2][pl+1]==1) scr[pr+2][pl+1]=0;
			}
		}
	}
	return;
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Down()//�µĲ���
{
	
	if (dp==0)	
		prd=high;
	else
		prd=high-1;
	if (pr<prd) 
	{
		if (scr[pr+1][pl]==3)
		{
			scr[pr+1][pl]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[++pr][pl]=1;
			if (dp==1)
			{
				scr[pr][pl-1]=0,scr[pr][pl+1]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//�����ɻ���ʧʱ���µĲ�Ӱ
			{
				if (scr[pr][pl-1]==1) scr[pr][pl-1]=0;
				if (scr[pr][pl+1]==1) scr[pr][pl+1]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Left()//��Ĳ���
{
	if (dp==0) 
		pll=0;
	else 
		pll=1;
	if(pl>pll)
	{
		if (scr[pr][pl-1]==3)
		{
			scr[pr][pl-1]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[pr][--pl]=1;
			if (dp==1)
			{
				scr[pr+1][pl]=0,scr[pr+1][pl+2]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//�����ɻ���ʧʱ���µĲ�Ӱ
			{
				if (scr[pr+1][pl]==1) scr[pr+1][pl]=0;
				if (scr[pr+1][pl+2]==1) scr[pr+1][pl+2]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Right()//�ҵĲ���
{
	if (dp==0) 
		plr=width-2;
	else 
		plr=width-3;
	if(pl<plr) 
	{
		if (scr[pr][pl+1]==3)
		{
			scr[pr][pl+1]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[pr][++pl]=1;
			if (dp==1)
			{
				scr[pr+1][pl]=0,scr[pr+1][pl-2]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//�����ɻ���ʧʱ���µĲ�Ӱ
			{
				if (scr[pr+1][pl]==1) scr[pr+1][pl]=0;
				if (scr[pr+1][pl-2]==1) scr[pr+1][pl-2]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Black()//�ո������
{
	if (dp==1)   //���ܷɻ�ʱ��������
	{
		scr[pr-1][pl]=2;
		scr[pr][pl-1]=2,scr[pr][pl+1]=2;
	}
	else
	{
		if (pp==1)//����˫��
		{
			scr[pr-1][pl-1]=2,scr[pr-1][pl+1]=2,num++;
			if (num>20) 
				pp=0,num=0;
		}
		else
			scr[pr-1][pl]=2;
	}
}
void T_game::printstartgame()//�����Ϸ��������
{
	system("cls");
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<57;j++)
			printf("%c",startgame[i][j]);
		printf("\n");
	}
	nowtime();
	printf("          NEW GAME [N]    OR     CONTINUE [C]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 67:case 99:
				new_or_continue=0;
				c=false;
				break;
			case 78:case 110:
				new_or_continue=1;
				c=false;
				break;
			default:c=true;
		}
	}
}
void T_game::printgameover()//�����Ϸ��������
{
	system("cls");
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<57;j++)
			printf("%c",gameover[i][j]);
		printf("\n");
	}
	printf("          NEW GAME [N]    OR     EXIT [E]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 78:case 110:
				new_or_exit=1;
				c=false;
				break;
			case 69:case 101:
				new_or_exit=0;
				c=false;
				break;
			default:c=true;
		}
	}
	return;
}
void T_game::print(int a[][N])//�������
{
	system("cls"); 
	int i,j;
	for (i=0;i<=high;i++)
	{
		a[i][width-1]=4;
		for(j=0;j<width;j++) 
		{
			if (a[i][j]==-1)
			{
				printf("+");
			}
			if (a[i][j]==-2)
			{
				printf("D");
			}
			if (a[i][j]==-3)
			{
				printf("L");
			}
			if (a[i][j]==-4)
			{
				printf("P");
			}
			if (a[i][j]==0)
				printf(" ");
			if (a[i][j]==1)
				printf("\5");//����һ��ķ���
			if (a[i][j]==2)
			{
				//mciSendString("play 1.mp3",NULL,0,NULL);
				printf(".");//�ӵ�
			}
			if (a[i][j]==3)
				printf("\3"); //����л����� 
			if (a[i][j]==4)
				printf("|"); 
			if (i==0 && j==width-1) 
				printf("Score: %d",score);//���Ͻ���ʾ�÷�
			if (i==1 && j==width-1)
				printf("Life: %d",life);
			if (i==2 && j==width-1)
				printf("Set: Esc");
			if (i==3 && j==width-1)
			{
				FINISH=clock();
				double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;
				printf("Time: %.2lf",totaltime);
			}
		}
		printf("\n");
	}
	return;
}
void T_game::movebul(int a[][N])//�ӵ��ƶ�����
{
	int i,j;
	for (i=0;i<=high;i++)
		for(j=0;j<width;j++)
		{
			if(i==0 && a[i][j]==2)//
				a[i][j]=0;
			if (a[i][j]==2)
			{
				if(a[i-1][j]==3)  //3����л�
				{
					score+=10;//,printf("\7");��ֹ�ӵ����׽�
					mciSendString("play 1.mp3",NULL,0,NULL);
					//Sleep(200);
				}
				/*if (a[i-1][j]==-1)
				{
					a[i][j]=-1,a[i-1][j]=2;      //+���ӵ�����λ��
				}
				else
				{
					a[i][j]=0,a[i-1][j]=2;
				}*/
				if (a[i-1][j]==-1)
				{
					a[i][j]=-1,a[i-1][j]=2;      //+���ӵ�����λ��
					//mciSendString("play 1.mp3",NULL,0,NULL);
				}
				else
					if (a[i-1][j]==-2)
					{
						a[i][j]=-2,a[i-1][j]=2;
						//mciSendString("play 1.mp3",NULL,0,NULL);
					}
					else
						if (a[i-1][j]==-3)
						{
							a[i][j]=-3,a[i-1][j]=2;
							//mciSendString("play 1.mp3",NULL,0,NULL);
						}
						else
						{
							a[i][j]=0,a[i-1][j]=2;
							//mciSendString("play 1.mp3",NULL,0,NULL);
						}
			}
		}
	return;
} 
void T_game::movepla(int a[][N])//�л��ƶ�����
{
	int i,j;
	for (i=high;i>=0;i--)//�����һ��������Ϊ�˱���ѵл�ֱ�ӳ�����顣
		for(j=0;j<width;j++)
		{
			if (i==high && a[i][j]==3)
				a[i][j]=0;//���и�ֵ0����Խ�硣
			if (a[i][j]==3)
			{
				a[i][j]=0;
				if (i!=high)
					a[i+1][j]=3;
			}
			 /*if (a[i][j]==3)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=3;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=3;
					 else
						 a[i][j]=0,a[i+1][j]=3;
			 if (a[i][j]==-1)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-1;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-1;
					 else
						 a[i][j]=0,a[i+1][j]=-1;
			 if (a[i][j]==-2)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-2;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-2;
					 else
						 a[i][j]=0,a[i+1][j]=-2;
			 if (a[i][j]==-3)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-3;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-3;
					 else
						 a[i][j]=0,a[i+1][j]=-3;*/
			 if (a[i][j]==-1)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-1;
			 }
			 if (a[i][j]==-2)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-2;
			 }
			 if (a[i][j]==-3)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-3;
			 }
		 }
	if (dp==0 && a[pr-1][pl]==3 && a[pr][pl]==1)//��1�ܷɻ�
	{
		a[pr-1][pl]=0;
		a[pr][pl]=0;
		life--;//death++;
		//if (a[pr+1][pl-1]==1) a[pr+1][pl-1]=0;//�ɻ�������ʱ�����ɻ���Ӱ��
		//if (a[pr+1][pl+1]==1) a[pr+1][pl+1]=0;//�ɻ�������ʱ�����ɻ���Ӱ��
		pr=high;pl=width/2;//�ɻ����³��ֵ�λ��
		if (life!=0) a[pr][pl]=1;//�ɻ����³��ֵ�λ�ò����ɻ�
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr+1][pl-1]==1 && a[pr+1][pl+1]==1)//3�ܷɻ��е��м�
	{
		life--;//death++;
		a[pr-1][pl]=0;
		a[pr][pl]=0;
		if (a[pr+1][pl-1]==1) a[pr+1][pl-1]=0;//�ɻ�������ʱ�����ɻ���Ӱ��
		if (a[pr+1][pl+1]==1) a[pr+1][pl+1]=0;//�ɻ�������ʱ�����ɻ���Ӱ��
		pr=high;pl=width/2;//�ɻ����³��ֵ�λ��
		if (life!=0) a[pr][pl]=1;//�ɻ����³��ֵ�λ�ò����ɻ�
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr][pl+2]==1 && a[pr-1][pl+1]==1)//��3�ܷɻ��е����
	{
		a[pr-1][pl]=0,a[pr+1][pl]=3;
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr][pl-2]==1 && a[pr-1][pl-1]==1)//��3�ܷɻ��е��Ҽ�
	{
		a[pr-1][pl]=0,a[pr+1][pl]=3;
	}
	if (a[pr-1][pl]==-1 && a[pr][pl]==1)
	{
		pp=1;
		a[pr-1][pl]=0;//��+�Ե�
	}
	if (a[pr-1][pl]==-2 && a[pr][pl]==1)
	{
		dp=1;
		a[pr-1][pl]=0,a[pr][pl]=1,a[pr+1][pl-1]=1,a[pr+1][pl+1]=1;//��D�Ե�
	}
	if (a[pr-1][pl]==-3 && a[pr][pl]==1)
	{
		life++;
		a[pr-1][pl]=0;//��L�Ե�
	}
	return;
} 
void T_game::savegame(void)//������Ϸ
{
	
	ofstream fout("Save\\savegame.txt");
	/*printf("%d %d\n",pr,pl);
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			if (j!=width)
				printf("%d ",scr[i][j]);
			else
				printf("%d",scr[i][j]);
		printf("\n");
	}
	printf("%d\n",score);
	printf("%d\n",life);

	FINISH=clock();
	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
	printf("%.2lf\n",totaltime);*/
	//fclose(stdout);
	fout<<pr<<' '<<pl<<endl;
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			if (j!=width)
				fout<<scr[i][j]<<' ';
			else
				fout<<scr[i][j]<<endl;
	}
	fout<<score<<endl<<life<<endl;
	FINISH=clock();
	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
	fout<<setprecision(2)<<totaltime;
	
	fout.close();
	return;
}
void T_game::loadgame()//������Ϸ����
{
	freopen("Save\\savegame.txt","r",stdin);
	
	scanf("%d%d",&pr,&pl);
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			scanf("%d",&scr[i][j]);
	}
	scanf("%d",&score);
	scanf("%d",&life);
	printf("%.2lf",&START);
	
	fclose(stdin);
}
void T_game::newrank()//�������а�
{
	freopen("Rank\\newrank.txt","r",stdin);
	freopen("Rank\\oldrank.txt","w",stdout);//���ļ������
	
	int rank[10],i;
	for (i=1;i<=3;i++)
		scanf("%d",&rank[i]);
	for (i=1;i<=3;i++)
		if (score>rank[i])
		{
			rank[i]=score;
		}
	for (i=1;i<=3;i++)
		printf("%d\n",rank[i]);
	
	fclose(stdin);
	fclose(stdout);//�ر��ļ������
	system("copy Rank\\oldrank.txt Rank\\newrank.txt");//���ı��ļ�oldrank.txt��������ݸ��Ƶ��ı��ļ�newrank.txt����
}
void T_game::loadrank()//�������а�
{
	freopen("Rank\\newrank.txt","r",stdin);
	
	int rank[10],i;
	for (i=1;i<=3;i++)
		scanf("%d",&rank[i]);

	for (i=1;i<=3;i++)
		printf("%d\n",rank[i]);

	fclose(stdin);
	printf("           BACK [B]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 66:case 98:
				loadgame();
				c=false;
				break;
			default:c=true;
		}
	}
	//fclose(stdin);
	return;
}
void T_game::setnewgame(void)//����Ϸ����
{
	START=clock();
	life=3;
	score=0;
	memset(scr,0,sizeof(scr));
	pl=9;pr=21;width=24;high=21;speed=3;density=15;score=0;life=3;pp=0;dp=0;
	num=0;nm=0;nu=0;np=0;npt=100;nl=0;//npt==20��������ʱ�� 
	pll=0;plr=width-2;pru=0;prd=high;
	scr[pr][pl]=1;
	scr[0][5]=3;
}
void T_game::nowtime(void)//��ʾ��ǰʱ�� 
{
	time_t curtime=time(0); 
	tm tim =*localtime(&curtime); 
	int day,mon,year,hour,minute,second; 
	day=tim.tm_mday;
	mon=tim.tm_mon;
	year=tim.tm_year;
	hour=tim.tm_hour;
	minute=tim.tm_min;
	second=tim.tm_sec;
	printf("%d��%d��%d��%dʱ%d��%d��\n",year+1900,mon+1,day,hour,minute,second);
}
void T_game::setting(void)//���ú���
{
	int sw=0,i,j;
	system("cls");
	do {
		sw=0;
		printf("\nThe size of the screen: 1.Big 2.Small >> ");
		switch(getche()) 
		{
		case '1':width=34;
			break; 
		case '2':width=24;
			;break;
		default:printf("\nError,Please re select...\n"); 
			sw=1; 
		} 
	}while(sw); 
	do {
		sw=0; 
		printf("\nPlease select the density: 1.Big 2.Middle 3.Small >> ");
		switch(getche()) 
		{
			case '0':density=10;
				break; 
			case '1':density=20;
				break;
			case '2':density=30;
				break; 
			case '3':density=40;
				break; 
			default:printf("\nError,Please re select...\n"); 
				sw=1;
		} 
	}while(sw);
	do {
		sw=0;
		printf("\nThe enemy planes flying speed: 1.Quick 2.Middle 3.Slow >> ");
		switch(getche()) 
		{
			case '1':speed=2;
				break; 
			case '2':speed=3;
				break; 
			case '3':speed=4;
				break;
			default:printf("\nError,Please re select...\n"); 
				sw=1;
		}
	}while(sw);
	for(i=0;i<22;i++)
		for(j=0;j<45;j++)
			scr[i][j]=0;
	scr[high][pl=width/2]=1;
	printf("\nSave the press any key...\n");
	getch();
} 
void T_game::menu(void)//�˵�����
{
	printf("\n");
	if (new_or_continue==0)
		printf("        You Choice CONTINUE\n");
	else
		printf("        You Choice NEW GAME\n");
	printf("\n");
	printf("Explain:\n");
	printf("UP   : %c Control Plane UP\n",24);//Press  %c %c %c %c Control Plane\nSet: Press Esc\n",24,25,27,26,5);
	printf("DOWN : %c Control Plane DOWN\n",25);
	printf("LEFT : %c Control Plane LETF\n",27);
	printf("RIGHT: %c Control Plane RIGHT\n",26);
	printf("BLOCK: %c Control Bullets\n",220);
	printf("\n");
	printf("  ESC: Set Game\n");
	printf("    S: Save the Game\n ");
	printf("\n");
	printf("Strat Game: Any key\n");
	if (getch()==27)
		setting();
	system("cls");
}
void T_game::Play()//��Ϸȫ�ֿ���
{
	new_or_continue=1;
	new_or_exit=0;
	printstartgame();
	system("cls");
	menu(); 
	int i=0,j=0;
	if (new_or_continue==0)
		loadgame();
	else
	{
		printf("Your name : ");
		scanf("%s",name);
	}
	
	START=clock();
	time_t cc;
	int count=0;
	while(1) 
	{
		count++;
		//cc=clock();
		//Sleep(10);
		mciSendString("play c3.mp3 repeat",NULL,0,NULL);
		//Sleep(300);
		if (life==0) 
		{
			printgameover();
			if (new_or_exit==1)
			{
				setnewgame();
			}
			else
			{
				break;
			}
		}
		if (kbhit())
			switch(getch())   //�������������ƶ��ͽ���˵�
			{
				case 72:Up();
						break;
				case 80:Down();
						break;
				case 75:Left();
						break;
				case 77:Right();
						break;
				case 32:Black();				
						break; 
				case 27:setting();    //ecs ASCII
						break;
				case 82:case 114:system("cls");
								loadrank();
								break;
				case 83:case 115:savegame();
								break;
								//exit(0);
					break;
			}
		if (++j%density==0)//���������л����ٶ�
		{
			j=0;
			nm++;//����+
			nu++;//����D
			nl++;//����L
			srand(time(NULL));
			if (nm==9 && dp==0)
				scr[0][rand()%width]=-1;//����+
			else
				if (nu==15 && dp==0)
					scr[0][rand()%width]=-2;//����D
				else
					if (nl==20)
						scr[0][rand()%width]=-3;//����L
					else
						scr[0][rand()%width]=3;//�����л�
			if (nm>10) nm=0;
			if (nu>16) nu=0;
			if (nl>20) nl=0;
		}
		if (++i%speed==0)//���Ƶл��ƶ��ٶȣ�������ӵ��ƶ��ٶ� 
			movepla(scr);
		movebul(scr);
		print(scr); 
		printf("%6d %6d\n",clock(),count);
		Sleep(max(count*50-(clock()-START),0));
		if (i==30000) i=0;//����iԽ��
		//if (j==30000) j=0;//����jԽ��
	}
	printf("\n");
}
int main()
{
	T_game T;
	T.Play();
	return 0;
}
