#include <iostream>
#include <string>
using namespace std;
string Subtract(string a, string b) {
    char arr1[100] = {0};
    char arr2[100] = {0};
    int result[100] = {0};
    string output = "";
    for (int i=0; i<a.length(); i++) {
        arr1[i]=a[a.length()- 1-i];
    }
    for (int i=0; i<b.length(); i++) {
        arr2[i]=b[b.length()- 1-i];
    }
    int borrow=0;  
    int maxLen;
    
    if (a.length()>b.length()) {
        maxLen=a.length();
    }
    else {
        maxLen=b.length();
    }
    
    for (int i=0; i<maxLen; i++) {
        int digit1, digit2;
        if (i<a.length()) {
            digit1=arr1[i]-'0';
        }
        else {
            digit1 = 0;
        }
        if (i<b.length()) {
            digit2=arr2[i]-'0';
        }
        else {
            digit2=0;
        }
        int diff=digit1-digit2-borrow;
        if (diff<0) {
            diff=diff+10;
            borrow=1;
        } 
        else {
            borrow=0;
        }
        
        result[i]=diff;
    }
    int endIndex=maxLen- 1;
    while (endIndex>0 && result[endIndex]==0) {
        endIndex--;
    }
    for (int i=endIndex; i>=0; i--) {
        output=output+char(result[i]+'0');
    }
    return output;
}
int main() {
    string a="123454567";
    string b="123445";
    cout<<Subtract(a, b);
    return 0;
}
