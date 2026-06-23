using namespace std;
#include <iostream>

// this program is main to print a pyramid of n rows of the symbol '*'
/*
for example if n=4 the output will be :
   at first we start with the loop that manages the rows 
   the second loop is main to print the spaces sequence for the pyramid 
   the third loop is main to print the stars for the pyramid 
*/ 
int main() {
     int rows ;
     int *r = &rows ;
     cout << "enter the number of rows u want to make a pyramid of : " ;
     cin >> *r ;
        for ( int i = 0 ; i < *r ; i++ ) {
            // this loop is main to print the rows 
            for ( int j = 0 ; j < *r - i - 1 ; j++ ) {
                // this loop is main to print the spaces sequence for the pyramid 
                cout << " " ;
                for ( int k = 0 ; k < 2 * i +1 ; k++ ) {
                    // this loop is main to print the stars for the pyramid 
                    cout << "*" ;
                    cout << endl ;
                }
                return 0 ;
            }
            

           
            
        }
     
     
}
