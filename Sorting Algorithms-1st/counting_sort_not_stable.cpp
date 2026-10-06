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

void Counting_sort(vector<int>&arr,int k){
    vector<int>temp(k+1);
    for(auto x:arr)
        temp[x]++;
    int indx=0;
    for(int i=0;i<=k;i++){
        while(temp[i]>0){
            arr[indx]=i;
            temp[i]--;
            indx++;
        }
    }   
}
int main()
{
    vector<int>arr={3,4,2,3,4,1,4};
    int mx=-1;
    for(auto a:arr){
        if(a>mx)
            mx=a;
    }
    Counting_sort(arr,mx);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
