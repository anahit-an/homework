#include <iostream>
#include <cmath>
using namespace std;
int Result (string arr[],int size,int x){
    int result=x;
    int a=1;
    for (int i=size-1;i>=0;i--){
        int old=result;
        if (arr[i]=="square") {
            a*=2*old;
            result=old*old;
        }
        if (arr[i]=="sin") {
            a*=cos(old);
            result=sin(old);
        }
        if (arr[i]=="exp") {
            a*=exp(old);
            result=exp(old);
        }
        if (arr[i]=="log"){
            a*=1/old;
            result=log(old);
        }
    }
    return a;
}
int main() {
    string arr[]={"sin","square"};
    int size=2; 
    int x=1;
    cout<<Result(arr,size,x)<<endl;
    return 0;
}
