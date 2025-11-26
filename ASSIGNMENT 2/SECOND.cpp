#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binarySearch(int a[], int n, int key){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]==key) return m;
        else if(a[m]>key) r=m-1;
        else l=m+1;
    }
    return -1;
}

void bubbleSort(){
    int a[7]={64,34,25,12,22,11,90};
    for(int i=0;i<7;i++)
        for(int j=0;j<6-i;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    for(int i=0;i<7;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int missingLinear(int a[], int n){
    for(int i=1;i<=n;i++)
        if(a[i-1]!=i) return i;
    return -1;
}

int missingBinary(int a[], int n){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==m+1) l=m+1;
        else r=m-1;
    }
    return l+1;
}

void concatStr(){
    string a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
}

void reverseStr(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}

void deleteVowels(){
    string s,t="";
    getline(cin,s);
    getline(cin,s);
    for(char c:s){
        if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&
           c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U') t+=c;
    }
    cout<<t<<endl;
}

void sortStrings(){
    int n;
    cin>>n;
    string a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void toLowercase(){
    char c;
    cin>>c;
    if(c>='A'&&c<='Z') c=c+32;
    cout<<c<<endl;
}

int diagIndex(int i,int j,int n){
    if(i==j) return i-1;
    return -1;
}

int triDiagIndex(int i,int j,int n){
    if(i-j==1) return i-2;
    if(i==j) return n+i-2;
    if(j-i==1) return 2*n+i-2;
    return -1;
}

int lowerIndex(int i,int j,int n){
    if(i>=j) return (i*(i-1))/2 + (j-1);
    return -1;
}

int upperIndex(int i,int j,int n){
    if(i<=j) return (i-1)*n - (i*(i-1))/2 + (j-i);
    return -1;
}

int symIndex(int i,int j,int n){
    if(i>=j) return (i*(i-1))/2 + (j-1);
    else return (j*(j-1))/2 + (i-1);
}

struct Term{int r,c,v;};

void transposeSparse(Term a[], Term b[], int n, int t){
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    int k=1;
    for(int i=1;i<=a[0].c;i++)
        for(int j=1;j<=t;j++)
            if(a[j].c==i){
                b[k].r=a[j].c;
                b[k].c=a[j].r;
                b[k].v=a[j].v;
                k++;
            }
}

void addSparse(Term a[], Term b[], Term c[], int t1, int t2){
    int i=1,j=1,k=1;
    while(i<=t1 && j<=t2){
        if(a[i].r==b[j].r && a[i].c==b[j].c){
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].v=a[i].v+b[j].v;
            i++; j++; k++;
        }
        else if(a[i].r<b[j].r || (a[i].r==b[j].r && a[i].c<b[j].c)){
            c[k++]=a[i++];
        }
        else c[k++]=b[j++];
    }
    while(i<=t1) c[k++]=a[i++];
    while(j<=t2) c[k++]=b[j++];
    c[0].v=k-1;
}

void multSparse(Term a[], Term b[], Term c[], int t1, int t2){
    int k=1;
    for(int i=1;i<=t1;i++){
        for(int j=1;j<=t2;j++){
            if(a[i].c==b[j].r){
                c[k].r=a[i].r;
                c[k].c=b[j].c;
                c[k].v=a[i].v*b[j].v;
                k++;
            }
        }
    }
    c[0].v=k-1;
}

int countInversions(int a[], int n){
    int c=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) c++;
    return c;
}

int countDistinct(int a[], int n){
    int c=0;
    for(int i=0;i<n;i++){
        int f=0;
        for(int j=0;j<i;j++)
            if(a[i]==a[j]) f=1;
        if(!f) c++;
    }
    return c;
}

int main(){
    return 0;
}
