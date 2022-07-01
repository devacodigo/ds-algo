#include<iostream>
#include<vector>

using namespace std;


void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int pivot, int lo, int hi){
    cout << "pivot -> " << pivot << endl;
    int curr = lo;
    int prev = lo - 1;
    while(curr <= hi){
        if(arr[curr] <= pivot){
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
    cout << "pivot index -> " << prev << endl;
    return prev;
}


int quickselect(vector<int>& arr, int lo, int hi, int k) {
    //first thing to partition by taking last element as pivot
    int pivot = arr[hi];
    int pind=partition(arr,pivot,lo,hi);
    if(pind==k){
        return pivot;

    } 
    else if(k>pind){
        lo=pind+1;
        return quickselect(arr,lo,hi,k);
    }
    else{
        hi=pind-1;
        return quickselect(arr,lo,hi,k);
    }
    
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  int ans = quickselect(arr, 0, n - 1, k-1);
  cout << ans << endl;
  return 0;
}