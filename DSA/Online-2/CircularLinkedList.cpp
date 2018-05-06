#include <bits/stdc++.h>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
    ListNode * prev;
};


class CircularLinkedList
{

    ListNode * list;
    int length;

public:
    CircularLinkedList()
    {
        list = 0;  //initially set to NULL
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;

        if(list==0) //inserting the first item
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            list = newNode;
        }
        else
        {
            ListNode *tail = list->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = list;
            list->prev = newNode;
            list = newNode;
        }
        length++;
        return SUCCESS_VALUE ;
    }

    ListNode * searchItem(int item)
    {
        if(list == 0) return 0;
        if(list->item == item) return list;
        ListNode *temp = list->next;
        while (temp != list)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printListForward()
    {
        if(list == 0) {
            printf("List is empty.\n");
            return ;
        }

        printf("Length: %d\n", length);
        printf("%d -> ", list->item);
        ListNode *temp = list->next;
        while(temp!=list)
        {
            printf("%d -> ", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }

    int deleteLast()
    {
        //write your codes here
        if(list == 0) return NULL_VALUE;

        ListNode *tail = list->prev;
        int ret = tail->item;
        if(list->next == list) {
            delete list;
            list = 0;
        }
        else {
            ListNode *temp = tail->prev;
            temp->next = list;
            list->prev = temp;
            delete tail;
        }
        --length;
        return ret;
    }
};

int main() {
    CircularLinkedList L;

    printf("1. Insert First. 2. Delete Last. 3. Print. 4. Search Item. 5. Exit\n");
    int ch;
    while(true) {
        scanf("%d", &ch);
        if(ch == 1) {
            int item;
            scanf("%d", &item);
            L.insertFirst(item);
        }
        else if(ch == 2) {
            printf("Deleted: %d\n", L.deleteLast());
        }
        else if(ch == 3) {
            L.printListForward();
        }
        else if(ch == 4) {
            int item;
            scanf("%d", &item);

            ListNode *temp = L.searchItem(item);
            if(temp == 0) printf("Not Found\n");
            else printf("Found\n");
        }
        else if(ch == 5) {
            break;
        }
    }

    return 0;
}
