#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
	//l��ʾ����,w��ʾ����
	const int bas_l=640,bas_w=178*2;        //���Ĵ�С
	char ctr=0,str[10];
	int l,w;				  //һ�����ӵĴ�С
	int l1,w1;                //�����볡�صı߽�
	int l2,w2;				  //���������ӵı߽�	
	int count,i,j;
	while(ctr!=27)
	{
		system("cls");
		cout<<"�������ӳ���(��ȷ��5cm): ";
		cin>>l;
		cout<<"�������ӿ��(��ȷ��5cm): ";
		cin>>w;
		cout<<"���������볡�ر߽�ĺ������(��ȷ��5cm): ";
		cin>>l1;
		cout<<"���������볡�ر߽���������(��ȷ��5cm): ";
		cin>>w1;
		cout<<"�������������ӱ߽�ĺ������(��ȷ��5cm): ";
		cin>>l2;
		cout<<"�������������ӱ߽���������(��ȷ��5cm): ";
		cin>>w2;
		l=l/5;
		w=w/5;
		l1=l1/5;
		w1=w1/5;
		l2=l2/5;
		w2=w2/5;
		count=0;
		initgraph(bas_l+10,bas_w+80);
		setcolor(RED);
		rectangle(0,0,bas_l,bas_w);
		setcolor(YELLOW);
		rectangle(l1,w1,bas_l-l1,bas_w-w1);
		setcolor(WHITE);

		for (i=l1;i+l+l1<=bas_l;i+=l+2*l2)
		{
			for (j=w1;j+2*w+w1<=bas_w;j+=2*w+2*w2)
			{
				rectangle(i,j,i+l,j+2*w);
				count+=2;
			}
			if (j+w+w1<=bas_w)
			{
				rectangle(i,j,i+l,j+w);
				count++;
			}
		}
		if (i+w+l1<=bas_l)
		{
			for (j=w1;j+l+w1<=bas_w;j+=l+2*w2)
			{
				rectangle(i,j,i+w,j+l);
				count++;
			}
		}
		sprintf(str,"%d",count);
		outtextxy(10,bas_w+10,"������Ϊ");
		outtextxy(75,bas_w+10,str);
		outtextxy(10,bas_w+30,"���Ϊ���򳡣��ƿ�Ϊ�������أ��׿�Ϊ���ӡ�");
		rectangle(10,bas_w+50,10+24,bas_w+50+2*12);
		outtextxy(10+24+5,bas_w+50,"Ϊ�������ӣ�");
		rectangle(135,bas_w+50,135+24,bas_w+50+12);
		outtextxy(135+24+5,bas_w+50,"Ϊһ�����ӣ�");
		getch();
		closegraph();
		cout<<"��esc�˳�,��������������"<<endl;
		ctr=getch();
	}
	return 0;
}

