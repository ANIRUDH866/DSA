#include <iostream>
using namespace std;

void create(int a[], int &n){
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
}

void display(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void insertPos(int a[], int &n){
    int pos,val,i;
    cin>>pos>>val;
    for(i=n;i>=pos;i--) a[i]=a[i-1];
    a[pos-1]=val;
    n++;
}

void deletePos(int a[], int &n){
    int pos,i;
    cin>>pos;
    for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
    n--;
}

void linearSearch(int a[], int n){
    int key;
    cin>>key;
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"-1\n";
}

void removeDup(int a[], int &n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=j;k<n-1;k++) a[k]=a[k+1];
                n--;
                j--;
            }
        }
    }
}

void reverseArray(int a[], int n){
    int i=0,j=n-1,temp;
    while(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
}

void matrixMultiply(){
    int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2,i,j,k;
    cin>>r1>>c1;
    for(i=0;i<r1;i++) for(j=0;j<c1;j++) cin>>a[i][j];
    cin>>r2>>c2;
    for(i=0;i<r2;i++) for(j=0;j<c2;j++) cin>>b[i][j];
    for(i=0;i<r1;i++) for(j=0;j<c2;j++){
        c[i][j]=0;
        for(k=0;k<c1;k++) c[i][j]+=a[i][k]*b[k][j];
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++) cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

void transpose(){
    int a[10][10],r,c,i,j;
    cin>>r>>c;
    for(i=0;i<r;i++) for(j=0;j<c;j++) cin>>a[i][j];
    for(i=0;i<c;i++){
        for(j=0;j<r;j++) cout<<a[j][i]<<" ";
        cout<<endl;
    }
}

void rowColSum(){
    int a[10][10],r,c,i,j,sum;
    cin>>r>>c;
    for(i=0;i<r;i++) for(j=0;j<c;j++) cin>>a[i][j];
    for(i=0;i<r;i++){
        sum=0;
        for(j=0;j<c;j++) sum+=a[i][j];
        cout<<sum<<" ";
    }
    cout<<endl;
    for(j=0;j<c;j++){
        sum=0;
        for(i=0;i<r;i++) sum+=a[i][j];
        cout<<sum<<" ";
    }
}

int main(){
    int a[100],n=0,ch;
    while(1){
        cin>>ch;
        if(ch==1) create(a,n);
        else if(ch==2) display(a,n);
        else if(ch==3) insertPos(a,n);
        else if(ch==4) deletePos(a,n);
        else if(ch==5) linearSearch(a,n);
        else if(ch==6) break;
        else if(ch==7) removeDup(a,n);
        else if(ch==8) reverseArray(a,n);
        else if(ch==9) matrixMultiply();
        else if(ch==10) transpose();
        else if(ch==11) rowColSum();
    }
}
₹