#include <iostream>
using namespace std;

struct CNode{
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL; }
};

struct DNode{
    char data;
    DNode* prev;
    DNode* next;
    DNode(char x){ data=x; prev=NULL; next=NULL; }
};

class CircularList{
public:
    CNode* head;
    CircularList(){ head=NULL; }

    void insertBegin(int x){
        CNode* n=new CNode(x);
        if(!head){ head=n; n->next=head; return; }
        CNode* t=head;
        while(t->next!=head) t=t->next;
        n->next=head;
        t->next=n;
        head=n;
    }

    void insertEnd(int x){
        CNode* n=new CNode(x);
        if(!head){ head=n; n->next=head; return; }
        CNode* t=head;
        while(t->next!=head) t=t->next;
        t->next=n;
        n->next=head;
    }

    void insertAfter(int key,int x){
        if(!head) return;
        CNode* t=head;
        do{
            if(t->data==key){
                CNode* n=new CNode(x);
                n->next=t->next;
                t->next=n;
                return;
            }
            t=t->next;
        }while(t!=head);
    }

    void insertBefore(int key,int x){
        if(!head) return;
        if(head->data==key){
            insertBegin(x);
            return;
        }
        CNode* t=head;
        do{
            if(t->next->data==key){
                CNode* n=new CNode(x);
                n->next=t->next;
                t->next=n;
                return;
            }
            t=t->next;
        }while(t!=head);
    }

    void deleteNode(int key){
        if(!head) return;
        if(head->data==key){
            if(head->next==head){ delete head; head=NULL; return; }
            CNode* t=head;
            while(t->next!=head) t=t->next;
            CNode* temp=head;
            head=head->next;
            t->next=head;
            delete temp;
            return;
        }
        CNode* t=head;
        do{
            if(t->next->data==key){
                CNode* temp=t->next;
                t->next=t->next->next;
                delete temp;
                return;
            }
            t=t->next;
        }while(t!=head);
    }

    int search(int key){
        if(!head) return -1;
        int pos=1;
        CNode* t=head;
        do{
            if(t->data==key) return pos;
            t=t->next; pos++;
        }while(t!=head);
        return -1;
    }

    void display(){
        if(!head) return;
        CNode* t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<head->data;
        cout<<endl;
    }

    int size(){
        if(!head) return 0;
        int c=0;
        CNode* t=head;
        do{
            c++; t=t->next;
        }while(t!=head);
        return c;
    }

    int isCircular(){
        if(!head) return 0;
        CNode* t=head->next;
        while(t && t!=head) t=t->next;
        return t==head;
    }
};

class DoublyList{
public:
    DNode* head;
    DNode* tail;
    DoublyList(){ head=NULL; tail=NULL; }

    void insertBegin(char x){
        DNode* n=new DNode(x);
        if(!head){ head=tail=n; return; }
        n->next=head;
        head->prev=n;
        head=n;
    }

    void insertEnd(char x){
        DNode* n=new DNode(x);
        if(!tail){ head=tail=n; return; }
        tail->next=n;
        n->prev=tail;
        tail=n;
    }

    void insertAfter(char key,char x){
        DNode* t=head;
        while(t){
            if(t->data==key){
                DNode* n=new DNode(x);
                n->next=t->next;
                n->prev=t;
                if(t->next) t->next->prev=n;
                t->next=n;
                if(t==tail) tail=n;
                return;
            }
            t=t->next;
        }
    }

    void insertBefore(char key,char x){
        if(!head) return;
        if(head->data==key){ insertBegin(x); return; }
        DNode* t=head;
        while(t){
            if(t->data==key){
                DNode* n=new DNode(x);
                n->next=t;
                n->prev=t->prev;
                t->prev->next=n;
                t->prev=n;
                return;
            }
            t=t->next;
        }
    }

    void deleteNode(char key){
        if(!head) return;
        if(head->data==key){
            DNode* t=head;
            head=head->next;
            if(head) head->prev=NULL;
            else tail=NULL;
            delete t;
            return;
        }
        DNode* t=head;
        while(t){
            if(t->data==key){
                if(t->next) t->next->prev=t->prev;
                else tail=t->prev;
                t->prev->next=t->next;
                delete t;
                return;
            }
            t=t->next;
        }
    }

    int search(char key){
        int pos=1;
        DNode* t=head;
        while(t){
            if(t->data==key) return pos;
            t=t->next; pos++;
        }
        return -1;
    }

    void display(){
        DNode* t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    int size(){
        int c=0;
        DNode* t=head;
        while(t){ c++; t=t->next; }
        return c;
    }

    int isPalindrome(){
        DNode* l=head;
        DNode* r=tail;
        while(l && r && l!=r && r->next!=l){
            if(l->data!=r->data) return 0;
            l=l->next;
            r=r->prev;
        }
        return 1;
    }
};

int main(){
    CircularList C;
    DoublyList D;
    int ch,x,key;
    char c,k;

    while(true){
        cin>>ch;

        if(ch==1){ cin>>x; C.insertBegin(x); }
        else if(ch==2){ cin>>x; C.insertEnd(x); }
        else if(ch==3){ cin>>key>>x; C.insertBefore(key,x); }
        else if(ch==4){ cin>>key>>x; C.insertAfter(key,x); }
        else if(ch==5){ cin>>key; C.deleteNode(key); }
        else if(ch==6){ cin>>key; cout<<C.search(key)<<endl; }
        else if(ch==7){ C.display(); }
        else if(ch==8){ cout<<C.size()<<endl; }
        else if(ch==9){ cout<<C.isCircular()<<endl; }

        else if(ch==10){ cin>>c; D.insertBegin(c); }
        else if(ch==11){ cin>>c; D.insertEnd(c); }
        else if(ch==12){ cin>>k>>c; D.insertBefore(k,c); }
        else if(ch==13){ cin>>k>>c; D.insertAfter(k,c); }
        else if(ch==14){ cin>>c; D.deleteNode(c); }
        else if(ch==15){ cin>>c; cout<<D.search(c)<<endl; }
        else if(ch==16){ D.display(); }
        else if(ch==17){ cout<<D.size()<<endl; }
        else if(ch==18){ cout<<D.isPalindrome()<<endl; }

        else break;
    }
}
