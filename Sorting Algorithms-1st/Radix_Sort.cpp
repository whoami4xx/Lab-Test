#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <climits>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;
#define ll long long
#define xx 1010

int FindMax(int arr[], int size){
    int mx=arr[0];
    for(int i=1;i<size;i++){
        mx=max(mx,arr[i]);
    }
    return mx;
}

void cntSort(int arr[],int n, int exp){
    int OutputArray[n];
    int cnt[10]={0};

    for(int i=0;i<n;i++){
        int a=(arr[i]/exp)%10;
        cnt[a]++;
    }

    //comulative sum
    for(int i=1;i<n;i++){
        cnt[i]+=cnt[i-1];
    }

    //move elements to output array with stable sorting process
    for(int i=n-1;i>=0;i--){
        int a=(arr[i]/exp)%10;
        int b=cnt[a]-1;
        OutputArray[b]=a;
        cnt[a]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=OutputArray[i];
    }

}

void RadixSort(int arr[],int n){
    int max=FindMax(arr,n);
    for(int exp=1;max/exp>0;exp*=10){
        cntSort(arr,n,exp);
    }
}


int main()
{
    int arr[]={3,4,2,3,4,1,4};
    int n=sizeof(arr)/sizeof(arr[1]);
    RadixSort(arr,n);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}