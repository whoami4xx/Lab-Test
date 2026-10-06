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

void Merge(vector<int>&v,int l, int mid, int r){
    int i=l;
    int j=mid+1;
    vector<int>b;
    while(i<=mid and j<=r){
        if(v[i]>v[j]){
            b.push_back(v[j]);
            j++;
        }
        else{
            b.push_back(v[i]);
            i++;
        }
    }

    while(i<=mid){
        b.push_back(v[i]);
        i++;
    }
    while(j<=r){
        b.push_back(v[j]);
        j++;
    }

    for(int i=l;i<=r;i++){
        v[i]=b[i-l];
    }

}

void MergeSort(vector<int>&v,int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        MergeSort(v,l,mid);
        MergeSort(v,mid+1,h);
        Merge(v,l,mid,h);
    }
}

int main()
{
    vector<int>arr={3,4,2,3,4,1,4};
    MergeSort(arr,0,6);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}