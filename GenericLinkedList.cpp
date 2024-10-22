#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    SinglyLL
//  Description        :    This class represents Singly Linear LinkedList.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    SinglyLL
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class SinglyLL
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Singly Linear linkedlist
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Singly Linear linkedlist
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Singly Linear linkedlist at First
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
   struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Singly Linear linkedlist At last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;   

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No, int iPos
//                              No Holds the entry which is to be added and iPos holds the position 
//  Description            :    This function add nodes to Singly Linear linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Singly Linear linkedlist At First
//  Return                 :    void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Singly Linear linkedlist At Last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::DeleteLast()
{
   struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    int iPos
//                              it holds the position 
//  Description            :    This function delete nodes from Singly Linear linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    SinglyCL
//  Description        :    This class represents Singly Circular LinkedList.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSC  
{
    T data;
    struct nodeSC  *next;
};

template<class T>
class SinglyCL
{
    private:
        struct nodeSC<T>  * First;
        struct nodeSC<T>  * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    SinglyCL
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class SinglyCL
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Singly Circular linkedlist
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T> * temp1 = First;
    struct nodeSC<T>  * temp2 = Last;

    if ((temp1 == NULL) && (temp2 == NULL))
    {
        cout<<"LinkedList is empty\n";
        return;
    }
    
    do
    {
        cout<<"| "<<temp1->data<<"|-> ";
        temp1 = temp1->next; 
    } while (temp1 != temp2 -> next);

    cout<<"\n";  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Singly Circular linkedlist
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Singly Circular linkedlist at First
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::InsertFirst(int No)
{
     struct nodeSC<T>  * newn = NULL;

    newn = new nodeSC<T>;   
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Singly Circular linkedlist At last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::InsertLast(int No)
{
     struct nodeSC<T>  * newn = NULL;

    newn = new nodeSC<T>;   
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No, int iPos
//                              No Holds the entry which is to be added and iPos holds the position 
//  Description            :    This function add nodes to Singly Circular linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::InsertAtPos(int No, int iPos)
{
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp;
    int i = 0;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Singly Circular linkedlist At First
//  Return                 :    void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty\n";
        return;
    }
    else if (First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete(Last -> next);
        Last -> next = First;
    }  
    iCount--; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Singly Circular linkedlist At Last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T> * temp  = First;

    if ((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty\n";
        return;
    }
    else if (First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
       while (temp -> next != Last)
        {
            temp = temp -> next;
        }
        free(Last);
        Last =temp;
        Last -> next = First;
    }  
    iCount--; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    int iPos
//                              it holds the position 
//  Description            :    This function delete nodes from Singly Circular linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSC<T> * temp1;
    struct nodeSC<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    DoublyLL
//  Description        :    This class represents Doubly Linear LinkedList.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDL
{
    T data;
    struct nodeDL<T> *next;
    struct nodeDL<T>  *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDL<T>  * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DoublyLL
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class DoublyLL
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLL<T> ::DoublyLL()
    {
            First = NULL;
            iCount = 0;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Doubly Linear linkedlist
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::Display()
{
    struct nodeDL<T>  * temp = First;

    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Doubly Linear linkedlist
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> ::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Doubly Linear linkedlist at First
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::InsertFirst(T No)
{
    struct nodeDL<T>  * newn = NULL;

    newn = new nodeDL<T> ;   

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First-> prev = newn;

        First = newn;
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Doubly Linear linkedlist At last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::InsertLast(T No)
{
    struct nodeDL<T>  * newn = NULL;
    struct nodeDL<T>  * temp = First;

    newn = new nodeDL<T> ;    

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp; 
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No, int iPos
//                              No Holds the entry which is to be added and iPos holds the position 
//  Description            :    This function add nodes to Doubly Linear linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T>  * newn = NULL;
    int i = 0;
    struct nodeDL<T>  * temp ;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    else if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeDL<T> ;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Doubly Linear linkedlist At First
//  Return                 :    void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::DeleteFirst()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete First -> prev;
        First-> prev = NULL;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Doubly Linear linkedlist At Last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::DeleteLast()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    int iPos
//                              it holds the position 
//  Description            :    This function delete nodes from Doubly Linear linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> ::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL<T> * temp;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        temp -> next= temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
        iCount--;
    }    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    DoublyCL
//  Description        :    This class represents Doubly Circular LinkedList.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DoublyCL
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class DoublyCL
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Doubly Circular linkedlist
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data<<" |<=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Doubly Circular linkedlist
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Doubly Circular linkedlist at First
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First==NULL)&&(Last==NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First-> prev = newn;
        First = newn;
    }
    Last ->next = First;
    First -> prev = Last;
    
    iCount++;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function add nodes to Doubly Circular linkedlist At last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;    

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
    }
    else
    {   
        Last -> next = newn;
        newn -> prev = Last; 
        Last = newn;
    }
    Last ->next = First;
    First -> prev = Last;

    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    InsertAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No, int iPos
//                              No Holds the entry which is to be added and iPos holds the position 
//  Description            :    This function add nodes to Doubly Circular linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertAtPos(T No,int iPOs)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;
    int i = 0;

    if(iPOs < 1 || iPOs > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (iPOs == 1)
    {
        InsertFirst(No);
    }
    else if (iPOs == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for ( i = 1; i < iPOs-1; i++)
        {
            temp = temp ->next;
        }
        
        newn -> next = temp ->next;
        temp->next ->prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
        iCount++;
    }   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteFirst
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Doubly Circular linkedlist At First
//  Return                 :    void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((First == NULL)&&(Last == NULL))
    {
       return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last ->next;
        First -> prev = Last;
        Last ->next = First;
    }
    iCount--;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteLast
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function delete node from Doubly Circular linkedlist At Last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteLast()
{
    if ((First == NULL)&&(Last == NULL))
    {
       return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last ->prev;
        delete First->prev;

        First -> prev = Last;
        Last ->next = First;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeleteAtPos
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    int iPos
//                              it holds the position 
//  Description            :    This function delete nodes from Doubly Circular linkedlist At given position
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteAtPos(int iPOs)
{
    struct nodeDC<T> * temp = NULL;
    int i = 0;

    if(iPOs < 1 || iPOs > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (iPOs == 1)
    {
        DeleteFirst();
    }
    else if (iPOs == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for ( i = 1; i < iPOs-1; i++)
        {
            temp = temp ->next;
        }
        
        temp-> next = temp ->next ->next;
        delete temp->next ->prev ;
        temp->next->prev= temp;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    Stack
//  Description        :    This class represents Stack. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeS
{
    T data;
    struct nodeS<T> *next;
};

template<class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;
    
    public:
        Stack();
        void Display();
        int Count();
        void Push(T No); 
        int Pop();       
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Stack
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class Stack
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
Stack<T>:: Stack()
{
    First =NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Stack
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are: \n";
    struct nodeS<T> * temp = First;

    while (temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp ->next;
    }
    cout<<"\n";   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Stack
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Stack<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Push
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function Push(insert) the element to stack at First
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Push(T No)
{
   struct nodeS<T> * newn = NULL;

   newn = new nodeS<T>;
   newn->data = No;
   newn->next = NULL;

   if (First == NULL)
   {
        First =  newn;
   }
   else
   {
    newn ->next = First;
    First = newn;
   }
   iCount++;    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Pop
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function Pop(remove) the element from Stack At First
//  Return                 :    int
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int  Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeS<T> * temp = NULL;

    if (First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;
        iValue = First->data;
        First = First ->next;
        delete temp;
        iCount--;
    }   
   return iValue; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name         :    Queue
//  Description        :    This class represents Queue.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template<class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;
    
    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No); 
        int DeQueue();    
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Queue
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This is a constructor of class Queue
//  Return                 :    NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
Queue<T>:: Queue()
{
    First =NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Display
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function display Queue
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T>::Display()
{
    cout<<"Elements of stack are: \n";
    struct nodeQ<T> * temp = First;

    while (temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp ->next;
    }
    cout<<"\n";  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    Count
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function counts nodes in Queue
//  Return                 :    int
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Queue<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    EnQueue
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    T No
//                              Holds the entry which is to be added
//  Description            :    This function Insert the element to Queue at Last
//  Return                 :    void
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T>::EnQueue(T No)
{
   struct nodeQ<T> * newn = NULL;
   struct nodeQ<T> * temp = NULL;

   newn = new nodeQ<T>;
   newn->data = No;
   newn->next = NULL;

   if (First == NULL)
   {
        First =  newn;
   }
   else
   {
        temp = First;
        while (temp -> next != NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;   
   }
   iCount++;  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name          :    DeQueue
//  Function Date          :    06/07/2024
//  Function Author        :    Dnyaneshwari Jadhav
//  Parameters             :    NONE
//  Description            :    This function Remove the element from Queue At First
//  Return                 :    int
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if (First == NULL)
    {
        cout<<"Unable to remove the element cause is empty\n";
        return -1;
    }
    else
    {
        temp = First;
        iValue = First->data;
        First = First ->next;
        delete temp;
        iCount--;
    }
   return iValue; 
}

int main()
{
    SinglyLL<int> *iobj = new SinglyLL<int>();
    SinglyCL<float> *fobj = new SinglyCL<float>();
    DoublyLL<char> *cobj = new DoublyLL<char>();
    DoublyCL<double> *dobj = new DoublyCL<double>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    return 0;
}