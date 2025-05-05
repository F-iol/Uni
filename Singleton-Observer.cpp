#include <iostream>
#include <string>
#include <vector>
using namespace std;
/// observer

class Student{
    private:
        string name;
        long indexID;
    public:
    Student(string name,long indexID){
        this->name=name;
        this->indexID=indexID;
    }
    void ShowNotif(string info){
        cout << "Student "<<name<<",got message: "<<info<<endl;
    }


};

class USOS{
    private:
        vector <Student*> StudentList;
    public:
        void Add_to_list(Student* student){
            StudentList.push_back(student);
        }
        void sendMessage(string message){
            for(Student* student:StudentList){
                student->ShowNotif(message);
            }
        }
        ~USOS(){
            for(Student* student:StudentList){
                delete(student);
            }
        }



};

// singleton

class Singleton{
    private:
    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }


};



int main()
{
    USOS* usos = new USOS;
    Student* student1=new Student("name1",1);
    Student* student2=new Student("name2",2);
    Student* student3=new Student("name3",3);
    

    usos ->Add_to_list(student1);
    usos->Add_to_list(student2);
    usos->Add_to_list(student3);
    usos->sendMessage("Message");

    delete(usos);
   

    Singleton& singleton = Singleton::getInstance();

}
