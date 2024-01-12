#include<iostream>
#include<vector>
using namespace std;




void merge(vector<int>&arr,int left,int right,int mid){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int>left_arr(n1);
    vector<int>right_arr(n2);
    

    for(int i=0;i<n1;i++){
        left_arr[i]=arr[left+i];
    }
     for(int i=0;i<n1;i++){
        right_arr[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
    if(left_arr[i]<arr[left+1]){
        arr[k]=left_arr[i];
        i++;
    }
    else{
        arr[k]=right_arr[j];
        j++;
    }
    k++;
    }
     while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }


}


void merge_sort(vector<int>&arr,int left,int right){
    int mid=left+(right-left)/2;
    if(left<right){
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }



}

int main(){
    int n;
    cout<<"enter array size "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the value for array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"original arry"<<endl;

     merge_sort(arr,0,n-1);
     cout << "Sorted array:";
    for (int i = 0; i < n; i++){
         cout << " " << arr[i];

    }
       

    return 0;

}