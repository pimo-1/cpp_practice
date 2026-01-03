using namespace std;
#include <iostream>

// this program is main to access a 2-dimensional array using pointers
int main(){
    const int rows = 2 ;
    const int cols = 2 ;
    int arr [rows][cols] {
        {1, 2},
        {3, 4}
    };
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}
