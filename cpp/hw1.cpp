#include <iostream>
using namespace std;
bool Count(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i]==arr[j]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3, 1};
    cout<<Count(arr1,3)<<endl; 
    cout<<Count(arr2,4)<<endl; 
    return 0;
}
