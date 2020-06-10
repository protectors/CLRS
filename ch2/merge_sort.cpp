#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1000;
const int inf=999999;

int a[maxn];
int L[maxn],R[maxn];


void Merge(int a[],int l,int m,int r){
    int i,j,n1=m-l+1,n2=r-m;
    for(i=1;i<=n1;i++) L[i]=a[l+i-1];
    for(j=1;j<=n2;j++) R[j]=a[m+j];
    L[n1+1]=inf;  R[n2+1]=inf;
    i=j=1;
    for(int k=l;k<=r;k++){
        if(L[i]<=R[j]){ a[k]=L[i]; i++; }
        else{ a[k]=R[j]; j++; }
    }
}


void MergeSort(int a[],int l,int r){
    int m;
    if(l<r){
        m=(l+r)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
}


int main(int argc, const char * argv[]) {

	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	memset(a,0,sizeof(a));

    int a[]={5,2,4,6,1,3};
    int n=sizeof(a)/sizeof(int);
    cout<<"n0 len:"<<n<<endl;
    MergeSort(a,0,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    // int a1[]={0,5,2,4,6,1,3};
    // InsertionSort1(a1, 6);
    // for(int i=1;i<=6;i++) cout<<a1[i]<<" ";
    return 0;
}