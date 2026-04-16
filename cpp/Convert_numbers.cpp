#include <iostream>
#include <string>
using namespace std;

string convert(string s,int fromBase,int toBase){
	string dec="0";
	for(int i=0;i<s.size();i++){
		int carry=0;
		for(int j=dec.size()-1;j>=0;j--){
			int x=(dec[j]-'0')*fromBase+carry;
			dec[j]=(x%10)+'0';
			carry=x/10;
		}
		while(carry){
			dec=char(carry%10+'0')+dec;
			carry/=10;
		}
		int d=s[i]-'0';
		carry=d;
		for(int j=dec.size()-1;j>=0&&carry;j--){
			int x=(dec[j]-'0')+carry;
			dec[j]=(x%10)+'0';
			carry=x/10;
		}
		while(carry){
			dec=char(carry%10+'0')+dec;
			carry/=10;
		}
	}
	if(dec=="0")return"0";
	string ans="";
	while(dec!="0"){
		string res="";
		int carry=0;
		for(int i=0;i<dec.size();i++){
			int x=carry*10+(dec[i]-'0');
			res+=(x/toBase)+'0';
			carry=x%toBase;
		}
		int i=0;
		while(i<res.size()-1&&res[i]=='0')i++;
		res=res.substr(i);
		ans=char(carry+'0')+ans;
		dec=res;
	}
	return ans;
}

int main(){
	cout<<convert("534007",9,7);
}
