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

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l + 1;
    int j = h;
    while(i <= j){
        while(i <= h && arr[i] <= pivot){
            i++;
        }
        while(j > l && arr[j] >= pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void QuickSort(int arr[],int l, int h){
    if(l<h){
        int j=partition(arr,l,h);
        QuickSort(arr,l,j-1);
        QuickSort(arr,j+1,h);
    }
}

int main()
{
    int arr[]={3,4,2,3,4,1,4,999};
    int n=sizeof(arr)/sizeof(arr[1]);
    QuickSort(arr,0,7);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}