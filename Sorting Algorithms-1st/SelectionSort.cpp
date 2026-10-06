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

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        if(min!=i){
                swap(arr[i],arr[min]);
            }
    }
}

int main()
{
    int arr[]={3,4,2,3,4,1,4};
    int n=sizeof(arr)/sizeof(arr[1]);
    selectionSort(arr,n);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}