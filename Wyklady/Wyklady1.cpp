#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int age;
    string name;

public:
    Student(int age, string name) {
        this->age = age;
        this->name = name;
    }

    Student(int age) {
        this->age = age;
        this->name = "";
    }

    void setName(string name) {
        if (this->name == "")
            this->name = name;

    }
};


int main(int argc, char const* argv[]) {

    Student student1(21, "Anna");
    student1.setName("Ola");

    cout << 5 + 5;
    return 0;
}