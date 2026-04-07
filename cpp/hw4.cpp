#include <iostream>
using namespace std;
int Sum(int nums[],int length,int k) {
    int count=0;
    for (int i=0; i<length; i++) {
        int sum=0;
        for (int j=i; j<length; j++) {
            sum+=nums[j];
            if (sum==k) {
                count++;
            }
        }
    }
    
    return count;
}
int main() {
    int nums1[]={1, 1, 1};
    int k1=2;
    int length=3;
    cout<<Sum(nums1,length,k1)<<endl;
    return 0;
}
