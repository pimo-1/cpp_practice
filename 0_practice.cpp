using namespace std;
#include <iostream>

int main() {
    string name ;
    cout << "please enter your name : ";
    cin >> name ;
    string *p = &name ;    
    cout << "hello, " << *p << "!" << endl;
    return 0;

}

