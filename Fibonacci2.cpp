#include<iostream>
#include<string>
using namespace std;
string sum(string x,string y) {
    string ans="";
    int carry=0;
    int i=x.size()-1;
    int j=y.size()-1;
    while(i>=0||j>=0||carry) {
        int s=carry;
        if(i>=0) {
            s+=x[i]-'0';
        }
        if(j>=0) {
            s+=y[j]-'0';
        }
        ans=char(s%10+'0')+ans;
        carry=s/10;
        i--;
        j--;
    }
    return ans;
}
int compare(string x,string y) {
    if(x.size()!=y.size()) {
        if(x.size()>y.size()) {
            return 1;
        }
        else {
            return -1;
        }
    }
    if(x==y) {
        return 0;
    }
    if(x>y) {
        return 1;
    }
    else {
        return -1;
    }
}
int findIndex(string n) {
    string first="0";
    string second="1";
    if(n=="0") {
        return 0;
    }
    if(n=="1") {
        return 1;
    }
    int index=1;
    while(true) {
        string next=sum(first,second);
        index++;
        if(compare(next,n)==0) {
            return index;
        }
        if(compare(next,n)==1) {
            return -1;
        }
        first=second;
        second=next;
    }
}

int main() {
    string n;
    cin>>n;
    cout<<findIndex(n);
}
