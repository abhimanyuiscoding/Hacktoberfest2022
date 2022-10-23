
#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this -> data= data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}



void print(Node *head){
    if(head==NULL) 
         cout<<"null";
    while(head!=NULL){
        cout<<head-> data<<" ";
        head=head -> next;
    }
}


Node* reverseKGroup(Node* head, int k) {
       int a=1,y=0;
        
        Node* curr = head;
        Node* prev= NULL;
        Node* nxt = NULL;
        Node* pr= NULL;
        while(curr!=NULL && a<k){
            pr = curr;
            curr = curr -> next;
            a++;
            if(curr==NULL && a<=k){
                curr = head;
                y=1;
                break;
            }
        }
        
        curr = head;
         a=0;
        if(y==0){
            while(curr!=NULL && a<k){
                nxt = curr -> next;
                curr -> next= prev;
                prev= curr;
                curr = nxt;
                
                a++;
            }
            
            if(nxt!=NULL){
                head -> next = reverseKGroup(nxt,k);
            }
            
        }
        
        else{
            prev = curr;
        }
        
        return  prev;
    }


    
int main(){
    Node* node1 = new Node(63);
    

    Node* head = node1;
    
   
    
    InsertAtHead(head, 50);
    InsertAtHead(head, 40);
    InsertAtHead(head, 30);
     InsertAtHead(head, 20);
    print(head);
    cout<<endl;
   

    print(reverseKGroup(head,2));
    
    return 0;	
}
