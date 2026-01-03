using namespace std;
#include <iostream>

int main() {
    int grade ;
cout << "enter the grade of the student : " ;
int *p = &grade ;
cin >> *p ;
if ( *p >= 90 ) {
    cout << "A" << endl ;
}
else if ( *p >= 80 ) {
    cout << "B" << endl ;
}
 else if ( *p >= 70 ) {
    cout << "C" << endl ;
}
else if ( *p >= 60 ) {
    cout << "D" << endl ;
}
else {
    cout << "F" << endl ;
}
    return 0;
}