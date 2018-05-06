#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;  //initially set to NULL
        tail = 0;
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
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
        return SUCCESS_VALUE ;
    }

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

    void printListForward()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
        if(length == 0) return insertFirst(item);
        ListNode *newNode = new ListNode();
        newNode->item = item;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        ++length;
        return SUCCESS_VALUE;
    }

    int deleteLast()
    {
        //write your codes here
        if(length == 0) return NULL_VALUE;
        if(length == 1) {
            int ret = tail->item;
            delete list;
            delete tail;
            list = 0, tail = 0;
            --length;
            return ret;
        }

        ListNode *temp = tail->prev;
        int ret = tail->item;
        delete tail;
        tail = temp;
        tail->next = 0;
        --length;
        return ret;
    }

    void printListBackward()
    {
        //will print the list backward starting from the tail position
        ListNode * temp;
        temp = tail;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->prev;
        }
        printf("\n");
    }

};
