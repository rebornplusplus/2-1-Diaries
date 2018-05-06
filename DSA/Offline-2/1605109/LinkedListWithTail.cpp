// If you kopy
// and submit this kode
// I will find you
// and I will kiss you

// 1605109
// May 05 2018 1722

#include <bits/stdc++.h>
#include "LinkedListWithTail.h"
using namespace std;

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Get Item at.\n");
        printf("6. Delete Last. 7. Print. 8.Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch == 4) {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==5)
        {
            int pos;
            scanf("%d", &pos);
            ListNode *item = new ListNode();
            item = ll.getItemAt(pos);
            if(item == NULL) printf("No such positions found\n");
            else printf("%d\n", item->item);
        }
        else if(ch == 6) {
            ll.deleteLast();
        }
        else if(ch == 7) {
            ll.printList();
        }
        else if(ch == 8) {
            break;
        }
    }

    return 0;
}
