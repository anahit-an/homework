#include <iostream>
using namespace std;
int main() {
    int intervals[][2]={{1,3},{6,9}};
    int n=2;
    int newInterval[2]={2,5};
    int result[100][2];
    int k=0;
    int i=0;
    while (i<n && intervals[i][1]<newInterval[0]){
       result[k][0]=intervals[i][0];
       result[k][1]=intervals[i][1];
       k++;
       i++;
    }
    while (i<n && intervals[i][0]<=newInterval[1]){
        if (intervals[i][0]<newInterval[0]){
            newInterval[0]=intervals[i][0];
        }
        if (intervals[i][1]>newInterval[1]){
            newInterval[1]=intervals[i][1];
        }
        i++;
    }
    
    result[k][0]=newInterval[0];
    result[k][1]=newInterval[1];
    k++;
    while (i<n){
        result[k][0]=intervals[i][0];
        result[k][1]=intervals[i][1];
        k++;
        i++;
    }
    for (int j=0;j<k;j++){
        cout<<"["<<result[j][0]<<","<<result[j][1]<<"]";
    }
    return 0;
}
