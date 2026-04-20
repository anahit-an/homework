#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct City{
    string name;
};
string toLower(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}
bool isUsed(vector<string> &used,string city){
    for(int i=0;i<used.size();i++){
        if(used[i]==city){
            return true;
        }
    }
    return false;
}
int similarity(string a,string b){
    int len=min(a.size(),b.size());
    int count=0;
    for(int i=0;i<len;i++){
        if(a[i]==b[i]){
            count++;
        }
    }
    return count;
}
int main(){
    ifstream f("worldcities.csv");
    vector<City> cities;
    if(!f){
        cout<<"File not found\n";
        return 0;
    }
    string line;
    getline(f,line);
    while(getline(f,line)){
        string name="";
        int comma=0;
        bool quotes=false;

        for(int i=0;i<line.size();i++){
            if(line[i]=='"'){
                quotes=!quotes;
            }
            else if(line[i]==',' && quotes==false){
                comma++;
            }
            else{
                if(comma==1){
                    name=name+line[i];
                }
            }
            if(comma>1){
                break;
            }
        }
        if(name!=""){
            City c;
            c.name=toLower(name);
            cities.push_back(c);
        }
    }
    f.close();
    vector<string> used;
    string user;
    cout<<"Start game\n";
    while(true){
        cout<<"Your city: ";
        getline(cin,user);
        if(user==""){
            getline(cin,user);
        }
        user=toLower(user);
        if(user=="help"){
            if(used.size()==0){
                bool suggested=false;
                for(int i=0;i<cities.size();i++){
                    string c=cities[i].name;
                    if(!isUsed(used,c)){
                        cout<<"The Computer is suggesting you: "<<c<<endl;
                        suggested=true;
                        break;
                    }
                }
                if(!suggested){
                    cout<<"No suggestion found!\n";
                }
            }
            else{
                char last=used.back()[used.back().size()-1];
                bool suggested=false;
                for(int i=0;i<cities.size();i++){
                    string c=cities[i].name;
                    if(c[0]==last && !isUsed(used,c)){
                        cout<<"The Computer is suggesting you: "<<c<<endl;
                        suggested=true;
                        break;
                    }
                }
                if(!suggested){
                    cout<<"No suggestion found!\n";
                }
            }
            continue;
        }
        if(user=="end"){
            break;
        }
        bool ok=false;
        for(int i=0;i<cities.size();i++){
            if(cities[i].name==user){
                ok=true;
            }
        }
        if(ok==false){
            string best="";
            int maxSim=0;
            for(int i=0;i<cities.size();i++){
                string c=cities[i].name;
                int sim=similarity(user,c);

                if(sim>maxSim){
                    maxSim=sim;
                    best=c;
                }
            }
            if(maxSim>=3){
                cout<<"City not found! Maybe you meant: "<<best<<endl;
            }
            else{
                cout<<"City not found!\n";
            }
            continue;
        }
        if(isUsed(used,user)){
            cout<<"Already used!\n";
            continue;
        }
        used.push_back(user);
        char last=user[user.size()-1];
        bool found=false;
        for(int i=0;i<cities.size();i++){
            string c=cities[i].name;
            if(c[0]==last){
                if(!isUsed(used,c)){
                    cout<<"Computer: "<<c<<endl;
                    used.push_back(c);
                    found=true;
                    break;
                }
            }
        }
        if(found==false){
            cout<<"Computer can't find city. You win!\n";
            break;
        }
    }
    cout<<"Game over\n";
    return 0;
}
