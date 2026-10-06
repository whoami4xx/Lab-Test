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

void Counting_sort(vector<int>&arr,int n){
    vector<int>S(n+1);
    for(auto x:arr)
        S[x]++;
    //Comulative Sum
    for(int i=1;i<=n;i++){
        S[i]=S[i]+S[i-1];
    }
    vector<int>Output(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int a=arr[i];
        int b=S[a]-1;
        Output[b]=a;
        S[a]--;
    }

    for(int i=0;i<arr.size();i++)
        arr[i]=Output[i];

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