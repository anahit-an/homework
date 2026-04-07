#include <iostream>
using namespace std;
int main() {
    int nums[]={1,1,1,2,2,3};
    int n=6; 
    int maxNum = nums[0];
    int maxCount = 0;
    for (int i=0; i<n; i++) {
        int count=0;
        for (int j=0; j<n; j++) {
            if (nums[j]==nums[i]) count++;
        }
        if (count>maxCount) {
            maxCount=count;
            maxNum=nums[i];
        }
    }
    cout<<maxNum<<endl;
}
