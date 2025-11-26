#include <iostream>
#include <queue>
#include <string>
using namespace std;

class SimpleQueue {
public:
    int a[100], front, rear, n;
    SimpleQueue(){ front=0; rear=-1; n=100; }
    void enqueue(int x){ if(rear<n-1) a[++rear]=x; }
    int dequeue(){ if(front>rear) return -1; return a[front++]; }
    int isEmpty(){ return front>rear; }
    int isFull(){ return rear==n-1; }
    int peek(){ if(front>rear) return -1; return a[front]; }
    void display(){ for(int i=front;i<=rear;i++) cout<<a[i]<<" "; cout<<endl; }
};

class CircularQueue {
public:
    int a[100], front, rear, n;
    CircularQueue(){ front=-1; rear=-1; n=100; }
    void enqueue(int x){
        if((rear+1)%n==front) return;
        if(front==-1) front=0;
        rear=(rear+1)%n;
        a[rear]=x;
    }
    int dequeue(){
        if(front==-1) return -1;
        int x=a[front];
        if(front==rear) front=rear=-1;
        else front=(front+1)%n;
        return x;
    }
    int isEmpty(){ return front==-1; }
    int isFull(){ return (rear+1)%n==front; }
    int peek(){ if(front==-1) return -1; return a[front]; }
    void display(){
        if(front==-1){ cout<<endl; return; }
        int i=front;
        while(true){
            cout<<a[i]<<" ";
            if(i==rear) break;
            i=(i+1)%n;
        }
        cout<<endl;
    }
};

void interleaveQueue(){
    queue<int> q;
    int x;
    for(int i=0;i<6;i++){ cin>>x; q.push(x); }
    int half=q.size()/2;
    queue<int> q1;
    for(int i=0;i<half;i++){ q1.push(q.front()); q.pop(); }
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
        cout<<q.front()<<" ";
        q.pop();
    }
}

void firstNonRepeating(){
    queue<char> q;
    int freq[256]={0};
    string s;
    cin>>s;
    for(char c:s){
        freq[c]++;
        q.push(c);
        while(!q.empty() && freq[q.front()]>1) q.pop();
        if(q.empty()) cout<<-1<<" ";
        else cout<<q.front()<<" ";
    }
    cout<<endl;
}

class StackTwoQueues {
public:
    queue<int> q1,q2;
    void push(int x){
        q2.push(x);
        while(!q1.empty()){ q2.push(q1.front()); q1.pop(); }
        swap(q1,q2);
    }
    int pop(){
        if(q1.empty()) return -1;
        int x=q1.front();
        q1.pop();
        return x;
    }
};

class StackOneQueue {
public:
    queue<int> q;
    void push(int x){
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        if(q.empty()) return -1;
        int x=q.front();
        q.pop();
        return x;
    }
};

int main(){
    SimpleQueue sq;
    CircularQueue cq;
    StackTwoQueues s2;
    StackOneQueue s1;

    int ch,x;

    while(true){
        cin>>ch;
        if(ch==1){ cin>>x; sq.enqueue(x); }
        else if(ch==2){ cout<<sq.dequeue()<<endl; }
        else if(ch==3){ cout<<sq.isEmpty()<<endl; }
        else if(ch==4){ cout<<sq.isFull()<<endl; }
        else if(ch==5){ sq.display(); }
        else if(ch==6){ cout<<sq.peek()<<endl; }

        else if(ch==7){ cin>>x; cq.enqueue(x); }
        else if(ch==8){ cout<<cq.dequeue()<<endl; }
        else if(ch==9){ cout<<cq.isEmpty()<<endl; }
        else if(ch==10){ cout<<cq.isFull()<<endl; }
        else if(ch==11){ cq.display(); }
        else if(ch==12){ cout<<cq.peek()<<endl; }

        else if(ch==13){ interleaveQueue(); }
        else if(ch==14){ firstNonRepeating(); }

        else if(ch==15){ cin>>x; s2.push(x); }
        else if(ch==16){ cout<<s2.pop()<<endl; }

        else if(ch==17){ cin>>x; s1.push(x); }
        else if(ch==18){ cout<<s1.pop()<<endl; }

        else break;
    }
}
