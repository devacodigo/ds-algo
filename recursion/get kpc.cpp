#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> codes={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};


vector<string> getKPC(string s){
    if(s.length()==0){
        vector<string> k;
        k.push_back("");
        return k;
    }
    char ch=s[0];
    string ss=s.substr(1);
    vector<string> sans=getKPC(ss);
    vector<string> fans;
    string codech =codes[ch-'0'];
    for(int i=0;i<codech.length();i++){
        char icode=codech[i];
        for(string ssans:sans){
            fans.push_back(icode+ssans);
            

        }
    }
    return fans;
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}