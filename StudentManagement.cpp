#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
    int rollno, age;
    string name;
    char sex;

public:
    Student(int stdrollno, int stdage, string stdname, char stdsex)
    {
        rollno = stdrollno;
        age = stdage;
        name = stdname;
        sex = stdsex;
    }

    // setter for roll number

    void setRollno(int stdrollno)
    {
        rollno = stdrollno;
    }

    // getter for roll number

    int getRollno()
    {
        return rollno;
    }
    // setter for age

    void setage(int stdage)
    {
        age = stdage;
    }

    // getter for age

    int getage()
    {
        return age;
    }

    // setter for name

    void setname(string stdname)
    {
        name = stdname;
    }

    // getter for name

    string getname()
    {
        return name;
    }

    // setter for sex

    void setsex(int stdsex)
    {
        sex = stdsex;
    }

    // getter for sex

    char getsex()
    {
        return sex;
    }
};
// function for adding new student
void addNewStudent(vector<Student> &students)
{
    int rollno, age;
    string name;
    char sex;
    std::cout << "\t\tEnter student's rollno : ";
    std::cin >> rollno;
    std::cout << "\t\tEnter student's name : ";
    std::cin >> name;
    std::cout << "\t\tEnter student's age : ";
    std::cin >> age;
    std::cout << "\t\tEnter student's sex : ";
    std::cin >> sex;

    students.push_back(Student(rollno, age, name, sex));

    std::cout << "\t\tCongratulations! Student has been added successfully...\n";
}

//function for showing student list
void showStudentList(vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "\t\tSorry their are no students currently.\n";
        return;
    }
    std::cout << "\t\tRoll No\t\t" << "Name\t\t" << "Age\t" << "Sex\n";

    for (Student student : students)
    {
        std::cout << "\t\t" << student.getRollno() << "\t\t" << student.getname() << "\t\t" << student.getage() << "\t" << student.getsex() << "\n";
    }
}
//function for searching for a student
void searchStudent(vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "\t\tSorry their are no students currently.\n";
        return;
    }
    int rollno;
    std::cout << "\t\tEnter student's roll number to be searched : " ;
    std::cin >> rollno;

    std::cout << "\t\tRoll No\t\t" << "Name\t\t" << "Age\t" << "Sex\n";

    for (Student student : students)
    {
        if (student.getRollno() == rollno)
        {
            std::cout << "\t\t" << student.getRollno() << "\t\t" << student.getname() << "\t\t" << student.getage() << "\t" << student.getsex() << "\n";
            return;
        }
    }
    std::cout << "\t\tNo student with mentioned roll number found!!!\n";
}

//function for updating a student's information
void updateStudentInfo(vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "\t\tSorry their are no students currently.\n";
        return;
    }
    int rollno;
    std::cout << "\t\tEnter student's roll number whose information is to be updated : " ;
    std::cin >> rollno;

    std::cout << "\t\tRoll No\t\t" << "Name\t\t" << "Age\t" << "Sex\n";

    for (Student student : students)
    {
        if (student.getRollno() == rollno)
        {
            std::cout << "\t\tStudent's Current Info : \n";
            std::cout << "\t\t" << student.getRollno() << "\t\t" << student.getname() << "\t\t" << student.getage() << "\t" << student.getsex() << "\n";
            int operation;
            std::cin >> operation;
            std::cout << "\t\tInput operation type for performing the updation : \n";
            std::cout << "\t\tType 1 : Update Roll Number\n";
            std::cout << "\t\tType 2 : Update name\n";
            std::cout << "\t\tType 3 : Update age\n";
            std::cout << "\t\tType 4 : Update sex\n";
            string nwname;
            switch (operation)
            {
            case 1:
                int newRollno;
                std::cout << "\t\tEnter new roll no. :";
                std::cin >> newRollno;
                student.setRollno(newRollno);
                break;
            case 2:
                // moved nwname to outside the switch statement due to error
                // "transfer of control bypasses initialization"
                std::cout << "\t\tEnter new name :";
                std::cin >> nwname;
                student.setname(nwname);
                break;
            case 3:
                int newage;
                std::cout << "\t\tEnter new age :";
                std::cin >> newage;
                student.setage(newage);
                break;
            case 4:
                char newsex;
                std::cout << "\t\tEnter new sex :";
                std::cin >> newsex;
                student.setsex(newsex);
                break;
            default:
                std::cout << "\t\tInvalid Operation!!!\n";
            }
            std::cout << "\t\tStudent details were updated successfully!!!\n";
            return;
        }
    }
    std::cout << "\t\tNo student with mentioned roll number found!!!\n";
}

//function for deleting a student's information
void deleteStudent(vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "\t\tSorry their are no students currently.\n";
        return;
    }
    int rollno;
    std::cout << "\t\tEnter student's roll number to be searched : " ;
    std::cin >> rollno;

    

    for (unsigned int i = 0; i < students.size(); ++i)
    {
        if (students[i].getRollno() == rollno)
        {
            std::cout << "\t\tRoll No\t\t" << "Name\t\t" << "Age\t" << "Sex\n";
            std::cout << "\t\t" << students[i].getRollno() << "\t\t" << students[i].getname() << "\t\t" << students[i].getage() << "\t" << students[i].getsex() << "\n";
            students.erase(students.begin() + i);
            std::cout << "\t\tStudent with mentioned roll number deleted successfully!!!\n";
            return;
        }
    }
    std::cout << "\t\tNo student with mentioned roll number found!!!\n";
}

int main()
{

    vector<Student> students;
    students.push_back(Student(1, 20, "Anchal", 'M'));
    std::cout << "\t--------Welcome to the Student Management System-------\n";
    std::cout << "\t\tInput operation type for performing the following operations : \n";

    std::cout << "\t\tType 1 : Add a student\n";
    std::cout << "\t\tType 2 : Show student list\n";
    std::cout << "\t\tType 3 : Search student\n";
    std::cout << "\t\tType 4 : Update student Info\n";
    std::cout << "\t\tType 5 : Delete student\n";
    std::cout << "\t\tType 6 : Exit\n";

    char choice;
    do
    {
        int operation;
        std::cout << "\t\tEnter the type of operation : ";
        std::cin >> operation;
        switch (operation)
        {
        case 1:
            addNewStudent(students);
            break;
        case 2:
            showStudentList(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            updateStudentInfo(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            return 0;
        default:
            std::cout << "\t\tInvalid Operation!!!\n";
        }

        std::cout << "\t\tDo you want to continue ? [y/n] : ";
        std::cin >> choice;
        // system("cls");
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
