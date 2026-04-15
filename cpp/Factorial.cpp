#include <iostream>
using namespace std;
int check(long long n, long long i, long long fact) {
    if (fact==n) {
        return i;
    }
    if (fact>n) {
        return -1;
    }
    i=i+1;
    fact=fact*i;
    return check(n,i,fact);
}
int isFactorial(long long n) {
    return check(n,1,1);
}
int main() {
    cout<<isFactorial(120)<<endl;
    return 0;
}
