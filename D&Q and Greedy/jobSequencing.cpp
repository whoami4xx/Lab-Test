#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};
//sort based on profit(descending order)
bool compare(Job a,Job b){
    return a.profit>b.profit;
}

void jobSequencing(vector<Job>&jobs){
    //step-1: sort by decreasing profit
    sort(jobs.begin(),jobs.end(),compare);
    //find maximum dedline

    int maxDedline=0;
    for(auto job:jobs){
        maxDedline=max(maxDedline,job.deadline);
    }

    //slots[0] unused
    vector<char>slots(maxDedline+1,'-');
    int totalProfit=0;

    //Step-2: Try to schedule each job
    for(auto job:jobs){
        //start from deadline and go backword
        for(int j=job.deadline;j>=1;j--){
             if(slots[j]=='-'){
                slots[j]=job.id;
                totalProfit+=job.profit;
                break;
            }
        }
    }
    cout<<"Job Schedule:"<<endl;
    for(int i=1;i<=maxDedline;i++){
        cout<<"Slot"<<i<<"->"<<slots[i]<<endl;
    }
    cout<<"Maximum Profit= "<<totalProfit<<endl;
}

int main() {

    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 50},
        {'C', 2, 200},
        {'D', 1, 70},
        {'E', 3, 150}
    };

    jobSequencing(jobs);

    return 0;
}