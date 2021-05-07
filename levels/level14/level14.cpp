#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
using namespace std;


class TeacherUAF{
   private:
    virtual void idk()
    {
        system("/bin/sh");
    }

protected:
    string name;
    int grade;

public:
    TeacherUAF() = default;
    virtual void be_nasty()
    {
    cout << "I am a teacher, homework more I give!\n";
    };
};

class StudentUAF: public TeacherUAF{
public:
    virtual void be_nasty()
    {
        cout << "I am a student, pull prank on teacher\n";
    };
};

int main()
{
    cout.setf(ios::unitbuf);
    cin.setf(ios::unitbuf);
    cout << "I really like tables that are V shaped - they are the next thing!\n";

    int choice;
    unsigned int size;
    char* jjj;
    StudentUAF* stud = new StudentUAF();
    while(true)
    {
        cout <<"1. delete_student\n2. be_nasty\n3. malloc\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                delete stud;
                break;

            case 2:
                stud->be_nasty();
                break;

            case 3:
                cout << "size: ";
                cin >> size;
                jjj = new char[size];
                cout << "data :" << flush;
                read(0,jjj,size);
                break;
            
            default:
                break;
        }
    }
}