#include <iostream>
#include <string>
using namespace std;

class student {
    private :
    string name ;
    int age ;
    protected :
    int id ;
    public :
    student(string n, int a, int i) {
        name = n ;
        age = a ;
        id = i ;
        cout << "constructor called" << endl ;
    }
    
    ~student(){
        cout << "destructor called" << endl ;
    }
    
    virtual void student_info(string n, int a , int i) {
        name = n ;
        age = a ;
        id = i ;
    }
};
class exam_info : public student {
    private :
    int marks ;
    public :
    exam_info(int m, string n, int a, int i) : student(n, a, i) {
        marks = m ;
    }
    void student_info(string n, int a , int i, int m) {
        student::student_info(n, a, i) ;
        marks = m ;
        
    }
    
    ~exam_info() {
        cout << "student marks: " << marks << endl ;

    }
};

int main() {
    string name ;
    int age ;
    int id ;
    int marks ;
    cout << "enter student name: " ;
    cin >> name ;
    cout << "enter student age: " ;
    cin >> age ;
    cout << "enter student id: " ;
    cin >> id ;
    cout << "enter student marks: " ;
    cin >> marks ;
    
    student s1(name, age, id) ;
    exam_info e1(marks, name, age, id) ;
    
    return 0;
}
