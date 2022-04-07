#include <iostream>
using namespace std;
typedef struct iqueue{
    int data[1001];
    int head;
    int tail;
}myqueue;

typedef struct istack{
    int data[10];
    int top;
}mystack;
int book[10];
int main()
{
    myqueue q1,q2;
    mystack s;
    int i, t;
    q1.head=1;
    q1.tail=1;
    q2.head=1;
    q2.tail=1;
    s.top=0;

    for(i=1;i<=6;i++)
    {
        cin>>q1.data[q1.tail];
        q1.tail++;
    }
    for(i=1;i<=6;i++)
    {
        cin>>q2.data[q2.tail];
        q2.tail++;
    }
    while(q1.head<q1.tail && q2.head<q2.tail)
    {
        t=q1.data[q1.head];
        if(book[t]==0)
        {
            q1.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }
        else
        {
            q1.head++;
            q1.data[q1.tail]=t;
            q1.tail++;
            while(s.data[s.top]!=t])
            {
                book[s.data[s.top]]=0;
                q1.data[q1.tail]=s.data[s.top];
                q1.tail++;
                s.top--;
            }
            book[s.data[s.top]]=0;
            q1.data[q1.tail]=s.data[s.top];
            q1.tail++;
            s.top--;

        }
        if(q1.head==q1.tail)
            break;
        
        t= q2.data[q2.head];
        if(book[t]==0)
        {
            q2.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail]=t;
            q2.tail++;
            while(s.data[s.top]!=t])
            {
                book[s.data[s.top]]=0;
                q2.data[q2.tail]=s.data[s.top];
                q2.tail++;
                s.top--;
            }
            book[s.data[s.top]]=0;
            q2.data[q2.tail]=s.data[s.top];
            q2.tail++;
            s.top--;

        }
        if(q2.head==q2.tail)
            break;
    }
}