#include<iostream>
#include<vector>

using namespace std;


void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping index " << i << " and index " << j << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void sort01(vector<int>& arr) {
    int i=0;
    int j=0;
    while(i<.arr.size()){
      if(arr[i]==1){
        i++;

      }
      else if(arr[i]==0){
        swap(arr,i,j);
        i++;
        j++;
      }
    }
    
}


void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort01(arr);
  Display(arr);
  return 0;
}