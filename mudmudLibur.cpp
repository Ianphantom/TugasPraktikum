#include <bits/stdc++.h>
using namespace std;
int main(){
    string word;
    int n,q,i,j;
    cin>>n;
    vector<string> satu;
    for(i=0;i<n;i++){
        cin>>word;
        satu.push_back(word);
    }
    cin>>q;
    for(i=1;i<=q;i++){
        cin>>word;
        int count = 0;
        vector<string> dua;
        for(string s: satu){
            if(s.find(word)==0){
                count++;
                dua.push_back(s);
            }
        }
        sort(dua.begin(), dua.end());
        dua.erase(unique(dua.begin(),dua.end()),dua.end());
        if(count){
            cout<<"Kasus #"<<i<<": "<<count<<endl;
            for(j=0;j<dua.size();j++){
                cout << dua[j] << endl;
            }
        }else{
            cout<<"Kasus #"<<i<<": Tidak ada hasil"<<endl;
        }
    }
    return 0;
}