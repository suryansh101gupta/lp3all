// #include<bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int partDeter(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qsDeter(vector<int>& arr, int low, int high){
    if(low<high){
        int pi = partDeter(arr, low, high);
        qsDeter(arr, low, pi-1);
        qsDeter(arr, pi+1, high);
    }
}

int partRandom(vector<int>& arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomPivotIndex]);
    return partDeter(arr, low, high);  
}

void qsRandom(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partRandom(arr, low, high);
        qsRandom(arr, low, pi - 1);
        qsRandom(arr, pi + 1, high);
    }
}

int main(){
    vector<int> arr;

    int n;
    cout<<"enter number of elements"<<endl;
    cin>>n;

    cout<<endl<<"enter elements"<<endl;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> arrDeter = arr;
    qsDeter(arrDeter, 0, arrDeter.size()-1);
    cout << "Deterministic Quick Sort Result: ";
    for (int x : arrDeter) cout << x << " ";
    cout << endl;


    vector<int> arrRandom = arr;
    srand(time(0));
    qsRandom(arrRandom, 0, arrRandom.size() - 1);
    cout << "Randomized Quick Sort Result: ";
    for (int x : arrRandom) cout << x << " ";
    cout << endl;

    return 0;
}