#include<iostream>
 #include<bits/stdc++.h>
    using namespace std;

            void Bubblesort(int arr[], int n){
                  for(int i=1; i<n; i++){
                        
                        for(int j=0; j<n-i; j++){
                            if(arr[j]>arr[j+1])
                                swap(arr[j], arr[j+1]);
                            
                        }
                  }
                  cout<<"After Sorting by BubbleSort Array is: ";
                  for(int i=1; i<n; i++){
                    cout<<arr[i]<<" ";
                  }
            }
    int main(){
        int arr[8]={1,5,87,55,95,8,85};
        Bubblesort(arr, 8);
        return 0;
    }
//Daily Leet