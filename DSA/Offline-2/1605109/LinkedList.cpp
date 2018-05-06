// If you kopy
// and submit this kode
// I will find you
// and I will kiss you

// 1605109
// May 05 2018 1545

#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Insert after an element. 6. Get Item at.\n");
        printf("7. Delete First. 8. Print. 9.Exit. \n");

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
            printf("Old element: ");
            int oldie;
            scanf("%d", &oldie);
            printf("New element: ");
            int newbie;
            scanf("%d", &newbie);
            ll.insertAfter(oldie, newbie);
        }
        else if(ch==6)
        {
            int pos;
            scanf("%d", &pos);
            ListNode *item = new ListNode();
            item = ll.getItemAt(pos);
            if(item == NULL) printf("No such positions found\n");
            else printf("%d\n", item->item);
        }
        else if(ch == 7) {
            ll.deleteFirst();
        }
        else if(ch == 8) {
            ll.printList();
        }
        else if(ch == 9) {
            break;
        }
    }

    return 0;
}
