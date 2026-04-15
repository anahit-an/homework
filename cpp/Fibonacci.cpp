#include <iostream>
using namespace std;
int findIndex(string a, string b, int index, string n) {
    if (a==n) {
        return index - 1;
    }
    if (b==n) {
        return index;
    }
    string next="";
    int carry=0;
    int i=a.size() - 1;
    int j=b.size() - 1;
    while (i>=0 || j>=0 || carry>0) {
        int sum=carry;
        if (i>=0) {
            sum=sum+(a[i]-'0');
        }
        if (j>=0) {
            sum=sum+(b[j]-'0');
        }
        next=char((sum%10)+'0')+next;
        carry=sum/10;
        i--;
        j--;
    }
    if (next.size()>n.size()) {
        return -1;
    }
    if (next.size()==n.size()) {
        if (next>n) {
            return -1;
        }
    }
    return findIndex(b, next, index + 1, n);
}
int Fibonacci(string n) {
    if (n == "1") {
        return 1;
    }
    return findIndex("1", "1", 2, n);
}
int main() {
    cout << Fibonacci("5")<<endl;
    cout << Fibonacci("55")<<endl;
    cout << Fibonacci("4")<<endl;
    return 0;
}
