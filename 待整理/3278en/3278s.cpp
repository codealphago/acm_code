#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <memory.h>

#define MAX 100005
using namespace std;

queue<int> q;
int step[MAX]; //�������飬��¼����
bool visit[MAX];
int n,k;
int next,head;

int bfs()
{
    q.push(n);
    step[n]=0;
    visit[n]=1;
    while(!q.empty())
    {
        head=q.front();
        q.pop();
        //����������BFS
        for(int i=0; i<3 ;i++)
        {
            if(i==0) next=head-1;
            else if(i==1) next=head+1;
            else  next=head*2;
            if(next>MAX || next<0 )  continue;  //�������жϣ���Ȼ��RE������Խ����
            if(!visit[next])
            {
              q.push(next);
              step[next]=step[head]+1;
              visit[next]=1;
            }
            if(next==k)  return step[next];
        }
    }
    return -1;
}

int main()
{
    memset(visit,0,sizeof(visit));
    scanf("%ld%ld",&n,&k);
    if(n>=k)
    {
        printf("%d",n-k);
    }
    else
    {
       printf("%d",bfs());
    }
    return 0;
}

