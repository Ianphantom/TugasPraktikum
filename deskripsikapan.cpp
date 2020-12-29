#include <iostream>
#include <deque>
using namespace std;
void printKMax(long long arr[], long long n, long long k){
    deque<pair<long long, long long>> dq;
    long long sum=0;
    for(long long a=0; a<n; a++){
        while(!dq.empty() && a - dq.front().second >= k){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().first <= arr[a]){
            dq.pop_back();
        }
        dq.push_back({arr[a], a});
        if(a >= k - 1){
            sum+=dq.front().first;
        }
    }
    cout <<sum<<"\n";
}

int main(){
    long long n,k;
    cin >> n >> k;
    long long i;
    long long arr[n];
    for(i=0;i<n;i++)
        cin >> arr[i];
    printKMax(arr, n, k);
    return 0;
}