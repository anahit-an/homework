#include <iostream>
#include <string>
using namespace std;
string String(int n) {
    string result="";
    while (n>0) {
        char digit=(n % 10) + '0';
        result=digit+result;
        n/=10;
    }
    return result;
}
string RLE(string a) {
    string result="";
    int count=1;
    for (int i=0; i<a.length(); i++) {
        if (i<a.length()- 1 && a[i]==a[i+ 1]) {
            count++;
        }
        else {
            if (count>1) {
                result+=String(count);
            }
            result+=a[i];
            count=1;
        }
    }

    return result;
}
int main() {
    string a="aabbbcd";
    cout<<RLE(a);
    return 0;
}
