#include <iostream>
#include <string>
using namespace std;
int main() {
    string s="([])";
    string stack;
    string open="({[";
    string close=")}]";
    for (int i=0;i<s.length();i++){
        char c=s[i];
        bool isValid=false;
        for (int j=0;j<open.length();j++){
            if (c==open[j]){
                stack.push_back(c);
                isValid=true;
                break;
            }
        }
        if (isValid){
            continue;
        }
        for (int j=0;j<close.length();j++){
            if (c==close[j]){
                if (stack.size()==0 || stack[stack.size()-1]!=open[j]){
                    cout<<"False";
                    return 0;
                }
                stack.pop_back();
                isValid=true;
                break;
            }
        }
        if (!isValid){
            cout<<"False";
            return 0;
        }
    }
    if (stack.size()==0){
        cout<<"True";
    }
    else {
        cout<<"False";
    }
    return 0;
}
