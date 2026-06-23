#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n ;
int arr[100] ;
// mean fucnction is mean to calculate the mean of the array 
float mean_fuction(){
cout << "enter the number of elements in the array : " ;
    cin >> n ;
    float sum = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        cout << "enter element " << i+1 << " : " ;
        cin >> arr[i] ;
        sum += arr[i] ;
    }
    float mean = sum / n ;
    cout << "Mean: " << mean << endl ;
    return mean ;
}
// variance function is mean to calculate the variance of the array
float variance_function(){
    mean_fuction() ;
    float mean = 0 ;
    float sum = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        sum += arr[i] ;
    }
    mean = sum / n ;
    float variance = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        variance += (arr[i] - mean) * 2 ;
    }
    variance = variance / n ;
    cout << "Variance: " << variance << endl ;
    return variance ;
}
// here in the main function we display all the past functions and we also calculate the max value in the array
int main(){
    mean_fuction() ;
    variance_function() ;
    int max_value ;
    int swap ;
// the bubble sort here have time complexity of O(n^2)
    for ( int i=0 ; i < n ; i++ ){
        for ( int j = 0 ; j < i ; j++ ) {
            if (arr[j] > arr[j+1]){
                swap = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = swap ;
            } else {
                max_value = arr[j+1] ;
            }
        }
    }
    cout << "Max value: " << max_value << endl ;
    cout << "the mean value is :" << mean_fuction() << endl ;
    cout << " the variance value is :"<< variance_function() << endl ;

    return 0 ;
}
