#include<iostream>
using namespace std;
int toInt(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        num=num*10+(s[i]-'0');
    }
    return num;
}
double toDouble(string s){
    double num=0;
    double frac=0;
    double Div=1;
    bool afterDot=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            afterDot=true;
        }else{
            if(!afterDot){
                num=num*10+(s[i]-'0');
            }else{
                frac=frac*10+(s[i]-'0');
                Div*=10;
            }
        }
    }
    return num+frac/Div;
}
bool check(string field,string op,string value,
           string name,string country,
           double lat,double lng,int population,
           string allNames[],int allPop[],int n){
    if(field=="population"){
        int x=toInt(value);
        if(op=="<"){
            return population<x;
        }
        if(op==">"){
            return population>x;
        }
        if(op=="=="){
            return population==x;
        }
    }
    if(field=="country"){
        if(op=="=="){
            return country==value;
        }
    }
    if(field=="lat"){
        double x=toDouble(value);
        if(op=="<"){
            return lat<x;
        }
        if(op==">"){
            return lat>x;
        }
        if(op=="=="){
            return lat==x;
        }
    }
    if(field=="lng"){
        double x=toDouble(value);
        if(op=="<"){
            return lng<x;
        }
        if(op==">"){
            return lng>x;
        }
        if(op=="=="){
            return lng==x;
        }
    }
    if(field=="city"){
        int ref=0;

        for(int i=0;i<n;i++){
            if(allNames[i]==value){
                ref=allPop[i];
            }
        }
        if(op=="<"){
            return population<ref;
        }
        if(op==">"){
            return population>ref;
        }
        if(op=="=="){
            return population==ref;
        }
    }
    return false;
}

int main(){
    int n=3;
    string name[3]={"Yerevan","Tokyo","Paris"};
    string country[3]={"Armenia","Japan","France"};
    double lat[3]={40.18,35.68,48.85};
    double lng[3]={44.51,139.69,2.35};
    int population[3]={1000000,37000000,2100000};
    string field,op,value;
    cin>>field>>op>>value;
    for(int i=0;i<n;i++){
        if(check(field,op,value,
                 name[i],country[i],lat[i],lng[i],population[i],
                 name,population,n)){
            cout<<name[i]<<" "<<country[i]<<" "<<lat[i]<<" "<<lng[i]<<" "
                <<population[i]<<endl;
        }
    }
    return 0;
}
