#include<iostream>
using namespace std;

struct node{
    int id;
    int profit;
    int deadline;
};

int parti(struct node* arr, int low, int high){
    int i = low-1;
    int pivot = arr[high].profit;
    for(int j = low; j < high; ++j){
        if(arr[j].profit > pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSort(struct node* arr, int low, int high){
    if(low < high){
        int p = parti(arr, low, high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

void solve(){
    /*
        Problem Statement:
        Given a set of n jobs where each job i has a deadline and profit associated to it.
        Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
        We earn the profit if and only if the job is completed by its deadline. 
        The task is to find the maximum profit and the number of jobs done.
    */
    int n;
    cin >> n;
    struct node* arr = (struct node*)malloc(n*sizeof(struct node));
    for(int i = 0; i < n; ++i){
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    //Sorting array in profitwise descending order
    quickSort(arr,0,n-1);
    int sold = 0;
    int net_profit = 0;
    int *result = new int[n];
    bool *slot[n] = (bool*)calloc(n,sizeof(bool));
    for(int i = 0; i < n; ++i){
        for(int j = min(n,arr[i].dead)-1; j >= 0; j--){
            if(!slot[j]){
                slot[j] = true;
                sold++;
                net_profit+=arr[i].profit;
            }
        }
    }
    // //Including element with maximum profit.
    // for(int i = 1; i < n; ++i){
    //     //LOGIC BEHIND THIS
    //     /*
    //         Job-Sequence algorithm according to GFG
    //         1) Sort all jobs in decreasing order of profit.
    //         2) Initialize the result sequence as first job in sorted jobs.
    //         3) Do following for remaining n-1 jobs
    //         .......a) If the current job can fit in the current result sequence 
    //                 without missing the deadline, add current job to the result.
    //                 Else ignore the current job.
    //     */
    //     if(arr[i].deadline > sold || current_deadline-sold > 0){
    //         net_profit+=arr[i].profit;
    //         sold++;
    //         current_deadline = max(arr[i].deadline,current_deadline);
    //     }
    // }
    cout << sold << " " << net_profit << endl;
}

int main(){
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}