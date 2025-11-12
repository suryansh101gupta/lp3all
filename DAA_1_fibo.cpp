#include<bits/stdc++.h>
using namespace std;


int fibo_recur(int n){
    if(n<=1){
        return n;
    }
    return fibo_recur(n-1) + fibo_recur(n-2);
}

void print_recur(int n){
    for(int i=0; i<=n; i++){
        cout<< fibo_recur(i) <<endl;
    }
    cout<< "Recursive Completete" <<endl;
}

void fibo_iter(int n){
    int a1 = 0;
    int a2 = 1;
    
    if(n==0){
        cout<< a1 <<endl;
        cout<< "Iterative Completete" <<endl;
        return;
    }
    
    cout << a1 <<endl;
    cout << a2 <<endl;
    
    for(int i=2; i<=n; i++){
        int a3 = a1 + a2;
        a1 = a2;
        a2 = a3;
        cout << a2 <<endl;
    }
    cout<< "Iterative Completete" <<endl;
}

int main(){

    print_recur(0);
    print_recur(5);
    fibo_iter(0);
    fibo_iter(5);
    return 0;
}