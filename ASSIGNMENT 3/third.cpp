#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int a[100], top, n;
    Stack(){ top=-1; n=100; }
    void push(int x){ if(top<n-1) a[++top]=x; }
    int pop(){ if(top==-1) return -1; return a[top--]; }
    int isEmpty(){ return top==-1; }
    int isFull(){ return top==n-1; }
    int peek(){ if(top==-1) return -1; return a[top]; }
    void display(){ for(int i=top;i>=0;i--) cout<<a[i]<<" "; cout<<endl; }
};

class CharStack{
public:
    char a[100]; int top;
    CharStack(){ top=-1; }
    void push(char x){ a[++top]=x; }
    char pop(){ return a[top--]; }
    char peek(){ return a[top]; }
    int empty(){ return top==-1; }
};

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

string infixToPostfix(string s){
    CharStack st;
    string res="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||isdigit(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='(') res+=st.pop();
            st.pop();
        }
        else{
            while(!st.empty() && prec(st.peek())>=prec(c)) res+=st.pop();
            st.push(c);
        }
    }
    while(!st.empty()) res+=st.pop();
    return res;
}

int evalPostfix(string s){
    Stack st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(isdigit(c)) st.push(c-'0');
        else{
            int b=st.pop();
            int a=st.pop();
            if(c=='+') st.push(a+b);
            else if(c=='-') st.push(a-b);
            else if(c=='*') st.push(a*b);
            else if(c=='/') st.push(a/b);
        }
    }
    return st.pop();
}

int balanced(string s){
    CharStack st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[') st.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(st.empty()) return 0;
            char x=st.pop();
            if((c==')'&&x!='(')||(c=='}'&&x!='{')||(c==']'&&x!='[')) return 0;
        }
    }
    return st.empty();
}

string reverseString(string s){
    CharStack st;
    for(char c:s) st.push(c);
    string r="";
    while(!st.empty()) r+=st.pop();
    return r;
}

int main(){
    Stack st;
    int ch,x;
    string exp;

    while(true){
        cin>>ch;
        if(ch==1){ cin>>x; st.push(x); }
        else if(ch==2){ cout<<st.pop()<<endl; }
        else if(ch==3){ cout<<st.isEmpty()<<endl; }
        else if(ch==4){ cout<<st.isFull()<<endl; }
        else if(ch==5){ st.display(); }
        else if(ch==6){ cout<<st.peek()<<endl; }
        else if(ch==7){ cin>>exp; cout<<reverseString(exp)<<endl; }
        else if(ch==8){ cin>>exp; cout<<balanced(exp)<<endl; }
        else if(ch==9){ cin>>exp; cout<<infixToPostfix(exp)<<endl; }
        else if(ch==10){ cin>>exp; cout<<evalPostfix(exp)<<endl; }
        else break;
    }
}
