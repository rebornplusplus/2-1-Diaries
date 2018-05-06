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
            int ret = tail->item;
            delete list;
            delete tail;
            list = 0, tail = 0;
            --length;
            return ret;
        }

        int ret = tail->item;
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
        return ret;
    }
};
