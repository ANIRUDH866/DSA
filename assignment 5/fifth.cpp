#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){ head=NULL; }

    void insertBegin(int x){
        Node* n=new Node(x);
        n->next=head;
        head=n;
    }

    void insertEnd(int x){
        Node* n=new Node(x);
        if(!head){ head=n; return; }
        Node* t=head;
        while(t->next) t=t->next;
        t->next=n;
    }

    void insertBefore(int key,int x){
        if(!head) return;
        if(head->data==key){
            insertBegin(x);
            return;
        }
        Node* t=head;
        while(t->next && t->next->data!=key) t=t->next;
        if(t->next){
            Node* n=new Node(x);
            n->next=t->next;
            t->next=n;
        }
    }

    void insertAfter(int key,int x){
        Node* t=head;
        while(t && t->data!=key) t=t->next;
        if(t){
            Node* n=new Node(x);
            n->next=t->next;
            t->next=n;
        }
    }

    void deleteBegin(){
        if(!head) return;
        Node* t=head;
        head=head->next;
        delete t;
    }

    void deleteEnd(){
        if(!head) return;
        if(!head->next){ delete head; head=NULL; return; }
        Node* t=head;
        while(t->next->next) t=t->next;
        delete t->next;
        t->next=NULL;
    }

    void deleteSpecific(int key){
        if(!head) return;
        if(head->data==key){
            deleteBegin();
            return;
        }
        Node* t=head;
        while(t->next && t->next->data!=key) t=t->next;
        if(t->next){
            Node* temp=t->next;
            t->next=t->next->next;
            delete temp;
        }
    }

    int search(int key){
        Node* t=head;
        int pos=1;
        while(t){
            if(t->data==key) return pos;
            t=t->next;
            pos++;
        }
        return -1;
    }

    void display(){
        Node* t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

void deleteOccurrences(LinkedList &L,int key){
    int count=0;
    while(L.head && L.head->data==key){
        L.deleteBegin();
        count++;
    }
    Node* t=L.head;
    while(t && t->next){
        if(t->next->data==key){
            Node* temp=t->next;
            t->next=t->next->next;
            delete temp;
            count++;
        }
        else t=t->next;
    }
    cout<<count<<endl;
    L.display();
}

int findMiddle(LinkedList &L){
    Node* slow=L.head;
    Node* fast=L.head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow) return slow->data;
    return -1;
}

void reverseList(LinkedList &L){
    Node* prev=NULL;
    Node* curr=L.head;
    Node* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    L.head=prev;
}

int main(){
    LinkedList L;
    int ch,x,key;

    while(true){
        cin>>ch;

        if(ch==1){ cin>>x; L.insertBegin(x); }
        else if(ch==2){ cin>>x; L.insertEnd(x); }
        else if(ch==3){ cin>>key>>x; L.insertBefore(key,x); }
        else if(ch==4){ cin>>key>>x; L.insertAfter(key,x); }
        else if(ch==5){ L.deleteBegin(); }
        else if(ch==6){ L.deleteEnd(); }
        else if(ch==7){ cin>>key; L.deleteSpecific(key); }
        else if(ch==8){ cin>>key; cout<<L.search(key)<<endl; }
        else if(ch==9){ L.display(); }

        else if(ch==10){ cin>>key; deleteOccurrences(L,key); }

        else if(ch==11){ cout<<findMiddle(L)<<endl; }

        else if(ch==12){ reverseList(L); L.display(); }

        else break;
    }
}
