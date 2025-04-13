# include <iostream>
using namespace std;


int check(int i, int arr[], int n){
    int count=0;
    for( i=0;i<n;i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
                check(i+3, arr, n-3);
            } 
            else{
                return 0;
            }
        }

    }
    return count;
}

int main(){
    int arr[] = {1,2,3,4,2,3,3,5,7};
   cout<< check(0,arr,9);
    return 0;
}