#include <bits/stdc++.h>
#include "LinkedListWithTail.h"
using namespace std;

class Queue
{
    LinkedListWithTail ll;
public:
    Queue()
    {

    }

    void enqueue(int item)
    {
        //write your codes here
        ll.insertItem(item);
    }

    int dequeue()
    {
       //write your codes here
       return ll.deleteLast();
    }
};

int main(void)
{
    Queue qu;

    while(1)
    {
        printf("1. Enque. 2. Deque. 3. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            qu.enqueue(item);
        }
        else if(ch==2)
        {
            int item=qu.dequeue();
            printf("%d\n",item);
        }
        else if(ch==3)
        {
            break;
        }
    }

    return 0;
}

