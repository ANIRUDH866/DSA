#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[1000], R[1000];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partitionQ(int a[], int l, int r){
    int pivot=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=partitionQ(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

void improvedSelectionSort(int a[], int n){
    int left=0, right=n-1;
    while(left<right){
        int minIndex=left, maxIndex=left;
        for(int i=left;i<=right;i++){
            if(a[i]<a[minIndex]) minIndex=i;
            if(a[i]>a[maxIndex]) maxIndex=i;
        }
        swap(a[left],a[minIndex]);
        if(maxIndex==left) maxIndex=minIndex;
        swap(a[right],a[maxIndex]);
        left++;
        right--;
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n, choice;
    int a[100];

    cin>>choice;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    if(choice==1){ selectionSort(a,n); printArray(a,n); }
    else if(choice==2){ insertionSort(a,n); printArray(a,n); }
    else if(choice==3){ bubbleSort(a,n); printArray(a,n); }
    else if(choice==4){ mergeSort(a,0,n-1); printArray(a,n); }
    else if(choice==5){ quickSort(a,0,n-1); printArray(a,n); }
    else if(choice==6){ improvedSelectionSort(a,n); printArray(a,n); }

    return 0;
}
