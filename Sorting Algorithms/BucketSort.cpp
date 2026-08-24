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

void insertionSort(vector<float>&v){
    sort(v.begin(),v.end());
}

void BucketSort(vector<float>&v,int n){
    vector<vector<float>>buckets(n);

    //push values into buckets
    for(int i=0;i<n;i++){
        int bucketIndex=n*v[i];
        buckets[bucketIndex].push_back(v[i]);
    }
    //sort individual bucket using insertion sort
    for(int i=0;i<n;i++){
        insertionSort(buckets[i]);
    }
    //copy element to the array form bucket
    int indx=0;
    for(int i=0;i<n;i++){
        for(auto x:buckets[i]){
            v[indx]=x;
            indx++;
        }
    }

}


int main()
{
    vector<float>v={0.23,0.43,0.23,0.56,0.55};
    int n=v.size();
    BucketSort(v,n);
    
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}