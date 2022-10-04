#include<iostream>
using namespace std;

int i,j,choice,count=0;
struct node
{
int data;
struct node* next;
};
struct node* Head=NULL;

void enq();
void deq();
void display();
void search();

int main()
{
    while(choice!=5){
    cout<<"***************"<<endl;
    cout<<"1. ENQUEUE"<<endl<<"2. DEQUEUE"<<endl<<"3. DISPLAY"<<endl<<"4. SEARCH"<<endl<<"5. EXIT"<<endl;
    cout<<"***************"<<endl;
    cout<<"Enter your Choice: "<<endl;
    cin>>choice;
        switch(choice)
        {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                cout<<"Exiting...."<<endl;
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}


void enq()
{
    struct node *temp = new(struct node);
    int num;
    cout<<"Enter data to be inserted: "<<endl;
    cin>>num;
    temp->data = num;
    if(Head==NULL)
    {
        temp->next = NULL;
        Head = temp;
        cout<<"Node Inserted at Beginning"<<endl;
        count+=1;
    } 
    else 
    {
        temp->next = Head;
        Head = temp;
        cout<<"Node Inserted at Beginning"<<endl;
        count+=1;
    }
}


void display()
{
    struct node* p;
    p = Head;
    if(p==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    } 
    else 
    {
        cout<<"<--Printing Linked List Elements-->"<<endl;
        while(p!=NULL)
        {
            cout<<p->data<<"->";
            p = p->next;
        }
        cout<<"head"<<endl;
    }
}


void deq()
{
    int pos;
    int num;
    struct node *temp,*r, *t;
    pos=count;
    r = Head;
    if(Head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    } 
    else if(pos==1)
    {
        Head = r->next;
        delete(r);
        cout<<"Node deleted at position: "<<pos<<endl;
        count-=1;
    } 
    else 
    {
        for(i=1;i<pos;i++)
        {
            t = r;
            r = r->next;
        }
        t->next = r->next;
        delete(r);
        cout<<"Node deleted at position: "<<pos<<endl;   
        count-=1;
    }
}

void search()
{
    int toSearch, pos=1;
    bool isFound;
    struct node* p;
    p = Head;
    if(Head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    } 
    else 
    {
        cout<<"Enter the element you want to search ? "<<endl;
        cin>>toSearch;
        while(p!=NULL)
        {
            if(p->data==toSearch)
            {
                cout<<toSearch<<" is found at position "<<pos<<endl;
                isFound=true;
                return;
            } 
            else 
            {
                isFound=false;
            }
            p = p->next;
            pos+=1;
        }
        if(!isFound)
        {
            cout<<"Element not found!!"<<endl;
        }
    }
}