// If you kopy
// and submit this kode
// I will find you
// and I will kiss you

// 1605109
// May 05 2018 1722

#include <bits/stdc++.h>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        if(length == 0) tail = list;
        length++;
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp ;
            length--;
            if(length == 0) tail = 0;
        }
        else
        {
            if(temp == tail) tail = prev;
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printList()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        if(length == 0) return insertItem(item);
        ListNode *newNode = new ListNode();
        newNode->item = item;
        tail->next = newNode;
        tail = newNode;
        ++length;
        return SUCCESS_VALUE;
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here
         if(pos > length or pos < 1) return NULL;

         ListNode *temp = new ListNode();
         temp = list;
         for(int i=2; i<=pos; ++i) temp = temp->next;
         return temp;
    }

    int deleteLast()
    {
        //write your codes here
        if(length == 0) return NULL_VALUE;
        if(length == 1) {
            delete list;
            delete tail;
            list = 0, tail = 0;
            --length;
            return SUCCESS_VALUE;
        }

        ListNode *temp, *prev;
        temp = list;
        while(temp != tail) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = 0;
        delete tail;
        tail = prev;
        length--;
        return SUCCESS_VALUE;
    }
};

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
