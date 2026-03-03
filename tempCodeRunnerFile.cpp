#include<iostream>
#include<vector>
using namespace std;
void swap(int& i , int& j ){
    int temp = i;
    i = j ; 
    j = temp;
    return;
}
int piv(vector<int> & arr , int low , int high){
    int i = low , j = high;
    while (i <= j){
        if(arr[i] > pivit && arr[j] < pivit) 
            swap(arr[i++] , arr [j--]);
        if(!(arr[i] > pivit))
            i++;
        if(!(arr[j] < pivit)) 
            j--;
    }
    return ++j;
}
void quick_sorting (vector<int> &arr , int low , int high){
    if(low >= high )
        return;
    int pivit_location = piv(arr, low , high);
    sort(arr, low , high , pivit , pivit_location);
    quick_sorting(arr , low , pivit_location-1);
    quick_sorting(arr , pivit_location+1 , high);
}
void print (vector<int> arr){
    while(!arr.empty()){
        cout << arr.back() << " ";
        arr.pop_back();
    }
}
int main(){
    vector<int> v = {1,35,6,4,311,63,45,3,452};
    quick_sorting(v,0, v.size()-1);
    print (v);
}