#include <bits/stdc++.h>
using namespace std;

int main(){
    vector< long long > conf;
    long long kasus;
    conf.push_back(2);
    cin >> kasus;
    while (conf.back() <= (long long)1e18){
        long long hasil;
        long long temp;
        hasil = (long long)conf.size() + 1;
        temp = 2 * hasil * hasil;
        conf.push_back(temp + conf.back());
    }
    for(int i=0;i<kasus;i++)
    {
        long long k;
        cin >> k;
        long long hasil = lower_bound(conf.begin(),conf.end(),k) - conf.begin() + 1;
        cout << hasil << endl;
    }
    return 0;
}