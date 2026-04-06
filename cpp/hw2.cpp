#include <iostream>
using namespace std;
bool Count(int arr[], int n) {
    bool hash[100]={};
    for (int i=0; i<n; i++) {
        int index=arr[i]; 
        if (hash[index]) {
            return true; 
        }
        hash[index]=true;
    }
    return false;
}
int main() {
    int arr1[]={1,2,3,3};
    int arr2[]={1,2,3,2};
    cout<<Count(arr1,4)<<endl; 
    cout<<Count(arr2,4)<<endl; 
    return 0;
}
