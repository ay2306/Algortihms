#include<bits/stdc++.h>
using namespace std;

struct node{
    int first;
    int second;
    int third;
};

int parti(struct node *arr, int low, int high){
    int pivot = arr[high].second;
    int i = low-1;
    for(int j = low; j < high; ++j){
        if(arr[j].second <= pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(struct node *arr, int low, int high){
    if(low < high){
        int p = parti(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

void solve(){
    int n;
    cin >> n;
    struct node *arr = new struct node[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].third = i+1;
    }
    for(int i = 0; i < n; ++i){
        cin >> arr[i].second;
    }
    quicksort(arr,0,n-1);
    struct node last_select = arr[0];
    // for(int i = 0; i < n; ++i)printf("(%d, %d, %d)\n",arr[i].first,arr[i].second,arr[i].third);
    int ans = 1;
    cout << arr[0].third << " ";
    for(int i = 1; i < n; ++i){
        if(arr[i].first >= last_select.second){
            cout << arr[i].third << " ";
            last_select = arr[i];
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}