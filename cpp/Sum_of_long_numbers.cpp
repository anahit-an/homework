#include <iostream>
#include <string>
using namespace std;
string Sum(string a, string b) {
    char arr1[100]={0};
    char arr2[100]={0};
    int result[101]={0};
    string output="";
    
    for (int i=0; i<a.length(); i++) {
        arr1[i]=a[a.length()- 1-i];
    }
    for (int i=0; i<b.length(); i++) {
        arr2[i]=b[b.length() - 1-i];
    }
    int carry=0;
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
            digit1=0;
        }
        if (i<b.length()) {
            digit2=arr2[i]-'0';
        } 
        else {
            digit2=0;
        }
        int sum=digit1+digit2+carry;
        result[i]=sum%10;
        carry=sum/10;
    }
    if (carry>0) {
        result[maxLen]=carry;
        maxLen=maxLen+1;
    }
    for (int i=maxLen- 1; i>=0;i--) {
        output=output+char(result[i]+'0');
    }
    
    return output;
}

int main() {
    string a="123445";
    string b="123454567";
    cout<<Sum(a, b);
    return 0;
}
