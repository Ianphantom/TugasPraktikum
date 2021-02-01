#include <bits/stdc++.h>
using namespace std;

long long  getMid(long long  s, long long  e){
    return s + (e - s) / 2;
}
 
long long  MaxUtil(long long * st, long long  ss, long long  se, long long  l, long long  r, long long  node){
    if (l <= ss && r >= se)
        return st[node];
 
    if (se < l || ss > r)
        return -1;
    long long  mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, se, l,  r, 2 * node + 2));
}

void change(long long  arr[], long long * st, long long  ss, long long  se, long long  index, long long  value, long long  node){

    if (ss == se) {   
        arr[index] = value;
        st[node] = value;
    }
    else {
        long long  mid = getMid(ss, se);

        if (index >= ss && index <= mid)
            change(arr, st,ss, mid, index, value, 2 * node + 1);
        else
            change(arr, st, mid + 1, se, index,value, 2 * node + 2);
         
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }
    return;
}
 
long long  findMax(long long * st, long long  n, long long  l, long long  r){
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
long long  constructSTUtil(long long  arr[], long long  ss, long long  se, long long * st, long long  si){
    if (ss == se) 
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    long long  mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
     
    return st[si];
}

long long * constructST(long long  arr[], long long  n)
{
    long long  x = (long long )(ceil(log2(n)));
    long long  max_size = 2 * (long long )pow(2, x) - 1;
    long long * st = new long long [max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
 
int main()
{
    long long  arr[100000];
    long long  banyak,kasus;
    cin >> banyak >> kasus;
    for(long long  i=0;i<banyak;i++){
        long long  angka;
        cin >> angka;
        arr[i]=angka;
    }  
    long long * st = constructST(arr, banyak);
    long long  test,test1,test2;
    for(long long  i=0;i<kasus;i++){
        cin >> test >> test1 >> test2;
        if(test==1){
            change(arr, st, 0, banyak - 1, test1-1, test2, 0);
        }else if(test==2){
            cout << findMax(st, banyak, test1-1, test2-1) << endl;
        }
    }
//    /*for(long long  i=0;i<banyak;i++){
//        cout << arr[i];
//    }*/
    return 0;
}