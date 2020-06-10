#include <iostream>
using namespace std;

// 下标从0开始
void InsertionSort0(int a[],int n){
    int i,j,key;
    for(j=1;j<n;j++){
        key=a[j];
        i=j-1;
        while(i>=0&&a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}

// 下标从1开始
void InsertionSort1(int a[],int n){
    int i,j,key;
    for(j=2;j<=n;j++){
        key=a[j];
        i=j-1;
        while(i>0&&a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}

int main(int argc, const char * argv[]) {
    int a0[]={5,2,4,6,1,3};
    int n0=sizeof(a0)/sizeof(int);
    cout<<"n0 len:"<<n0<<endl;
    InsertionSort0(a0, n0);
    for(int i=0;i<n0;i++) cout<<a0[i]<<" ";
    cout<<endl;
    
    int a1[]={0,5,2,4,6,1,3};
    InsertionSort1(a1, 6);
    for(int i=1;i<=6;i++) cout<<a1[i]<<" ";
    return 0;
}