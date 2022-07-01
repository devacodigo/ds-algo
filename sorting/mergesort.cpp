#include <iostream>

#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> mergeSort(vector<int> &arr,int l,int r)
{   
    if(l==r){//base case is must beta
        vector<int> base;
        base.push_back(arr[l]);
        return base;
    }
    int mid=(l+r)/2;
    vector<int> X=mergeSort(arr,l,mid);
    vector<int> Y=mergeSort(arr,mid+1,r);
    vector<int> ans=mergeTwoSortedArrays(X,Y);
    return ans;

    
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);5

    input(A);

    vector<int> ans = mergeSort(A,0,A.size()-1);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}
