#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

class Stack
{
    LinkedList ll;
public:
    Stack()
    {

    }
    void push(int item)
    {
        //write your codes here
        ll.insertItem(item);
    }
    int pop()
    {
        //write your codes here
        return ll.deleteFirst();
    }
};

int main(void)
{
    Stack st;

    while(1)
    {
        printf("1. Push. 2. Pop. 3. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            st.push(item);
        }
        else if(ch==2)
        {
            int item=st.pop();
            printf("%d\n",item);
        }
        else if(ch==3)
        {
            break;
        }
    }

    return 0;
}
