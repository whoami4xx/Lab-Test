#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct activity{
    int start;
    int end;
};

bool compare(activity a, activity b){
    return a.end<b.end;
}

void activitySelection(vector<activity>&activities){
    //sort based on finish time
    sort(activities.begin(),activities.end(),compare);
    cout<<"selected activities: \n";

    //select first activity
    int lastFinish=activities[0].end;
    cout<<"("
        <<activities[0].start<<","
        <<activities[0].end<<")\n";
    
    //check remaining activities

    for(int i=1;i<activities.size();i++){
        if(activities[i].start>=lastFinish){
            cout<<"("
                <<activities[i].start<<","
                <<activities[i].end<<")"<<endl;
            lastFinish=activities[i].end;
        }
    }

}

int main(){
    vector<activity>activities={
        {1, 3},
        {2, 5},
        {3, 4},
        {5, 7},
        {6, 8},
        {8, 9}
    };

    activitySelection(activities);
    return 0;
}