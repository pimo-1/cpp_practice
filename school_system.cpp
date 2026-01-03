#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

// ==================================================
// ENUMS
// ==================================================
enum class Gender {
    Male,
    Female
};

enum class Grade {
    A, B, C, D, F
};

// ==================================================
// ABSTRACT BASE CLASS
// ==================================================
class Person {
protected:
    int id;
    string name;
    int age;
    Gender gender;

public:
    Person(int id, string name, int age, Gender gender)
        : id(id), name(name), age(age), gender(gender) {}

    virtual void display() const = 0;
    virtual string role() const = 0;

    int getId() const { return id; }
    string getName() const { return name; }

    virtual ~Person() = default;
};

// ==================================================
// STUDENT CLASS
// ==================================================
class Student : public Person {
private:
    string level;
    map<string, double> grades;

public:
    Student(int id, string name, int age, Gender gender, string level)
        : Person(id, name, age, gender), level(level) {}

    void addGrade(const string& course, double score) {
        if (score < 0 || score > 100)
            throw invalid_argument("Invalid score value");
        grades[course] = score;
    }

    double calculateGPA() const {
        if (grades.empty()) return 0.0;

        double total = 0;
        for (auto& g : grades)
            total += g.second;

        return total / grades.size();
    }

    void display() const override {
        cout << "\n[STUDENT]\n";
        cout << "ID: " << id << "\nName: " << name
             << "\nAge: " << age
             << "\nLevel: " << level
             << "\nGPA: " << fixed << setprecision(2)
             << calculateGPA() << endl;

        for (auto& g : grades)
            cout << "  " << g.first << " -> " << g.second << endl;
    }

    string role() const override {
        return "Student";
    }
};

// ==================================================
// TEACHER CLASS
// ==================================================
class Teacher : public Person {
private:
    string department;
    double salary;

public:
    Teacher(int id, string name, int age, Gender gender,
            string department, double salary)
        : Person(id, name, age, gender),
          department(department), salary(salary) {}

    void display() const override {
        cout << "\n[TEACHER]\n";
        cout << "ID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nDepartment: " << department
             << "\nSalary: " << salary << endl;
    }

    string role() const override {
        return "Teacher";
    }
};

// ==================================================
// COURSE CLASS
// ==================================================
class Course {
private:
    string code;
    string title;
    int maxScore;

public:
    Course(string code, string title, int maxScore = 100)
        : code(code), title(title), maxScore(maxScore) {}

    string getCode() const { return code; }
    string getTitle() const { return title; }

    void display() const {
        cout << "Course: " << code
             << " | " << title
             << " | Max Score: " << maxScore << endl;
    }
};

// ==================================================
// DATABASE LAYER
// ==================================================
class SchoolDatabase {
private:
    vector<shared_ptr<Person>> people;
    vector<Course> courses;

public:
    void addPerson(shared_ptr<Person> person) {
        people.push_back(person);
    }

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    shared_ptr<Person> findPerson(int id) {
        for (auto& p : people)
            if (p->getId() == id)
                return p;
        throw runtime_error("Person not found");
    }

    void displayAll() const {
        for (auto& p : people)
            p->display();
    }

    void displayCourses() const {
        for (auto& c : courses)
            c.display();
    }
};

// ==================================================
// SYSTEM CONTROLLER
// ==================================================
class SchoolSystem {
private:
    SchoolDatabase db;

public:
    void createStudent() {
        int id, age;
        string name, level;
        int genderInput;

        cout << "ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Gender (0=Male,1=Female): ";
        cin >> genderInput;
        cin.ignore();

        cout << "Level: ";
        getline(cin, level);

        db.addPerson(make_shared<Student>(
            id, name, age, static_cast<Gender>(genderInput), level
        ));
    }

    void createTeacher() {
        int id, age;
        string name, dept;
        double salary;
        int genderInput;

        cout << "ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Gender (0=Male,1=Female): ";
        cin >> genderInput;
        cin.ignore();

        cout << "Department: ";
        getline(cin, dept);

        cout << "Salary: ";
        cin >> salary;

        db.addPerson(make_shared<Teacher>(
            id, name, age, static_cast<Gender>(genderInput),
            dept, salary
        ));
    }

    void addCourse() {
        string code, title;
        cout << "Course Code: ";
        cin >> code;
        cin.ignore();

        cout << "Title: ";
        getline(cin, title);

        db.addCourse(Course(code, title));
    }

    void addGradeToStudent() {
        int id;
        string course;
        double grade;

        cout << "Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Course: ";
        getline(cin, course);

        cout << "Grade: ";
        cin >> grade;

        auto person = db.findPerson(id);
        auto student = dynamic_pointer_cast<Student>(person);

        if (!student)
            throw runtime_error("Person is not a student");

        student->addGrade(course, grade);
    }

    void showAll() {
        db.displayAll();
    }

    void showCourses() {
        db.displayCourses();
    }
};

// ==================================================
// MENU
// ==================================================
void menu() {
    cout << "\n===== ADVANCED SCHOOL MANAGEMENT =====\n";
    cout << "1. Add Student\n";
    cout << "2. Add Teacher\n";
    cout << "3. Add Course\n";
    cout << "4. Add Grade\n";
    cout << "5. Display All People\n";
    cout << "6. Display Courses\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

// ==================================================
// MAIN
// ==================================================
int main() {
    SchoolSystem system;
    int choice;

    try {
        do {
            menu();
            cin >> choice;

            switch (choice) {
                case 1: system.createStudent(); break;
                case 2: system.createTeacher(); break;
                case 3: system.addCourse(); break;
                case 4: system.addGradeToStudent(); break;
                case 5: system.showAll(); break;
                case 6: system.showCourses(); break;
                case 0: cout << "Exiting...\n"; break;
                default: cout << "Invalid option\n";
            }
        } while (choice != 0);
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
