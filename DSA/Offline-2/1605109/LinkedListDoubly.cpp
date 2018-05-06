// If you kopy
// and submit this kode
// I will find you
// and I will kiss you

// 1605109
// May 05 2018 1723

#include <bits/stdc++.h>
#include "LinkedListDoubly.h"
using namespace std;

int main(void)
{
    LinkedListDoubly ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Print forward. 5. Print backward. 6. exit.\n");
        printf("7. Insert last.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertFirst(item);
        }
        else if(ch==2)
        {
            int item = ll.deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            ll.printListForward();
        }
        else if(ch==5)
        {
            ll.printListBackward();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch == 7) {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
    }

    return 0;
}
