#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Admin;
class Student;
class Doctor;
class TA;

void welcomePage();
void FrontEndline();

// Todo ================================================================================================================================================================
// Todo ------------------------------------------------->                           Class Admin                           <--------------------------------------------
// Todo ================================================================================================================================================================
char x = 221, Y = 222;
char u[15], ps[11], r1 = 201, r2 = 200, r3 = 188, r4 = 187, r5 = 205, r6 = 186, r7 = 220, r8 = 202, r9 = 204, r10 = 203, r11 = 206, r12 = 185;

class Admin
{
public:
    void main();
    void login();
    void sleep(int seconds);
    bool search(string enteredGmail, string enteredPassword);
    void logout();
    void Schedule();
    void finalResult();
    void dashboard();
    void dashboardDoctor();
    void dashboardTA();
    void dashboardAdmin();
    // TABLE ==============> L1 <==============
    // !! Section L1 Test Done @0xMoataz
    void dashboardStudentL1();
    void readCSVL1();
    void insertnodeL1(string gmail, string password, string rank, string id, string name, string group, string gpa,
                      string hours, string electronics, string linearAlgebra, string programming, string discreteMath,
                      string presentation, string english);
    void AddStudentL1();
    bool isDuplicateL1(string gmail, string id);
    bool isDuplicateL1(string gmail); // !! Overload
    void exportToCSVL1();
    void editNodeL1();
    void deleteL1();
    void displayL1();
    void searchL1();
    // TABLE ==============> L2 <==============
    void dashboardStudentL2();
    void readCSVL2();
    void insertnodeL2(string email, string password, string rank, string id, string name, string group, string gpa,
                      string hours, string eventDriven, string probability, string principles, string analysis, string dataCommunications, string informationSystems);
    void AddStudentL2();
    bool isDuplicateL2(string gmail, string id);
    bool isDuplicateL2(string gmail); // !! Overload
    void exportToCSVL2();
    void editNodeL2();
    void deleteL2();
    void displayL2();
    void searchL2();
    // TABLE ==============> L3 <==============
    void dashboardStudentL3();
    void readCSVL3();
    void insertnodeL3(string email, string password, string rank, string id, string name, string group, string gpa,
                      string hours, string sysModeling, string dataProgramming, string faultTolerance,
                      string aiIntro, string infoSecurity, string computerGraphics);
    void AddStudentL3();
    bool isDuplicateL3(string gmail, string id);
    bool isDuplicateL3(string gmail); // !! Overload
    void exportToCSVL3();
    void editNodeL3();
    void deleteL3();
    void displayL3();
    void searchL3();
    // TABLE ==============> Doctor <==============
    void readCSVDr();
    void insertNodeDr(string email, string password, string name,
                      string course1, string code1, string course2, string code2, string course3, string code3, string numOfCourses);
    void AddDr();
    bool isDuplicateDr(string gmail);
    void exportToCSVDr();
    void editNodeDr();
    void deleteDr();
    void displayDr();
    void searchDr();
    // TABLE ==============> Admin <==============
    void readCSVAdmin();
    void insertNodeAdmin(string email, string password, string name);
    void AddAdmin();
    bool isDuplicateTA(string gmail);
    void exportToCSVAdmin();
    void editNodeAdmin();
    void deleteAdmin();
    void displayAdmin();
    void searchAdmin();
    // TABLE ==============> TA <==============
    void readCSVTA();
    void insertNodeTA(string gmail, string password, string name, string course1, string code1, string course2, string code2, string numOfCourses);
    void AddTA();
    bool isDuplicateAdmin(string gmail);
    void exportToCSVTA();
    void editNodeTA();
    void deleteTA();
    void displayTA();
    void searchTA();

protected:
    string enteredGmail;
    string enteredPassword;
    string email;
    string password;
    string name;
    // TABLE ==============> L1 <==============

    struct Student_nodeL1
    {
        string gmail;
        string password;
        string rank;
        string id;
        string name;
        string group;
        string gpa;
        string hours;
        string electronics;
        string linearAlgebra;
        string programming;
        string discreteMath;
        string presentation;
        string english;
        Student_nodeL1 *next;
    };
    Student_nodeL1 *headL1 = NULL;
    Student_nodeL1 *checkL1();

    // TABLE ==============> L2 <==============

    struct Student_nodeL2
    {
        string email;
        string password;
        string rank;
        string id;
        string name;
        string group;
        string gpa;
        string hours;
        string eventDriven;
        string probability;
        string principles;
        string analysis;
        string dataCommunications;
        string informationSystems;
        Student_nodeL2 *next;
    };
    Student_nodeL2 *headL2 = NULL;
    Student_nodeL2 *checkL2();
    // TABLE ==============> L3 <==============
    struct Student_nodeL3
    {
        string email;
        string password;
        string rank;
        string id;
        string name;
        string group;
        string gpa;
        string hours;
        string sysModeling;
        string dataProgramming;
        string faultTolerance;
        string aiIntro;
        string infoSecurity;
        string computerGraphics;
        Student_nodeL3 *next;
    };
    Student_nodeL3 *headL3 = nullptr;
    Student_nodeL3 *checkL3();
    // TABLE ==============> L4 <==============
    // TABLE ==============> Dr <==============
    struct DoctorNode
    {
        string email;
        string password;
        string name;
        string course1;
        string code1;
        string course2;
        string code2;
        string course3;
        string code3;
        string numOfCourses; // Change from int to string
        DoctorNode *next;
    };
    DoctorNode *headDr = NULL;
    // TABLE ==============> Dr <==============
    struct AdminNode
    {
        string email;
        string password;
        string name;
        AdminNode *next;
    };
    AdminNode *headAdmin = NULL;
    // TABLE ==============> Dr <==============
    struct TANode
    {
        string gmail;
        string password;
        string name;
        string course1;
        string code1;
        string course2;
        string code2;
        string numOfCourses;
        TANode *next;
    };
    TANode *headTA = NULL;
};

Admin::Student_nodeL1 *Admin::checkL1()
{
    string searchID;
    cout << "Enter The ID Of The L1 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        if (tempL1->id == searchID)
        {
            return tempL1;
        }
        tempL1 = tempL1->next;
    }
    return nullptr;
}

Admin::Student_nodeL2 *Admin::checkL2()
{
    string searchID;
    cout << "Enter The ID Of The L2 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL2 *tempL2 = headL2;
    while (tempL2 != nullptr)
    {
        if (tempL2->id == searchID)
        {
            return tempL2;
        }
        tempL2 = tempL2->next;
    }
    return nullptr;
}

Admin::Student_nodeL3 *Admin::checkL3()
{
    string searchID;
    cout << "Enter The ID Of The L3 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL3 *tempL3 = headL3;
    while (tempL3 != nullptr)
    {
        if (tempL3->id == searchID)
        {
            return tempL3;
        }
        tempL3 = tempL3->next;
    }
    return nullptr;
}

void Admin::sleep(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void Admin::main()
{
    bool adminFlag = true;
    int adminChoice; // Fixed High Bug in Code @0xMoataz

    while (adminFlag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           WELCOME TO ADMIN PAGE            " << Y << "\n\n";

        cout << "[1] - Login" << endl;
        cout << "[2] - Exit" << endl;
        cout << "[0] - Go Back to Welcome Page" << endl;
        cout << "\n>> Enter your choice : ";

        if (!(cin >> adminChoice)) // if enter string or any thing not number catch error and ignore value @0xMoataz
        {
            cin.clear();                                                   // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            system("color 04");
            cout << "\aInvalid input. Please enter a number.\n";
            system("pause");
            system("color 07");
            system("cls");
            continue; // skip the rest of the loop and start over
        }

        switch (adminChoice)
        {
        case 1:
            readCSVL1();
            readCSVL2();
            readCSVL3();
            readCSVDr();
            readCSVAdmin();
            readCSVTA();
            system("cls");
            login();
            break;
        case 2:
            cout << "Exiting the program . . .\n";
            exit(0);
            break;
        case 0:
            adminFlag = false;
            system("cls");
            welcomePage();
            break;
        default:
            system("color 04");
            cout << "\aInvalid choice. Please try again.\n";
            cout << "Try Again !!" << endl;
            sleep(2);
            system("pause");
            system("color 07");
            system("cls");
        }
    }
}

void Admin::login()
{
    bool flag = true;

    while (flag)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "                LOGIN ADMIN                " << Y << "\n\n";

        cout << "Enter Gmail    : ";
        getline(cin, enteredGmail);
        cout << "Enter Password : ";
        getline(cin, enteredPassword);

        if (search(enteredGmail, enteredPassword))
        {
            system("cls");
            dashboard();
        }
        else
        {
            flag = false;
            system("cls");
        }
    }
}

bool Admin::search(string enteredGmail, string enteredPassword)
{
    AdminNode *tempAdmin = headAdmin;
    while (tempAdmin != nullptr)
    {
        if (tempAdmin->email == enteredGmail && tempAdmin->password == enteredPassword)
        {
            cout << setw(65) << "LOGIN SUCCESSFUL !! " << setw(65) << endl;
            email = enteredGmail;
            password = enteredPassword;
            name = tempAdmin->name;
            return true;
        }
        tempAdmin = tempAdmin->next;
    }

    system("color 04");
    cout << "\aLogin failed. Incorrect Gmail or password." << endl;
    cout << "Try Again !!" << endl;
    // sleep(3); // Fixed High Bug in Code @0xMoataz
    system("pause");
    system("color 07");
    cout << endl;
    return false;
}

void Admin::logout()
{
    cout << setw(62) << "Logging out ";
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << ".";
    }

    // !! FREE MEMORY
    // !! Delete All Nodes in Admin

    Student_nodeL1 *tempL1 = headL1;
    Student_nodeL2 *tempL2 = headL2;
    Student_nodeL3 *tempL3 = headL3;
    DoctorNode *tempDr = headDr;
    AdminNode *tempAdmin = headAdmin;
    TANode *tempTA = headTA;

    while (tempL1 != nullptr)
    {
        Student_nodeL1 *next = tempL1->next;
        delete tempL1;
        tempL1 = next;
    }
    while (tempL2 != nullptr)
    {
        Student_nodeL2 *next = tempL2->next;
        delete tempL2;
        tempL2 = next;
    }
    while (tempL3 != nullptr)
    {
        Student_nodeL3 *next = tempL3->next;
        delete tempL3;
        tempL3 = next;
    }
    while (tempDr != nullptr)
    {
        DoctorNode *next = tempDr->next;
        delete tempDr;
        tempDr = next;
    }
    while (tempAdmin != nullptr)
    {
        AdminNode *next = tempAdmin->next;
        delete tempAdmin;
        tempAdmin = next;
    }
    while (tempTA != nullptr)
    {
        TANode *next = tempTA->next;
        delete tempTA;
        tempTA = next;
    }

    headL1 = nullptr;
    headL2 = nullptr;
    headL3 = nullptr;
    headDr = nullptr;
    headAdmin = nullptr;
    headTA = nullptr;
    system("cls");
    main();
}

void Admin::readCSVL1()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level1.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (headL1er)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string gmail, password, rank, id, name, group, gpa, hours, electronics, linearAlgebra, programming, discreteMath, presentation, english;

        getline(iss, gmail, delimiter);
        getline(iss, password, delimiter);
        getline(iss, rank, delimiter);
        getline(iss, id, delimiter);
        getline(iss, name, delimiter);
        getline(iss, group, delimiter);
        getline(iss, gpa, delimiter);
        getline(iss, hours, delimiter);
        getline(iss, electronics, delimiter);
        getline(iss, linearAlgebra, delimiter);
        getline(iss, programming, delimiter);
        getline(iss, discreteMath, delimiter);
        getline(iss, presentation, delimiter);
        getline(iss, english, delimiter);

        insertnodeL1(gmail, password, rank, id, name, group, gpa,
                     hours, electronics, linearAlgebra, programming, discreteMath,
                     presentation, english);
    }

    file.close();
}
void Admin::readCSVL2()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level2.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string email, password, rank, id, group, name, gpa, hours, eventDriven, probability, principles, analysis, dataCommunications, informationSystems;

        getline(iss, email, delimiter);
        getline(iss, password, delimiter);
        getline(iss, rank, delimiter);
        getline(iss, id, delimiter);
        getline(iss, name, delimiter);
        getline(iss, group, delimiter);
        getline(iss, gpa, delimiter);
        getline(iss, hours, delimiter);
        getline(iss, eventDriven, delimiter);
        getline(iss, probability, delimiter);
        getline(iss, principles, delimiter);
        getline(iss, analysis, delimiter);
        getline(iss, dataCommunications, delimiter);
        getline(iss, informationSystems, delimiter);

        insertnodeL2(email, password, rank, id, name, group, gpa,
                     hours, eventDriven, probability, principles, analysis,
                     dataCommunications, informationSystems);
    }

    file.close();
}
void Admin::readCSVL3()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level3.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string email, password, rank, id, name, group, gpa, hours, sysModeling, dataProgramming, faultTolerance,
            aiIntro, infoSecurity, computerGraphics;

        getline(iss, email, delimiter);
        getline(iss, password, delimiter);
        getline(iss, rank, delimiter);
        getline(iss, id, delimiter);
        getline(iss, name, delimiter);
        getline(iss, group, delimiter);
        getline(iss, gpa, delimiter);
        getline(iss, hours, delimiter);
        getline(iss, sysModeling, delimiter);
        getline(iss, dataProgramming, delimiter);
        getline(iss, faultTolerance, delimiter);
        getline(iss, aiIntro, delimiter);
        getline(iss, infoSecurity, delimiter);
        getline(iss, computerGraphics, delimiter);

        insertnodeL3(email, password, rank, id, name, group, gpa,
                     hours, sysModeling, dataProgramming, faultTolerance,
                     aiIntro, infoSecurity, computerGraphics);
    }

    file.close();
}
void Admin::readCSVDr()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Dr.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string email, password, name, course1, code1, course2, code2, course3, code3, numOfCourses;

        getline(iss, email, delimiter);
        getline(iss, password, delimiter);
        getline(iss, name, delimiter);
        getline(iss, course1, delimiter);
        getline(iss, code1, delimiter);
        getline(iss, course2, delimiter);
        getline(iss, code2, delimiter);
        getline(iss, course3, delimiter);
        getline(iss, code3, delimiter);
        getline(iss, numOfCourses, delimiter);

        insertNodeDr(email, password, name, course1, code1, course2, code2, course3, code3, numOfCourses);
    }

    file.close();
}
void Admin::readCSVAdmin()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Admin.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string email, password, name;

        getline(iss, email, delimiter);
        getline(iss, password, delimiter);
        getline(iss, name, delimiter);

        insertNodeAdmin(email, password, name);
    }

    file.close();
}
void Admin::readCSVTA()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/TA.csv";
    char delimiter = ',';
    ifstream file(filename);
    if (!file.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    string line;
    int lineCount = 0;
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line))
    {
        lineCount++;
        istringstream iss(line);
        string gmail, password, name, course1, code1, course2, code2;
        string numOfCourses;

        getline(iss, gmail, delimiter);
        getline(iss, password, delimiter);
        getline(iss, name, delimiter);
        getline(iss, course1, delimiter);
        getline(iss, code1, delimiter);
        getline(iss, course2, delimiter);
        getline(iss, code2, delimiter);
        getline(iss, numOfCourses, delimiter);

        insertNodeTA(gmail, password, name, course1, code1, course2, code2, numOfCourses);
    }

    file.close();
}

void Admin::exportToCSVL1()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level1.csv";

    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "Email,Password,Rank,ID,Name,Group,GPA,Hours,Electronics,Linear Algebra,Programming,Discrete Math,Presentation,English" << endl;

    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        outputFile << tempL1->gmail << ','
                   << tempL1->password << ','
                   << tempL1->rank << ','
                   << tempL1->id << ','
                   << tempL1->name << ','
                   << tempL1->group << ','
                   << tempL1->gpa << ','
                   << tempL1->hours << ','
                   << tempL1->electronics << ','
                   << tempL1->linearAlgebra << ','
                   << tempL1->programming << ','
                   << tempL1->discreteMath << ','
                   << tempL1->presentation << ','
                   << tempL1->english << endl;

        tempL1 = tempL1->next;
    }
    outputFile.close();
}
void Admin::exportToCSVL2()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level2.csv";
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "Email,Password,Rank,ID,Name,Group,GPA,Hours,Event-Driven,Probability,Principles,Analysis,Data Communications,Information Systems" << endl;

    Student_nodeL2 *tempL2 = headL2;
    while (tempL2 != nullptr)
    {
        outputFile << tempL2->email << ','
                   << tempL2->password << ','
                   << tempL2->rank << ','
                   << tempL2->id << ','
                   << tempL2->name << ','
                   << tempL2->group << ','
                   << tempL2->gpa << ','
                   << tempL2->hours << ','
                   << tempL2->eventDriven << ','
                   << tempL2->probability << ','
                   << tempL2->principles << ','
                   << tempL2->analysis << ','
                   << tempL2->dataCommunications << ','
                   << tempL2->informationSystems << endl;

        tempL2 = tempL2->next;
    }

    outputFile.close();
}
void Admin::exportToCSVL3()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Level3.csv";
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "Email,Password,Rank,ID,Name,Group,GPA,Hours,System Modeling,Data Science Programming,Fault Tolerance,Introduction to Artificial Intelligence,Information and Networks Security,Computer Graphics" << endl;

    Student_nodeL3 *tempL3 = headL3;
    while (tempL3 != nullptr)
    {
        outputFile << tempL3->email << ','
                   << tempL3->password << ','
                   << tempL3->rank << ','
                   << tempL3->id << ','
                   << tempL3->name << ','
                   << tempL3->group << ','
                   << tempL3->gpa << ','
                   << tempL3->hours << ','
                   << tempL3->sysModeling << ','
                   << tempL3->dataProgramming << ','
                   << tempL3->faultTolerance << ','
                   << tempL3->aiIntro << ','
                   << tempL3->infoSecurity << ','
                   << tempL3->computerGraphics << endl;

        tempL3 = tempL3->next;
    }

    outputFile.close();
}
void Admin::exportToCSVDr()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Dr.csv";
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "gmail,password,name,Course01,Code,Course02,Code,Course03,Code,Num of Courses" << endl;

    DoctorNode *tempDr = headDr;
    while (tempDr != nullptr)
    {
        outputFile << tempDr->email << ',' << tempDr->password << ',' << tempDr->name << ','
                   << tempDr->course1 << ',' << tempDr->code1 << ',' << tempDr->course2 << ',' << tempDr->code2 << ','
                   << tempDr->course3 << ',' << tempDr->code3 << ',' << tempDr->numOfCourses << endl;

        tempDr = tempDr->next;
    }

    outputFile.close();
}
void Admin::exportToCSVAdmin()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/Admin.csv";
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "email,password,name" << endl;

    AdminNode *tempAdmin = headAdmin;
    while (tempAdmin != nullptr)
    {
        outputFile << tempAdmin->email << ',' << tempAdmin->password << ',' << tempAdmin->name << endl;

        tempAdmin = tempAdmin->next;
    }

    outputFile.close();
}
void Admin::exportToCSVTA()
{
    string filename = "./Source_Files/DataSet/Set_Here_Your_Work_DateSet/TA.csv";
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        system("color 04");
        cout << "\aError opening file " << filename << " for writing." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    outputFile << "gmail,password,name,course1,code1,course2,code2,numOfCourses" << endl;

    TANode *tempTA = headTA;
    while (tempTA != nullptr)
    {
        outputFile << tempTA->gmail << ',' << tempTA->password << ',' << tempTA->name << ','
                   << tempTA->course1 << ',' << tempTA->code1 << ',' << tempTA->course2 << ',' << tempTA->code2 << ','
                   << tempTA->numOfCourses << endl;

        tempTA = tempTA->next;
    }

    outputFile.close();
}

void Admin::insertNodeTA(string gmail, string password, string name, string course1, string code1, string course2, string code2, string numOfCourses)
{
    TANode *newNode = new TANode;
    newNode->gmail = gmail;
    newNode->password = password;
    newNode->name = name;
    newNode->course1 = course1;
    newNode->code1 = code1;
    newNode->course2 = course2;
    newNode->code2 = code2;
    newNode->numOfCourses = numOfCourses;
    newNode->next = nullptr;

    if (headTA == nullptr)
    {
        headTA = newNode;
    }
    else
    {
        TANode *tempTA = headTA;
        while (tempTA->next != nullptr)
        {
            tempTA = tempTA->next;
        }
        tempTA->next = newNode;
    }
}

void Admin::insertnodeL1(string gmail, string password, string rank, string id, string name, string group, string gpa,
                         string hours, string electronics, string linearAlgebra, string programming, string discreteMath,
                         string presentation, string english)
{
    Student_nodeL1 *new_node = new Student_nodeL1;
    new_node->gmail = gmail;
    new_node->password = password;
    new_node->rank = rank;
    new_node->id = id;
    new_node->name = name;
    new_node->group = group;
    new_node->gpa = gpa;
    new_node->hours = hours;
    new_node->electronics = electronics;
    new_node->linearAlgebra = linearAlgebra;
    new_node->programming = programming;
    new_node->discreteMath = discreteMath;
    new_node->presentation = presentation;
    new_node->english = english;
    new_node->next = nullptr;

    if (headL1 == nullptr)
    {
        headL1 = new_node;
    }
    else
    {
        Student_nodeL1 *tempL1 = headL1;
        while (tempL1->next != nullptr)
        {
            tempL1 = tempL1->next;
        }
        tempL1->next = new_node;
    }
}

void Admin::insertnodeL2(string email, string password, string rank, string id, string name, string group, string gpa,
                         string hours, string eventDriven, string probability, string principles, string analysis,
                         string dataCommunications, string informationSystems)
{
    Student_nodeL2 *new_node = new Student_nodeL2;
    new_node->email = email;
    new_node->password = password;
    new_node->rank = rank;
    new_node->id = id;
    new_node->name = name;
    new_node->group = group;
    new_node->gpa = gpa;
    new_node->hours = hours;
    new_node->eventDriven = eventDriven;
    new_node->probability = probability;
    new_node->principles = principles;
    new_node->analysis = analysis;
    new_node->dataCommunications = dataCommunications;
    new_node->informationSystems = informationSystems;
    new_node->next = nullptr;

    if (headL2 == nullptr)
    {
        headL2 = new_node;
    }
    else
    {
        Student_nodeL2 *tempL2 = headL2;
        while (tempL2->next != nullptr)
        {
            tempL2 = tempL2->next;
        }
        tempL2->next = new_node;
    }
}
void Admin::insertnodeL3(string email, string password, string rank, string id, string name, string group, string gpa,
                         string hours, string sysModeling, string dataProgramming, string faultTolerance,
                         string aiIntro, string infoSecurity, string computerGraphics)
{
    Student_nodeL3 *new_node = new Student_nodeL3;
    new_node->email = email;
    new_node->password = password;
    new_node->rank = rank;
    new_node->id = id;
    new_node->name = name;
    new_node->group = group;
    new_node->gpa = gpa;
    new_node->hours = hours;
    new_node->sysModeling = sysModeling;
    new_node->dataProgramming = dataProgramming;
    new_node->faultTolerance = faultTolerance;
    new_node->aiIntro = aiIntro;
    new_node->infoSecurity = infoSecurity;
    new_node->computerGraphics = computerGraphics;
    new_node->next = nullptr;

    if (headL3 == nullptr)
    {
        headL3 = new_node;
    }
    else
    {
        Student_nodeL3 *tempL3 = headL3;
        while (tempL3->next != nullptr)
        {
            tempL3 = tempL3->next;
        }
        tempL3->next = new_node;
    }
}
void Admin::insertNodeDr(string email, string password, string name,
                         string course1, string code1, string course2, string code2, string course3, string code3, string numOfCourses)
{
    DoctorNode *newNode = new DoctorNode;
    newNode->email = email;
    newNode->password = password;
    newNode->name = name;
    newNode->course1 = course1;
    newNode->code1 = code1;
    newNode->course2 = course2;
    newNode->code2 = code2;
    newNode->course3 = course3;
    newNode->code3 = code3;
    newNode->numOfCourses = numOfCourses;
    newNode->next = nullptr;

    if (headDr == nullptr)
    {
        headDr = newNode;
    }
    else
    {
        DoctorNode *tempDr = headDr;
        while (tempDr->next != nullptr)
        {
            tempDr = tempDr->next;
        }
        tempDr->next = newNode;
    }
}
void Admin::insertNodeAdmin(string email, string password, string name)
{
    AdminNode *newNode = new AdminNode;
    newNode->email = email;
    newNode->password = password;
    newNode->name = name;
    newNode->next = nullptr;

    if (headAdmin == nullptr)
    {
        headAdmin = newNode;
    }
    else
    {
        AdminNode *tempAdmin = headAdmin;
        while (tempAdmin->next != nullptr)
        {
            tempAdmin = tempAdmin->next;
        }
        tempAdmin->next = newNode;
    }
}

bool Admin::isDuplicateL1(string gmail, string id)
{
    Student_nodeL1 *current = headL1;
    while (current != nullptr)
    {
        if (current->gmail == gmail || current->id == id)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateL1(string gmail)
{
    Student_nodeL1 *current = headL1;
    while (current != nullptr)
    {
        if (current->gmail == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateL2(string gmail, string id)
{
    Student_nodeL2 *current = headL2;
    while (current != nullptr)
    {
        if (current->email == gmail || current->id == id)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateL2(string gmail)
{
    Student_nodeL2 *current = headL2;
    while (current != nullptr)
    {
        if (current->email == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateL3(string gmail, string id)
{
    Student_nodeL3 *current = headL3;
    while (current != nullptr)
    {
        if (current->email == gmail || current->id == id)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateL3(string gmail)
{
    Student_nodeL3 *current = headL3;
    while (current != nullptr)
    {
        if (current->email == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateDr(string gmail)
{
    DoctorNode *current = headDr;
    while (current != nullptr)
    {
        if (current->email == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateTA(string gmail)
{
    TANode *current = headTA;
    while (current != nullptr)
    {
        if (current->gmail == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
bool Admin::isDuplicateAdmin(string gmail)
{
    AdminNode *current = headAdmin;
    while (current != nullptr)
    {
        if (current->email == gmail)
        {
            return true; // Duplicate found
        }
        current = current->next;
    }
    return false; // No duplicate found
}
void Admin::AddStudentL1()
{
    string gmail, password, rank, id, name, group, gpa, hours, electronics, linearAlgebra, programming, discreteMath, presentation, english;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Student Details For Level 1 : " << endl;
    cout << "Gmail    : ";
    getline(cin, gmail);
    cout << "ID       : ";
    getline(cin, id);

    if (isDuplicateL1(gmail, id))
    {
        system("color 04");
        cout << "\aError: Gmail or ID already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Rank     : ";
    getline(cin, rank);
    cout << "Password : ";
    getline(cin, password);
    cout << "Name     : ";
    getline(cin, name);
    cout << "Group    : ";
    getline(cin, group);
    cout << "GPA      : ";
    getline(cin, gpa);
    cout << "Hours    : ";
    getline(cin, hours);
    cout << "Electronics     : ";
    getline(cin, electronics);
    cout << "Linear Algebra  : ";
    getline(cin, linearAlgebra);
    cout << "Programming     : ";
    getline(cin, programming);
    cout << "Discrete Math   : ";
    getline(cin, discreteMath);
    cout << "Presentation    : ";
    getline(cin, presentation);
    cout << "English         : ";
    getline(cin, english);

    insertnodeL1(gmail, password, rank, id, name, group, gpa, hours, electronics, linearAlgebra, programming, discreteMath, presentation, english);

    cout << endl;
    cout << "Student added to Level 1 successfully." << endl;
    system("pause");
    exportToCSVL1();
}
void Admin::AddStudentL2()
{
    // Get student information
    string email, password, rank, id, name, group, gpa, hours, eventDriven, probability, principles, analysis, dataCommunications, informationSystems;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Student Details For Level 2 : " << endl;
    cout << "Email       : ";
    getline(cin, email);
    cout << "ID          : ";
    getline(cin, id);

    if (isDuplicateL2(email, id))
    {
        system("color 04");
        cout << "\aError: Email or ID already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Password    : ";
    getline(cin, password);
    cout << "Name        : ";
    getline(cin, name);
    cout << "Rank        : ";
    getline(cin, rank);
    cout << "Group       : ";
    getline(cin, group);
    cout << "GPA         : ";
    getline(cin, gpa);
    cout << "Hours       : ";
    getline(cin, hours);
    cout << "Event-Driven Programming Languages  : ";
    getline(cin, eventDriven);
    cout << "Probability and Statistics          : ";
    getline(cin, probability);
    cout << "Principles of Programming Languages : ";
    getline(cin, principles);
    cout << "Analysis and Design of Algorithms   : ";
    getline(cin, analysis);
    cout << "Data Communications                 : ";
    getline(cin, dataCommunications);
    cout << "Information Systems                 : ";
    getline(cin, informationSystems);

    insertnodeL2(email, password, rank, id, name, group, gpa, hours, eventDriven, probability, principles, analysis, dataCommunications, informationSystems);

    cout << endl;
    cout << "Student added to Level 2 successfully." << endl;
    system("pause");
    // Export the updated data to Level2.csv
    exportToCSVL2();
}
void Admin::AddStudentL3()
{
    // Get student information
    string email, password, rank, id, name, group, gpa, hours, sysModeling, dataProgramming, faultTolerance, aiIntro, infoSecurity, computerGraphics;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Student Details For Level 3 : " << endl;
    cout << "Email    : ";
    getline(cin, email);
    cout << "ID       : ";
    getline(cin, id);

    if (isDuplicateL3(email, id))
    {
        system("color 04");
        cout << "\aError: Email or ID already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Rank     : ";
    getline(cin, rank);
    cout << "Password : ";
    getline(cin, password);
    cout << "Name     : ";
    getline(cin, name);
    cout << "Group    : ";
    getline(cin, group);
    cout << "GPA      : ";
    getline(cin, gpa);
    cout << "Hours    : ";
    getline(cin, hours);
    cout << "System Modeling      : ";
    getline(cin, sysModeling);
    cout << "Data Programming     : ";
    getline(cin, dataProgramming);
    cout << "Fault Tolerance      : ";
    getline(cin, faultTolerance);
    cout << "AI Introduction      : ";
    getline(cin, aiIntro);
    cout << "Information Security : ";
    getline(cin, infoSecurity);
    cout << "Computer Graphics    : ";
    getline(cin, computerGraphics);

    insertnodeL3(email, password, rank, id, name, group, gpa, hours, sysModeling, dataProgramming, faultTolerance, aiIntro, infoSecurity, computerGraphics);

    cout << endl;
    cout << "Student added to Level 3 successfully." << endl;
    system("pause");
    // Export the updated data to Level3.csv
    exportToCSVL3();
}
void Admin::AddDr()
{
    // Get Doctor information
    string email, password, name, course1, code1, course2, code2, course3, code3, numOfCourses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Doctor Details :" << endl;
    cout << "Email          : ";
    getline(cin, email);

    if (isDuplicateDr(email))
    {
        system("color 04");
        cout << "\aError: Email already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Password       : ";
    getline(cin, password);
    cout << "Name           : ";
    getline(cin, name);
    cout << "Course 1       : ";
    getline(cin, course1);
    cout << "Code 1         : ";
    getline(cin, code1);
    cout << "Course 2       : ";
    getline(cin, course2);
    cout << "Code 2         : ";
    getline(cin, code2);
    cout << "Course 3       : ";
    getline(cin, course3);
    cout << "Code 3         : ";
    getline(cin, code3);
    cout << "Num of Courses : ";
    getline(cin, numOfCourses);

    insertNodeDr(email, password, name, course1, code1, course2, code2, course3, code3, numOfCourses);

    cout << endl;
    cout << "Doctor added successfully." << endl;
    system("pause");
    // Export the updated data to Doctor.csv
    exportToCSVDr();
}
void Admin::AddTA()
{
    // Get TA information
    string gmail, password, name, course1, code1, course2, code2, numOfCourses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter TA Details :" << endl;
    cout << "Gmail          : ";
    getline(cin, gmail);

    if (isDuplicateTA(gmail))
    {
        system("color 04");
        cout << "\aError: Gmail already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Password       : ";
    getline(cin, password);
    cout << "Name           : ";
    getline(cin, name);
    cout << "Course 1       : ";
    getline(cin, course1);
    cout << "Code 1         : ";
    getline(cin, code1);
    cout << "Course 2       : ";
    getline(cin, course2);
    cout << "Code 2         : ";
    getline(cin, code2);
    cout << "Num of Courses : ";
    getline(cin, numOfCourses);

    insertNodeTA(gmail, password, name, course1, code1, course2, code2, numOfCourses);

    cout << endl;
    cout << "TA added successfully." << endl;
    system("pause");
    // Export the updated data to TA.csv
    exportToCSVTA();
}
void Admin::AddAdmin()
{
    // Get Admin information
    string email, password, name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Admin Details : " << endl;
    cout << "Email     : ";
    getline(cin, email);

    if (isDuplicateAdmin(email))
    {
        system("color 04");
        cout << "\aError: Email already exists in the linked list. Cannot add duplicate." << endl;
        system("pause");
        system("color 07");
        system("cls");
        return;
    }

    cout << "Password  : ";
    getline(cin, password);
    cout << "Name      : ";
    getline(cin, name);

    insertNodeAdmin(email, password, name);

    cout << endl;
    cout << "Admin added successfully." << endl;
    system("pause");
    // Export the updated data to Admin.csv
    exportToCSVAdmin();
}

void Admin::editNodeL1()
{
    string id;
    cout << "Enter The ID Of The Node You Want To Edit Level 1 : ";
    cin >> id;

    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        if (tempL1->id == id)
        {
            cout << "Current Data    :" << endl;
            cout << "Gmail           : " << tempL1->gmail << endl;
            cout << "Password        : " << tempL1->password << endl;
            cout << "Name            : " << tempL1->name << endl;
            cout << "Rank            : " << tempL1->rank << endl;
            cout << "ID              : " << tempL1->id << endl;
            cout << "Group           : " << tempL1->group << endl;
            cout << "GPA             : " << tempL1->gpa << endl;
            cout << "Hours           : " << tempL1->hours << endl;
            cout << "Electronics     : " << tempL1->electronics << endl;
            cout << "Linear Algebra  : " << tempL1->linearAlgebra << endl;
            cout << "Programming     : " << tempL1->programming << endl;
            cout << "Discrete Math   : " << tempL1->discreteMath << endl;
            cout << "Presentation    : " << tempL1->presentation << endl;
            cout << "English         : " << tempL1->english << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            // Allow the user to edit all fields except the ID
            cout << "Enter new data  : " << endl;
            cout << "Gmail           : ";
            getline(cin, tempL1->gmail);
            if (isDuplicateL1(tempL1->gmail))
            {
                system("color 04");
                cout << "\aError: Gmail or ID already exists in the linked list. Cannot add duplicate." << endl;
                system("pause");
                system("color 07");
                system("cls");
                return;
            }
            cout << "Password        : ";
            getline(cin, tempL1->password);
            cout << "Name            : ";
            getline(cin, tempL1->name);
            cout << "Rank            : ";
            getline(cin, tempL1->rank);
            // !! Don't allow editing the ID @0xMoataz
            cout << "Group           : ";
            getline(cin, tempL1->group);
            cout << "GPA             : ";
            getline(cin, tempL1->gpa);
            cout << "Hours           : ";
            getline(cin, tempL1->hours);
            cout << "Electronics     : ";
            getline(cin, tempL1->electronics);
            cout << "Linear Algebra  : ";
            getline(cin, tempL1->linearAlgebra);
            cout << "Programming     : ";
            getline(cin, tempL1->programming);
            cout << "Discrete Math   : ";
            getline(cin, tempL1->discreteMath);
            cout << "Presentation    : ";
            getline(cin, tempL1->presentation);
            cout << "English         : ";
            getline(cin, tempL1->english);
            cout << endl;
            exportToCSVL1();
            cout << "Node with ID " << id << " updated successfully." << endl;
            system("pause");
            return;
        }
        tempL1 = tempL1->next;
    }
    system("color 04");
    cout << "\aNode with ID " << id << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}
void Admin::editNodeL2()
{
    string id;
    cout << "Enter The ID Of The Node You Want To Edit Level 2 : ";
    cin >> id;

    Student_nodeL2 *tempL2 = headL2; // Assuming headL2 is the head for Level 2
    while (tempL2 != nullptr)
    {
        if (tempL2->id == id)
        {
            // Display current data
            cout << "Current Data    :" << endl;
            cout << "Email           : " << tempL2->email << endl;
            cout << "Password        : " << tempL2->password << endl;
            cout << "Name            : " << tempL2->name << endl;
            cout << "Rank            : " << tempL2->rank << endl;
            cout << "ID              : " << tempL2->id << endl;
            cout << "Group           : " << tempL2->group << endl;
            cout << "GPA             : " << tempL2->gpa << endl;
            cout << "Hours           : " << tempL2->hours << endl;
            cout << "Event-Driven Programming Languages  : " << tempL2->eventDriven << endl;
            cout << "Probability and Statistics          : " << tempL2->probability << endl;
            cout << "Principles of Programming Languages : " << tempL2->principles << endl;
            cout << "Analysis and Design of Algorithms   : " << tempL2->analysis << endl;
            cout << "Data Communications                 : " << tempL2->dataCommunications << endl;
            cout << "Information Systems                 : " << tempL2->informationSystems << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            // Allow the user to edit all fields except the ID
            cout << "Enter new data  : " << endl;
            cout << "Email           : ";
            if (isDuplicateL2(tempL2->email))
            {
                system("color 04");
                cout << "\aError: Gmail or ID already exists in the linked list. Cannot add duplicate." << endl;
                system("pause");
                system("color 07");
                system("cls");
                return;
            }
            getline(cin, tempL2->email);
            cout << "Password        : ";
            getline(cin, tempL2->password);
            cout << "Name            : ";
            getline(cin, tempL2->name);
            cout << "Rank            : ";
            getline(cin, tempL2->rank);
            // !! Don't allow editing the ID
            cout << "Group           : ";
            getline(cin, tempL2->group);
            cout << "GPA             : ";
            getline(cin, tempL2->gpa);
            cout << "Hours           : ";
            getline(cin, tempL2->hours);
            cout << "Event-Driven Programming Languages  : ";
            getline(cin, tempL2->eventDriven);
            cout << "Probability and Statistics          : ";
            getline(cin, tempL2->probability);
            cout << "Principles of Programming Languages : ";
            getline(cin, tempL2->principles);
            cout << "Analysis and Design of Algorithms   : ";
            getline(cin, tempL2->analysis);
            cout << "Data Communications                 : ";
            getline(cin, tempL2->dataCommunications);
            cout << "Information Systems                 : ";
            getline(cin, tempL2->informationSystems);
            cout << endl;
            exportToCSVL2();
            cout << "Node with ID " << id << " updated successfully." << endl;
            system("pause");
            return;
        }
        tempL2 = tempL2->next;
    }

    system("color 04");
    cout << "\aNode with ID " << id << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}
void Admin::editNodeL3()
{
    string id;
    cout << "Enter The ID Of The Node You Want To Edit Level 3 : ";
    cin >> id;

    Student_nodeL3 *tempL3 = headL3;
    while (tempL3 != nullptr)
    {
        if (tempL3->id == id)
        {
            cout << "Current Data     :" << endl;
            cout << "Email            : " << tempL3->email << endl;
            cout << "Password         : " << tempL3->password << endl;
            cout << "Name             : " << tempL3->name << endl;
            cout << "Rank             : " << tempL3->rank << endl;
            cout << "ID               : " << tempL3->id << endl;
            cout << "Group            : " << tempL3->group << endl;
            cout << "GPA              : " << tempL3->gpa << endl;
            cout << "Hours            : " << tempL3->hours << endl;
            cout << "System Modeling          : " << tempL3->sysModeling << endl;
            cout << "Data Science Programming : " << tempL3->dataProgramming << endl;
            cout << "Fault Tolerance          : " << tempL3->faultTolerance << endl;
            cout << "Introduction to AI       : " << tempL3->aiIntro << endl;
            cout << "Information Security     : " << tempL3->infoSecurity << endl;
            cout << "Computer Graphics        : " << tempL3->computerGraphics << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            cout << "Enter new data   :" << endl;
            cout << "Email            : ";
            getline(cin, tempL3->email);
            if (isDuplicateL2(tempL3->email))
            {
                system("color 04");
                cout << "\aError: Gmail or ID already exists in the linked list. Cannot add duplicate." << endl;
                system("pause");
                system("color 07");
                system("cls");
                return;
            }
            cout << "Password         : ";
            getline(cin, tempL3->password);
            cout << "Name             : ";
            getline(cin, tempL3->name);
            cout << "Rank             : ";
            getline(cin, tempL3->rank);
            // !! Don't allow editing the ID
            cout << "Group            : ";
            getline(cin, tempL3->group);
            cout << "GPA              : ";
            getline(cin, tempL3->gpa);
            cout << "Hours            : ";
            getline(cin, tempL3->hours);
            cout << "System Modeling          : ";
            getline(cin, tempL3->sysModeling);
            cout << "Data Science Programming : ";
            getline(cin, tempL3->dataProgramming);
            cout << "Fault Tolerance          : ";
            getline(cin, tempL3->faultTolerance);
            cout << "Introduction to AI       : ";
            getline(cin, tempL3->aiIntro);
            cout << "Information Security     : ";
            getline(cin, tempL3->infoSecurity);
            cout << "Computer Graphics        : ";
            getline(cin, tempL3->computerGraphics);
            cout << endl;
            exportToCSVL3();
            cout << "Node with ID " << id << " updated successfully." << endl;
            system("pause");
            return;
        }
        tempL3 = tempL3->next;
    }

    system("color 04");
    cout << "\aNode with ID " << id << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}
void Admin::editNodeDr()
{
    string email;
    cout << "Enter the email of the doctor you want to edit: ";
    cin >> email;

    DoctorNode *tempDr = headDr;
    while (tempDr != nullptr)
    {
        if (tempDr->email == email)
        {
            // Display the current data
            cout << "Current Data:" << endl;
            cout << "Email    : " << tempDr->email << endl;
            cout << "Password : " << tempDr->password << endl;
            cout << "Name     : " << tempDr->name << endl;
            cout << "Course 1 : " << tempDr->course1 << endl;
            cout << "Code 1   : " << tempDr->code1 << endl;
            cout << "Course 2 : " << tempDr->course2 << endl;
            cout << "Code 2   : " << tempDr->code2 << endl;
            cout << "Course 3 : " << tempDr->course3 << endl;
            cout << "Code 3   : " << tempDr->code3 << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            // Allow the user to edit each field
            cout << "Enter new data:" << endl;
            cout << "Password: ";
            getline(cin, tempDr->password);
            cout << "Name: ";
            getline(cin, tempDr->name);
            cout << "Course 1: ";
            getline(cin, tempDr->course1);
            cout << "Code 1: ";
            getline(cin, tempDr->code1);
            cout << "Course 2: ";
            getline(cin, tempDr->course2);
            cout << "Code 2: ";
            cin >> tempDr->code2;
            cout << "Course 3: ";
            getline(cin, tempDr->course3);
            cout << "Code 3: ";
            getline(cin, tempDr->code3);
            cout << "Num of Courses: ";
            getline(cin, tempDr->numOfCourses);
            cout << endl;
            cout << "Doctor with email " << email << " updated successfully." << endl;
            exportToCSVDr(); // Export the updated data to doctors.csv
            system("pause");
            return;
        }
        tempDr = tempDr->next;
    }

    system("color 04");
    cout << "\aDoctor with email " << email << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}
void Admin::editNodeAdmin()
{
    string email;
    cout << "Enter The Email Of The Node You Want To Edit : ";
    cin >> email;

    AdminNode *tempAdmin = headAdmin;
    while (tempAdmin != nullptr)
    {
        if (tempAdmin->email == email)
        {
            // Display the current data
            cout << "Current Data :" << endl;
            cout << "Email        : " << tempAdmin->email << endl;
            cout << "Password     : " << tempAdmin->password << endl;
            cout << "Name         : " << tempAdmin->name << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            // Allow the user to edit each field
            cout << "Enter new data :" << endl;
            cout << "Email    : ";
            getline(cin, tempAdmin->email);
            cout << "Password : ";
            getline(cin, tempAdmin->password);
            cout << "Name     : ";
            getline(cin, tempAdmin->name);
            cout << endl;
            cout << "Admin with email " << email << " updated successfully." << endl;
            exportToCSVAdmin(); // Export the updated data to admins.csv
            system("pause");
            return;
        }
        tempAdmin = tempAdmin->next;
    }
    system("color 04");
    cout << "\aAdmin with email " << email << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}
void Admin::editNodeTA()
{
    string gmail;
    cout << "Enter the gmail of the TA you want to edit: ";
    cin >> gmail;

    TANode *tempTA = headTA;
    while (tempTA != nullptr)
    {
        if (tempTA->gmail == gmail)
        {
            cout << "Current Data  :" << endl;
            cout << "Email         : " << tempTA->gmail << endl;
            cout << "Password      : " << tempTA->password << endl;
            cout << "Name          : " << tempTA->name << endl;
            cout << "Course 1      : " << tempTA->course1 << endl;
            cout << "Code 1        : " << tempTA->code1 << endl;
            cout << "Course 2      : " << tempTA->course2 << endl;
            cout << "Code 2        : " << tempTA->code2 << endl;
            cout << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            // Allow the user to edit each field
            cout << "Enter new data:" << endl;
            cout << "Password        : ";
            cin >> tempTA->password;
            cout << "Name            : ";
            getline(cin, tempTA->name);
            cout << "Course 1        : ";
            getline(cin, tempTA->course1);
            cout << "Code 1          : ";
            getline(cin, tempTA->code1);
            cout << "Course 2        : ";
            getline(cin, tempTA->course2);
            cout << "Code 2          : ";
            getline(cin, tempTA->code2);
            cout << "Num of Courses  : ";
            getline(cin, tempTA->numOfCourses);
            cout << endl;
            cout << "TA with gmail " << gmail << " updated successfully." << endl;
            exportToCSVTA(); // Export the updated data to tas.csv
            system("pause");

            return;
        }
        tempTA = tempTA->next;
    }

    system("color 04");
    cout << "\aTA with gmail " << gmail << " not found." << endl;
    sleep(2);
    system("color 07");
    system("pause");
}

void Admin::deleteL1()
{
    string id;
    cout << "Enter The ID Of The Student You Want To Delete : ";
    cin >> id;
    if (headL1 == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Student_nodeL1 *tempL1 = headL1;
    Student_nodeL1 *prevL1 = nullptr;

    if (tempL1 != nullptr && tempL1->id == id)
    {
        headL1 = tempL1->next;
        delete tempL1;
        exportToCSVL1();
        cout << "Node with ID " << id << " deleted successfully." << endl;
    }
    else
    {
        while (tempL1 != nullptr && tempL1->id != id)
        {
            prevL1 = tempL1;
            tempL1 = tempL1->next;
        }
        if (tempL1 == nullptr)
        {
            system("color 04");
            cout << "\aNode with ID " << id << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {

            prevL1->next = tempL1->next;
            delete tempL1;
            exportToCSVL1();
            cout << "Node with ID " << id << " deleted successfully." << endl;
        }
    }
    exportToCSVL1();
    system("pause");
}
void Admin::deleteL2()
{
    string id;
    cout << "Enter The ID Of The Student You Want To Delete : ";
    cin >> id;
    if (headL2 == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Student_nodeL2 *tempL2 = headL2;
    Student_nodeL2 *prevL2 = nullptr;

    if (tempL2 != nullptr && tempL2->id == id)
    {
        headL2 = tempL2->next;
        delete tempL2;
        exportToCSVL2();
        cout << "Node with ID " << id << " deleted successfully." << endl;
    }
    else
    {

        while (tempL2 != nullptr && tempL2->id != id)
        {
            prevL2 = tempL2;
            tempL2 = tempL2->next;
        }
        if (tempL2 == nullptr)
        {
            system("color 04");
            cout << "\aNode with ID " << id << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {
            prevL2->next = tempL2->next;
            delete tempL2;
            exportToCSVL2();
            cout << "Node with ID " << id << " deleted successfully." << endl;
        }
    }
    exportToCSVL2();
    system("pause");
}
void Admin::deleteL3()
{
    string id;
    cout << "Enter The ID Of The Student You Want To Delete : ";
    cin >> id;
    if (headL3 == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Student_nodeL3 *tempL3 = headL3;
    Student_nodeL3 *prev = nullptr;

    if (tempL3 != nullptr && tempL3->id == id)
    {
        headL3 = tempL3->next;
        delete tempL3;
        exportToCSVL3();

        cout << "Node with ID " << id << " deleted successfully." << endl;
    }
    else
    {
        while (tempL3 != nullptr && tempL3->id != id)
        {
            prev = tempL3;
            tempL3 = tempL3->next;
        }
        if (tempL3 == nullptr)
        {
            system("color 04");
            cout << "\aNode with ID " << id << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {
            prev->next = tempL3->next;
            delete tempL3;
            exportToCSVL3();

            cout << "Node with ID " << id << " deleted successfully." << endl;
        }
    }
    exportToCSVL3();
    system("pause");
}
void Admin::deleteDr()
{
    string email;
    cout << "Enter The Email Of The Doctor You Want To Delete : ";
    cin >> email;

    if (headDr == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    DoctorNode *tempDr = headDr;
    DoctorNode *prev = nullptr;

    if (tempDr != nullptr && tempDr->email == email)
    {
        headDr = tempDr->next;
        delete tempDr;
        exportToCSVDr();

        cout << "Doctor with email " << email << " deleted successfully." << endl;
    }
    else
    {

        while (tempDr != nullptr && tempDr->email != email)
        {
            prev = tempDr;
            tempDr = tempDr->next;
        }
        if (tempDr == nullptr)
        {
            system("color 04");
            cout << "\aDoctor with email " << email << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {
            prev->next = tempDr->next;
            delete tempDr;
            cout << "Doctor with email " << email << " deleted successfully." << endl;

            exportToCSVDr();
        }
    }
    exportToCSVDr();
    system("pause");
}
void Admin::deleteAdmin()
{
    string email;
    cout << "Enter the email of the admin you want to delete: ";
    cin >> email;

    if (headAdmin == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    AdminNode *tempAdmin = headAdmin;
    AdminNode *prev = nullptr;

    if (tempAdmin != nullptr && tempAdmin->email == email)
    {
        headAdmin = tempAdmin->next;
        delete tempAdmin;
        exportToCSVAdmin();
        cout << "Admin with email " << email << " deleted successfully." << endl;
    }
    else
    {

        while (tempAdmin != nullptr && tempAdmin->email != email)
        {
            prev = tempAdmin;
            tempAdmin = tempAdmin->next;
        }
        if (tempAdmin == nullptr)
        {
            system("color 04");
            cout << "\aAdmin with email " << email << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {
            prev->next = tempAdmin->next;
            delete tempAdmin;
            exportToCSVAdmin();
            cout << "Admin with email " << email << " deleted successfully." << endl;
        }
    }
    exportToCSVAdmin();
    system("pause");
}
void Admin::deleteTA()
{
    string gmail;
    cout << "Enter The Email Of The TA You Want To Delete : ";
    cin >> gmail;

    if (headTA == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    TANode *tempTA = headTA;
    TANode *prev = nullptr;

    if (tempTA != nullptr && tempTA->gmail == gmail)
    {
        headTA = tempTA->next;
        delete tempTA;
        exportToCSVTA();
        cout << "TA with gmail " << gmail << " deleted successfully." << endl;
    }
    else
    {

        while (tempTA != nullptr && tempTA->gmail != gmail)
        {
            prev = tempTA;
            tempTA = tempTA->next;
        }
        if (tempTA == nullptr)
        {
            system("color 04");
            cout << "\aTA with gmail " << gmail << " not found." << endl;
            sleep(2);
            system("color 07");
        }
        else
        {
            prev->next = tempTA->next;
            delete tempTA;
            cout << "TA with gmail " << gmail << " deleted successfully." << endl;

            exportToCSVTA();
        }
    }
    exportToCSVTA();
    system("pause");
}
void Admin::displayL1()
{
    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        tempL1 = tempL1->next;
    }

    // Print table headers with adjusted widths and alignments
    cout << left
         << setw(25) << "Gmail"
         << setw(15) << "Password"
         << setw(8) << "Rank"
         << setw(15) << "ID"
         << setw(30) << "Name"
         << setw(6) << "Group"
         << setw(6) << "GPA"
         << setw(8) << "Hours"
         << setw(12) << "Electronics"
         << setw(15) << "Linear Algebra"
         << setw(15) << "Programming"
         << setw(15) << "Discrete Math"
         << setw(15) << "Presentation"
         << setw(12) << "English" << endl;

    // Iterate through the linked list of Student_nodeL1 objects
    tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        // Print each student's details in columns with appropriate widths
        cout << left
             << setw(25) << tempL1->gmail
             << setw(15) << tempL1->password
             << setw(8) << tempL1->rank
             << setw(15) << tempL1->id
             << setw(30) << tempL1->name
             << setw(6) << tempL1->group
             << setw(6) << tempL1->gpa
             << setw(8) << tempL1->hours
             << setw(12) << tempL1->electronics
             << setw(15) << tempL1->linearAlgebra
             << setw(15) << tempL1->programming
             << setw(15) << tempL1->discreteMath
             << setw(15) << tempL1->presentation
             << setw(12) << tempL1->english << endl;

        // Move to the next student node in the linked list
        tempL1 = tempL1->next;
    }
}

void Admin::displayL2()
{
    // Print table headers with adjusted widths and alignments
    cout << left
         << setw(25) << "Email"
         << setw(15) << "Password"
         << setw(8) << "Rank"
         << setw(15) << "ID"
         << setw(30) << "Name"
         << setw(6) << "Group"
         << setw(6) << "GPA"
         << setw(8) << "Hours"
         << setw(20) << "Event-Driven"
         << setw(25) << "Probability & Statistics"
         << setw(20) << "Principles"
         << setw(12) << "Algorithms"
         << setw(25) << "Data Communications"
         << setw(20) << "Information Systems" << endl;

    // Iterate through the linked list of Student_nodeL2 objects
    Student_nodeL2 *tempL2 = headL2;
    while (tempL2 != nullptr)
    {
        // Print each student's details in columns with appropriate widths
        cout << left
             << setw(25) << tempL2->email
             << setw(15) << tempL2->password
             << setw(8) << tempL2->rank
             << setw(15) << tempL2->id
             << setw(30) << tempL2->name
             << setw(6) << tempL2->group
             << setw(6) << tempL2->gpa
             << setw(8) << tempL2->hours
             << setw(20) << tempL2->eventDriven
             << setw(25) << tempL2->probability
             << setw(20) << tempL2->principles
             << setw(12) << tempL2->analysis
             << setw(25) << tempL2->dataCommunications
             << setw(20) << tempL2->informationSystems << endl;

        // Move to the next student node in the linked list
        tempL2 = tempL2->next;
    }
}

void Admin::displayL3()
{
    // Print table headers with adjusted widths and alignments
    cout << left
         << setw(25) << "Email"
         << setw(15) << "Password"
         << setw(8) << "Rank"
         << setw(15) << "ID"
         << setw(30) << "Name"
         << setw(8) << "Group"
         << setw(8) << "GPA"
         << setw(10) << "Hours"
         << setw(20) << "System Modeling"
         << setw(25) << "Data Science Programming"
         << setw(20) << "Fault Tolerance"
         << setw(30) << "AI Introduction"
         << setw(25) << "Networks Security"
         << setw(15) << "Graphics" << endl;

    // Iterate through the linked list of Student_nodeL3 objects
    Student_nodeL3 *tempL3 = headL3;
    while (tempL3 != nullptr)
    {
        // Print each student's details in columns with appropriate widths and alignments
        cout << left
             << setw(25) << tempL3->email
             << setw(15) << tempL3->password
             << setw(8) << tempL3->rank
             << setw(15) << tempL3->id
             << setw(30) << tempL3->name
             << setw(8) << tempL3->group
             << setw(8) << tempL3->gpa
             << setw(10) << tempL3->hours
             << setw(20) << tempL3->sysModeling
             << setw(25) << tempL3->dataProgramming
             << setw(20) << tempL3->faultTolerance
             << setw(30) << tempL3->aiIntro
             << setw(25) << tempL3->infoSecurity
             << setw(15) << tempL3->computerGraphics
             << endl;

        // Move to the next student node in the linked list
        tempL3 = tempL3->next;
    }
}
void Admin::displayDr()
{
    // Print the headers with consistent width and alignment
    cout << left
         << setw(35) << "Email"
         << setw(20) << "Password"
         << setw(30) << "Name"
         << setw(40) << "Course 1"
         << setw(10) << "Code 1"
         << setw(40) << "Course 2"
         << setw(10) << "Code 2"
         << setw(40) << "Course 3"
         << setw(10) << "Code 3"
         << setw(15) << "Num of Courses"
         << endl;

    // Iterate through the linked list of DoctorNode objects
    DoctorNode *tempDr = headDr;
    while (tempDr != nullptr)
    {
        // Print the data for each doctor with consistent column widths
        cout << left
             << setw(35) << tempDr->email
             << setw(20) << tempDr->password
             << setw(30) << tempDr->name;

        if (tempDr->course1 != "NULL")
        {
            cout << setw(40) << tempDr->course1
                 << setw(10) << tempDr->code1;
        }
        else
        {
            cout << setw(50) << "";
        }

        if (tempDr->course2 != "NULL")
        {
            cout << setw(40) << tempDr->course2
                 << setw(10) << tempDr->code2;
        }
        else
        {
            cout << setw(50) << "";
        }

        if (tempDr->course3 != "NULL")
        {
            cout << setw(40) << tempDr->course3
                 << setw(10) << tempDr->code3;
        }
        else
        {
            cout << setw(50) << "";
        }
        cout << setw(15) << tempDr->numOfCourses << endl;
        tempDr = tempDr->next;
    }
}
void Admin::displayTA()
{

    cout << left
         << setw(40) << "email"
         << setw(15) << "Password"
         << setw(25) << "Name"
         << setw(40) << "Course 1"
         << setw(10) << "Code 1"
         << setw(40) << "Course 2"
         << setw(10) << "Code 2"
         << setw(15) << "Num of Courses" << endl;

    TANode *tempTA = headTA;
    while (tempTA != nullptr)
    {
        cout << left
             << setw(40) << tempTA->gmail
             << setw(15) << tempTA->password
             << setw(25) << tempTA->name;

        if (tempTA->course1 != "NULL")
        {
            cout << setw(40) << tempTA->course1
                 << setw(10) << tempTA->code1;
        }
        else
        {
            cout << setw(50) << "";
        }

        if (tempTA->course2 != "NULL")
        {
            cout << setw(40) << tempTA->course2
                 << setw(10) << tempTA->code2;
        }
        else
        {
            cout << setw(50) << "";
        }

        cout << setw(15) << tempTA->numOfCourses << endl;

        tempTA = tempTA->next;
    }
}

void Admin::displayAdmin()
{
    cout << setw(30) << "Email" << setw(15) << "Password" << setw(15) << "Name" << endl;

    AdminNode *tempAdmin = headAdmin;
    while (tempAdmin != nullptr)
    {
        cout << setw(30) << tempAdmin->email << setw(15) << tempAdmin->password << setw(15) << tempAdmin->name << endl;

        tempAdmin = tempAdmin->next;
    }
}
void Admin::searchAdmin()
{
    string searchEmail;
    cout << "Enter The Email Of The Admin You Want To Search : ";
    cin >> searchEmail;

    AdminNode *tempAdmin = headAdmin;
    while (tempAdmin != nullptr)
    {
        if (tempAdmin->email == searchEmail)
        {
            // Display Admin information
            cout << ">> Admin Found" << endl;
            cout << "Name        : " << tempAdmin->name << endl;
            cout << "Email       : " << tempAdmin->email << endl;
            cout << "Password    : " << tempAdmin->password << endl;
            return;
        }
        tempAdmin = tempAdmin->next;
    }
    system("color 04");
    cout << "\aAdmin with email " << searchEmail << " not found." << endl;
    sleep(2);
    system("color 07");
}
void Admin::searchDr()
{
    string searchEmail;
    cout << "Enter The Email Of The Doctor You Want To Search: ";
    cin >> searchEmail;

    DoctorNode *tempDr = headDr;
    while (tempDr != nullptr)
    {
        if (tempDr->email == searchEmail)
        {
            // Display Doctor information
            cout << ">> Doctor Found" << endl;
            cout << "Name           : " << tempDr->name << endl;
            cout << "Email          : " << tempDr->email << endl;
            cout << "Password       : " << tempDr->password << endl;
            // Add more fields based on your data structure

            cout << ">> Course Enrollment" << endl;
            if (tempDr->course1 != "NULL")
                cout << "[1] " << setw(40) << left << tempDr->course1 << setw(10) << right << tempDr->code1 << endl;
            if (tempDr->course2 != "NULL")
                cout << "[2] " << setw(40) << left << tempDr->course2 << setw(10) << right << tempDr->code2 << endl;
            if (tempDr->course3 != "NULL")
                cout << "[3] " << setw(40) << left << tempDr->course3 << setw(10) << right << tempDr->code3 << endl;
            return;
        }
        tempDr = tempDr->next;
    }
    system("color 04");
    cout << "\aDoctor with email " << searchEmail << " not found." << endl;
    sleep(2);
    system("color 07");
}
void Admin::searchTA()
{
    string searchGmail;
    cout << "Enter The Gmail Of The TA You Want To Search: ";
    cin >> searchGmail;

    TANode *tempTA = headTA;
    while (tempTA != nullptr)
    {
        if (tempTA->gmail == searchGmail)
        {
            cout << ">> TA Found" << endl;
            cout << "Name       : " << tempTA->name << endl;
            cout << "Gmail      : " << tempTA->gmail << endl;
            cout << "Password   : " << tempTA->password << endl;

            cout << ">> Course Enrollment" << endl;
            if (tempTA->course1 != "NULL")
                cout << "[1] " << setw(40) << left << tempTA->course1 << setw(10) << right << tempTA->code1 << endl;
            if (tempTA->course2 != "NULL")
                cout << "[2] " << setw(40) << left << tempTA->course2 << setw(10) << right << tempTA->code2 << endl;
            return;
        }
        tempTA = tempTA->next;
    }
    system("color 04");
    cout << "\aTA with gmail " << searchGmail << " not found." << endl;
    sleep(2);
    system("color 07");
}
void Admin::searchL1()
{
    string searchID;
    cout << "Enter The ID Of The L1 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        if (tempL1->id == searchID)
        {
            cout << ">> L1 Student Found" << endl;
            cout << "Name       : " << tempL1->name << endl;
            cout << "Gmail      : " << tempL1->gmail << endl;
            cout << "Password   : " << tempL1->password << endl;
            cout << "Rank       : " << tempL1->rank << endl;
            cout << "ID         : " << tempL1->id << endl;
            cout << "Group      : " << tempL1->group << endl;
            cout << "GPA        : " << tempL1->gpa << endl;
            cout << "Hours      : " << tempL1->hours << endl;
            cout << endl;
            cout << ">> Course Enrollment" << endl;
            if (tempL1->electronics != "NO R")
                cout << "Electronics    : " << tempL1->electronics << endl;
            if (tempL1->linearAlgebra != "NO R")
                cout << "Linear Algebra : " << tempL1->linearAlgebra << endl;
            if (tempL1->programming != "NO R")
                cout << "Programming    : " << tempL1->programming << endl;
            if (tempL1->discreteMath != "NO R")
                cout << "Discrete Math  : " << tempL1->discreteMath << endl;
            if (tempL1->presentation != "NO R")
                cout << "Presentation   : " << tempL1->presentation << endl;
            if (tempL1->english != "NO R")
                cout << "English        : " << tempL1->english << endl;
            return;
        }
        tempL1 = tempL1->next;
    }

    system("color 04");
    cout << "\aL1 Student with ID " << searchID << " not found." << endl;
    sleep(2);
    system("color 07");
}
void Admin::searchL2()
{
    string searchID;
    cout << "Enter The ID Of The L2 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL2 *tempL2 = headL2;
    while (tempL2 != nullptr)
    {
        if (tempL2->id == searchID)
        {
            // Display L2 student information
            cout << ">> L2 Student Found:" << endl;
            cout << "Name       : " << tempL2->name << endl;
            cout << "Gmail      : " << tempL2->email << endl;
            cout << "Password   : " << tempL2->password << endl;
            cout << "Rank       : " << tempL2->rank << endl;
            cout << "ID         : " << tempL2->id << endl;
            cout << "Group      : " << tempL2->group << endl;
            cout << "GPA        : " << tempL2->gpa << endl;
            cout << "Hours      : " << tempL2->hours << endl;
            // Add more fields based on your data structure
            cout << endl;
            cout << ">> Course Enrollment :" << endl;
            if (tempL2->eventDriven != "NO R")
                cout << "Event Driven         : " << tempL2->eventDriven << endl;
            if (tempL2->probability != "NO R")
                cout << "Probability          : " << tempL2->probability << endl;
            if (tempL2->principles != "NO R")
                cout << "Principles           : " << tempL2->principles << endl;
            if (tempL2->analysis != "NO R")
                cout << "Analysis             : " << tempL2->analysis << endl;
            if (tempL2->dataCommunications != "NO R")
                cout << "Data Communications  : " << tempL2->dataCommunications << endl;
            if (tempL2->informationSystems != "NO R")
                cout << "Information Systems  : " << tempL2->informationSystems << endl;
            return;
        }
        tempL2 = tempL2->next;
    }

    system("color 04");
    cout << "\aL2 Student with ID " << searchID << " not found." << endl;
    sleep(2);
    system("color 07");
}
void Admin::searchL3()
{
    string searchID;
    cout << "Enter The ID Of The L3 Student You Want To Search : ";
    cin >> searchID;

    Student_nodeL3 *tempL3 = headL3;
    while (tempL3 != nullptr)
    {
        if (tempL3->id == searchID)
        {
            cout << ">> L3 Student Found" << endl;
            cout << "Name       : " << tempL3->name << endl;
            cout << "Gmail      : " << tempL3->email << endl;
            cout << "Password   : " << tempL3->password << endl;
            cout << "Rank       : " << tempL3->rank << endl;
            cout << "ID         : " << tempL3->id << endl;
            cout << "Group      : " << tempL3->group << endl;
            cout << "GPA        : " << tempL3->gpa << endl;
            cout << "Hours      : " << tempL3->hours << endl;
            cout << endl;
            cout << ">> Course Enrollment :" << endl;
            if (tempL3->sysModeling != "NO R")
                cout << "System Modeling      : " << tempL3->sysModeling << endl;
            if (tempL3->dataProgramming != "NO R")
                cout << "Data Programming         : " << tempL3->dataProgramming << endl;
            if (tempL3->faultTolerance != "NO R")
                cout << "Fault Tolerance      : " << tempL3->faultTolerance << endl;
            if (tempL3->aiIntro != "NO R")
                cout << "AI Introduction      : " << tempL3->aiIntro << endl;
            if (tempL3->infoSecurity != "NO R")
                cout << "Information Security : " << tempL3->infoSecurity << endl;
            if (tempL3->computerGraphics != "NO R")
                cout << "Computer Graphics    : " << tempL3->computerGraphics << endl;
            return;
        }
        tempL3 = tempL3->next;
    }

    system("color 04");
    cout << "\aL3 Student with ID " << searchID << " not found." << endl;
    sleep(2);
    system("color 07");
}

void Admin::finalResult()
{
    bool flag = true;

    while (flag)
    {
        string ID;
        cout << "\nEnter the student ID: ";
        cin >> ID;

        ifstream csvfile(".\\Source_Files\\DataSet\\Set_Here_Your_Work_DateSet\\All_Student_Fall_22-23.csv");
        if (!csvfile.is_open())
        {
            system("color 04");
            cout << "\aError opening the file.\n";
            system("pause");
            system("color 07");
            system("cls");
        }

        string line;
        getline(csvfile, line);

        bool student_found = false;

        while (getline(csvfile, line))
        {
            stringstream ss(line);
            string cell;
            vector<string> row;

            while (getline(ss, cell, ','))
            {
                row.push_back(cell);
            }

            if (row[0] == ID)
            {
                student_found = true;
                cout << "\nThe student ID is : " << ID << endl;
                if (row[69] != "NO R")
                    cout << "Name: " << row[69] << endl;
                if (row[70] != "NO R")
                    cout << "Rank: " << row[70] << endl;
                if (row[71] != "NO R")
                    cout << "Group: " << row[71] << endl;
                cout << "+-----------------------------------------------+----------+-------+--------+\n";
                cout << "|                    Courses                    |   Code   | Grade | Credit |\n";
                cout << "+-----------------------------------------------+----------+-------+--------+\n";
                if (row[4] != "NO R")
                    cout << "| Event-Driven and Reactive Programming         |  CSC207  | " << row[4] << "  |   3H   |\n";
                if (row[5] != "NO R")
                    cout << "| Parallel and Distributed Systems              |  CNE402  | " << row[5] << "  |   3H   |\n";
                if (row[6] != "NO R")
                    cout << "| Computer Systems Modeling & Analysis          |  CNE310  | " << row[6] << "  |   3H   |\n";
                if (row[7] != "NO R")
                    cout << "| Data Science Programming                      |  CSC309  | " << row[7] << "  |   3H   |\n";
                if (row[8] != "NO R")
                    cout << "| Fault Tolerance                               |  CSC310  | " << row[8] << "  |   3H   |\n";
                if (row[9] != "NO R")
                    cout << "| Probability & Statistics                      |  MAT203  | " << row[9] << "  |   3H   |\n";
                if (row[10] != "NO R")
                    cout << "| Critical Thinking                             |  UNI101  | " << row[10] << "  |   2H   |\n";
                if (row[11] != "NO R")
                    cout << "| Database I                                    |  SWE301  | " << row[11] << "  |   3H   |\n";
                if (row[12] != "NO R")
                    cout << "| Principles of Programming Languages           |  CSC204  | " << row[12] << "  |   3H   |\n";
                if (row[13] != "NO R")
                    cout << "| Wireless Networks                             |  CNE405  | " << row[13] << "  |   3H   |\n";
                if (row[14] != "NO R")
                    cout << "| Internetworking                               |  CNE409  | " << row[14] << "  |   3H   |\n";
                if (row[15] != "NO R")
                    cout << "| Electronics                                   |  CNE101  | " << row[15] << "  |   3H   |\n";
                if (row[16] != "NO R")
                    cout << "| English Language 101                          |  LAN101  | " << row[16] << "  |   3H   |\n";
                if (row[17] != "NO R")
                    cout << "| Analysis and Design of Algorithms             |  CSC205  | " << row[17] << "  |   3H   |\n";
                if (row[18] != "NO R")
                    cout << "| Mobile Computing                              |  CNE406  | " << row[18] << "  |   3H   |\n";
                if (row[19] != "NO R")
                    cout << "| Optical Networks                              |  CNE413  | " << row[19] << "  |   3H   |\n";
                if (row[20] != "NO R")
                    cout << "| Project II                                    |  CNE421  | " << row[20] << "  |   3H   |\n";
                if (row[21] != "NO R")
                    cout << "| Fundamentals of Management                    |  MAN101  | " << row[21] << "  |   2H   |\n";
                if (row[22] != "NO R")
                    cout << "| Introduction to Artificial Intelligence       |  CSC303  | " << row[22] << "  |   3H   |\n";
                if (row[23] != "NO R")
                    cout << "| Calculus II                                   |  MAT202  | " << row[23] << "  |   3H   |\n";
                if (row[24] != "NO R")
                    cout << "| Electric Circuits                             |  CNE201  | " << row[24] << "  |   3H   |\n";
                if (row[25] != "NO R")
                    cout << "| Data Communications                           |  CNE203  | " << row[25] << "  |   3H   |\n";
                if (row[26] != "NO R")
                    cout << "| Information Systems Analysis and Design       |  SWE201  | " << row[26] << "  |   3H   |\n";
                if (row[27] != "NO R")
                    cout << "| Information and Networks Security             |  CNE308  | " << row[27] << "  |   3H   |\n";
                if (row[28] != "NO R")
                    cout << "| Linear Algebra II                             |  MAT201  | " << row[28] << "  |   3H   |\n";
                if (row[29] != "NO R")
                    cout << "| Introduction to Computer Science              |  CSC101  | " << row[29] << "  |   4H   |\n";
                if (row[30] != "NO R")
                    cout << "| Fundamentals of Programming I                 |  CSC102  | " << row[30] << "  |   4H   |\n";
                if (row[31] != "NO R")
                    cout << "| Perception and computer vision                |  CSC407  | " << row[31] << "  |   3H   |\n";
                if (row[32] != "NO R")
                    cout << "| Formal Languages and Automata                 |  CSC402  | " << row[32] << "  |   3H   |\n";
                if (row[33] != "NO R")
                    cout << "| Human Computer Interaction                    |  CSC407  | " << row[33] << "  |   3H   |\n";
                if (row[34] != "NO R")
                    cout << "| Machine Learning                              |  CSC409  | " << row[34] << "  |   3H   |\n";
                if (row[35] != "NO R")
                    cout << "| Compilers and Interpreters                    |  CSC402  | " << row[35] << "  |   3H   |\n";
                if (row[36] != "NO R")
                    cout << "| Computer Graphics                             |  CSC302  | " << row[36] << "  |   3H   |\n";
                if (row[37] != "NO R")
                    cout << "| English Language 102                          |  LAN102  | " << row[37] << "  |   3H   |\n";
                if (row[38] != "NO R")
                    cout << "| Computer Organization & Architecture          |  CNE302  | " << row[38] << "  |   3H   |\n";
                if (row[39] != "NO R")
                    cout << "| Selected Topics in Computer Networks          |  CNE411  | " << row[39] << "  |   3H   |\n";
                if (row[40] != "NO R")
                    cout << "| Software Engineering II                       |  SWE402  | " << row[40] << "  |   3H   |\n";
                if (row[41] != "NO R")
                    cout << "| Software Project Management                   |  SWE412  | " << row[41] << "  |   2H   |\n";
                if (row[42] != "NO R")
                    cout << "| Project II                                    |  SWE421  | " << row[42] << "  |   3H   |\n";
                if (row[43] != "NO R")
                    cout << "| Object Oriented Software Development          |  SWE403  | " << row[43] << "  |   3H   |\n";
                if (row[44] != "NO R")
                    cout << "| Data warehousing and Data integration         |  SWE411  | " << row[44] << "  |   3H   |\n";
                if (row[45] != "NO R")
                    cout << "| Database II                                   |  SWE402  | " << row[45] << "  |   3H   |\n";
                if (row[46] != "NO R")
                    cout << "| Distributed Systems                           |  CNE406  | " << row[46] << "  |   3H   |\n";
                if (row[47] != "NO R")
                    cout << "| Fundamentals of Programming II                |  CSC201  | " << row[47] << "  |   4H   |\n";
                if (row[48] != "NO R")
                    cout << "| Operating Systems                             |  CSC301  | " << row[48] << "  |   3H   |\n";
                if (row[49] != "NO R")
                    cout << "| Software and System Tools                     |  CSC206  | " << row[49] << "  |   3H   |\n";
                if (row[50] != "NO R")
                    cout << "| Programming on the Web                        |  CSC304  | " << row[50] << "  |   3H   |\n";
                if (row[51] != "NO R")
                    cout << "| Project II                                    |  CSC421  | " << row[51] << "  |   3H   |\n";
                if (row[52] != "NO R")
                    cout << "| Computer Networks I                           |  CNE304  | " << row[52] << "  |   3H   |\n";
                if (row[53] != "NO R")
                    cout << "| Discrete Mathematics                          |  MAT103  | " << row[53] << "  |   3H   |\n";
                if (row[54] != "NO R")
                    cout << "| Presentation and Communication Skills         |  UNI102  | " << row[54] << "  |   2H   |\n";
                if (row[55] != "NO R")
                    cout << "| Advanced Computer Graphics                    |  CSC413  | " << row[55] << "  |   3H   |\n";
                if (row[56] != "NO R")
                    cout << "| Logic Design                                  |  CNE202  | " << row[56] << "  |   3H   |\n";
                if (row[57] != "NO R")
                    cout << "| Computer Networks II                          |  CNE401  | " << row[57] << "  |   3H   |\n";
                if (row[58] != "NO R")
                    cout << "| Selected Topics in Computer Networks          |  CNE408  | " << row[58] << "  |   3H   |\n";
                if (row[59] != "NO R")
                    cout << "| Software Engineering II                       |  SWE401  | " << row[59] << "  |   3H   |\n";
                if (row[60] != "NO R")
                    cout << "| English Language 100                          |  LAN100  | " << row[60] << "  |   3H   |\n";
                if (row[61] != "NO R")
                    cout << "| Robotics                                      |  AIN402  | " << row[61] << "  |   3H   |\n";
                if (row[62] != "NO R")
                    cout << "| Virtual Reality                               |  AIN401  | " << row[62] << "  |   3H   |\n";
                if (row[63] != "NO R")
                    cout << "| Project II                                    |  AIN421  | " << row[63] << "  |   3H   |\n";
                if (row[64] != "NO R")
                    cout << "| Machine Vision                                |  AIN413  | " << row[64] << "  |   3H   |\n";
                if (row[65] != "NO R")
                    cout << "| Deep learning                                 |  AIN405  | " << row[65] << "  |   3H   |\n";
                if (row[66] != "NO R")
                    cout << "| Natural and formal languages processing       |  AIN403  | " << row[66] << "  |   3H   |\n";
                if (row[67] != "NO R")
                    cout << "| Image and Speech Processing                   |  AIN412  | " << row[67] << "  |   3H   |\n";
                if (row[68] != "NO R")
                    cout << "| Selected topics in computer science           |  CSC408  | " << row[68] << "  |   3H   |\n";
                cout << "+-----------------------------------------------+----------+-------+--------+\n";

                cout << "\nTotal GPA: " << row[1] << endl;
                cout << "Total credit hours: " << row[3] << endl;
                break;
            }
        }

        if (!student_found)
        {
            system("color 04");
            cout << "\aStudent ID not found\n";
            sleep(2);
            system("pause");
            system("color 07");
        }

        string flag_input;
        cout << "\nDo you want to see the result again? (Y/N): ";
        cin >> flag_input;

        if (flag_input == "N" || flag_input == "n")
        {
            flag = false;
        }
        else if (flag_input != "Y" && flag_input != "y")
        {
            cout << "Invalid input. Exiting loop.\n";
            flag = false;
        }
        system("cls");
    }
}

void Admin::Schedule()
{
    // string path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Schedule\\Full_Schedule.pdf\"";

    // \"\" here will open default program to open pdfs files
    // Done Updated @0xMoataz

    string path = "start \"\" \".\\Source_Files\\Schedule\\Full_Schedule.pdf\"";
    system(path.c_str());
    cout << "\n\n\n";
    cout << "Going Back To The Dashboard ..." << endl;
    system("pause");
    cout << "\n";
    system("cls");
    dashboard();
}

void Admin::dashboard()
{
    int adminChoice;
    bool adminFlag = true;

    while (adminFlag)
    {
        FrontEndline();
        cout << "\n\n\t\t\t\t        " << x << "             DASHBOARD              " << Y << "\n\n";
        cout << setw(00) << "Welcome back , " << name << "\n\n"; // !! Back To Add Admin Name
        cout << "[01] - Manage Students Level 1" << endl;
        cout << "[02] - Manage Students Level 2" << endl;
        cout << "[03] - Manage Students Level 3" << endl;
        cout << "[04] - Manage Students Level 4" << endl;
        cout << "[05] - Manage Doctors" << endl;
        cout << "[06] - Manage TAs" << endl;
        cout << "[07] - Manage Admins" << endl;
        cout << "[08] - Logout" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> adminChoice;
        switch (adminChoice)
        {
        case 1:
            system("cls");
            dashboardStudentL1();
            break;
        case 2:
            system("cls");
            dashboardStudentL2();
            break;
        case 3:
            system("cls");
            dashboardStudentL3();
            break;
        case 4:
            system("cls");
            system("color 04");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            NOT AVAILABLE NOW           " << Y << "\n\n";
            cout << endl;
            sleep(3);
            system("color 07");
            system("cls");
            break;
        case 5:
            system("cls");
            dashboardDoctor();
            break;
        case 6:
            system("cls");
            dashboardTA();
            break;
        case 7:
            system("cls");
            dashboardAdmin();
            break;
        case 8:
            logout();
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}

void Admin::dashboardStudentL1()
{
    int choice_fun;
    bool flag = true;
    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "    ADMIN: MANAGING STUDENTS LEVEL 1    " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Student Account" << endl;
        cout << setw(10) << "[02] - Edit Student Account" << endl;
        cout << setw(10) << "[03] - Delete Student Account" << endl;
        cout << setw(10) << "[04] - View Student Info" << endl;
        cout << setw(10) << "[05] - Display Students Level 1" << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           ADD STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Student" << endl;
            cout << endl;
            AddStudentL1();
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          EDIT STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Student" << endl;
            cout << endl;
            editNodeL1();
            system("cls");

            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DELETE STUDENT ACCOUNT         " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteL1();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            VIEW STUDENT INFO           " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchL1();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DISPLAY STUDENTS LEVEL 1       " << Y << "\n\n";
            cout << endl;
            displayL1(); // todo
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}
void Admin::dashboardStudentL2()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "    ADMIN: MANAGING STUDENTS LEVEL 2    " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Student Account" << endl;
        cout << setw(10) << "[02] - Edit Student Account" << endl;
        cout << setw(10) << "[03] - Delete Student Account" << endl;
        cout << setw(10) << "[04] - View Student Info" << endl;
        cout << setw(10) << "[05] - Display Students Level 2" << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           ADD STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Student" << endl;
            cout << endl;
            AddStudentL2();
            system("cls");

            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          EDIT STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Student" << endl;
            cout << endl;
            editNodeL2();
            system("cls");

            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DELETE STUDENT ACCOUNT         " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteL2();
            system("cls");

            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            VIEW STUDENT INFO           " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchL2();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DISPLAY STUDENTS LEVEL 3       " << Y << "\n\n";
            cout << endl;
            displayL2();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}
void Admin::dashboardStudentL3()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "    ADMIN: MANAGING STUDENTS LEVEL 3    " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Student Account" << endl;
        cout << setw(10) << "[02] - Edit Student Account" << endl;
        cout << setw(10) << "[03] - Delete Student Account" << endl;
        cout << setw(10) << "[04] - View Student Info" << endl;
        cout << setw(10) << "[05] - Display Students Level 3" << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           ADD STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Student" << endl;
            cout << endl;
            AddStudentL3();
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          EDIT STUDENT ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Student" << endl;
            cout << endl;
            editNodeL3();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DELETE STUDENT ACCOUNT         " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteL3();
            system("cls");

            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            VIEW STUDENT INFO           " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchL3();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         DISPLAY STUDENTS LEVEL 3       " << Y << "\n\n";
            cout << endl;
            displayL3();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}
void Admin::dashboardDoctor()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         ADMIN: MANAGING DOCTORS         " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Doctor Account" << endl;
        cout << setw(10) << "[02] - Edit Doctor Account" << endl;
        cout << setw(10) << "[03] - Delete Doctor Account" << endl;
        cout << setw(10) << "[04] - View Doctor Info" << endl;
        cout << setw(10) << "[05] - Display All Doctors " << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            ADD DOCTOR ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Doctor" << endl;
            cout << endl;
            AddDr();
            system("cls");

            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            EDIT DOCTOR ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Doctor" << endl;
            cout << endl;
            editNodeDr();
            system("cls");

            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          DELETE DOCTOR ACCOUNT         " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteDr();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "             VIEW DOCTOR INFO           " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchDr();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           DISPLAY ALL DOCTORS          " << Y << "\n\n";
            cout << endl;
            displayDr();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}
void Admin::dashboardTA()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           ADMIN: MANAGING TAS          " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Teacher Assistant Account" << endl;
        cout << setw(10) << "[02] - Edit Teacher Assistant Account" << endl;
        cout << setw(10) << "[03] - Delete Teacher Assistant Account" << endl;
        cout << setw(10) << "[04] - View Teacher Assistant Info" << endl;
        cout << setw(10) << "[05] - Display All Teacher Assistants " << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";

        cin >> choice_fun;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "      ADD TEACHER ASSISTANT ACCOUNT     " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Teacher Assistant" << endl;
            cout << endl;
            AddTA();
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "      EDIT TEACHER ASSISTANT ACCOUNT     " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Teacher Assistant" << endl;
            cout << endl;
            editNodeTA();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "     DELETE TEACHER ASSISTANT ACCOUNT    " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteTA();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "       VIEW TEACHER ASSISTANT INFO      " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchTA();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "      DISPLAY ALL TEACHER ASSISTANTS     " << Y << "\n\n";
            cout << endl;
            displayTA();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}
void Admin::dashboardAdmin()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          Admin: Managing Admins         " << Y << "\n\n";
        cout << endl;
        cout << setw(10) << "[01] - Add Admin Account" << endl;
        cout << setw(10) << "[02] - Edit Admin Account" << endl;
        cout << setw(10) << "[03] - Delete Admin Account" << endl;
        cout << setw(10) << "[04] - View Admin Info" << endl;
        cout << setw(10) << "[05] - Display All Admins " << endl;
        cout << setw(10) << "[06] - Display Final Results " << endl;
        cout << setw(10) << "[07] - Course Schedule " << endl;
        cout << setw(10) << "[00] - Go back To Admin Dashboard" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            ADD ADMIN ACCOUNT           " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter Data About New Admin" << endl;
            cout << endl;
            AddAdmin();
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            EDIT ADMIN ACCOUNT          " << Y << "\n\n";
            cout << endl;
            cout << setw(10) << "Enter New Data About This Admin" << endl;
            cout << endl;
            editNodeAdmin();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "           DELETE ADMIN ACCOUNT         " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            deleteAdmin();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "             VIEW ADMIN INFO           " << Y << "\n\n";
            cout << endl;
            cout << setw(0);
            searchAdmin();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "            DISPLAY ALL ADMINS          " << Y << "\n\n";
            cout << endl;
            displayAdmin();
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "   FINAL RESULTS FOR SEMESTER FALL 22-23   " << Y << "\n\n";
            cout << endl;
            finalResult();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          COURSE SCHEDULE         " << Y << "\n\n";
            cout << endl;
            Schedule();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            flag = false;
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}

// Todo ================================================================================================================================================================
// Todo ------------------------------------------------->                           Class Student                           <------------------------------------------
// Todo ================================================================================================================================================================
class Student : public Admin
{
public:
    void dashboard();
    void main();
    void login();
    void logout();
    bool search(string gmail, string password);
    void changePass();
    void myCourses();
    void myProfile();
    void myGrades();
    void mySchedule();
    void myCourses01();
    void myCourses02();
    void myCourses03();
    void myCourses04();
    void myCourses05();
    void myCourses06();

private:
    string gmail;
    string password;
    string rank;
    string id;
    string name;
    string group;
    string gpa;
    string hours;
    string electronics;
    string linearAlgebra;
    string programming;
    string discreteMath;
    string presentation;
    string english;

    string confirmGmail;
    string confirmPassword;
    Student_nodeL1 *mystudent;
    Student_nodeL1 *next;
};

void Student::main()
{

    bool studentFlag = true;

    while (studentFlag)
    {
        int studentChoice;
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          WELCOME TO STUDENT PAGE           " << Y << "\n\n";

        cout << "[1] - Login" << endl;
        cout << "[2] - Exit" << endl;
        cout << "[0] - Go Back to Welcome Page" << endl;
        cout << "\n>> Enter your choice : ";
        if (!(cin >> studentChoice))
        {
            cin.clear();                                                   // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            system("color 04");
            cout << "\aInvalid input. Please enter a number.\n";
            system("pause");
            system("color 07");
            system("cls");
            continue; // skip the rest of the loop and start over
        }
        switch (studentChoice)
        {
        case 1:
            readCSVL1();
            system("cls");
            login();
            break;
        case 2:
            cout << "Exiting the program . . .\n";
            exit(0);
            break;
        case 0:
            studentFlag = false;
            system("cls");
            welcomePage();
            break;
        default:
            system("color 04");
            cout << "\aInvalid choice. Please try again.\n";
            cout << "Try Again !!" << endl;
            sleep(2);
            system("pause");
            system("color 07");
            system("cls");
        }
    }
}
void Student::login()
{
    bool flag = true;

    while (flag)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "              LOGIN STUDENT             " << Y << "\n\n";

        cout << "Enter Gmail    : ";
        getline(cin, confirmGmail);
        cout << "Enter Password : ";
        getline(cin, confirmPassword);
        if (search(confirmGmail, confirmPassword))
        {
            system("cls");
            dashboard();
        }
        else
        {
            flag = false;
            system("cls");
        }
    }
}
void Student::logout()
{
    cout << setw(62) << "Logging out ";
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << ".";
    }
    gmail = "";
    password = "";
    rank = "";
    id = "";
    name = "";
    group = "";
    gpa = "";
    hours = "";
    electronics = "";
    linearAlgebra = "";
    programming = "";
    discreteMath = "";
    presentation = "";
    english = "";
    confirmGmail = "";
    confirmPassword = "";
    system("cls");
    main();
}
bool Student::search(string enteredGmail, string enteredPassword)
{
    Student_nodeL1 *tempL1 = headL1;
    while (tempL1 != nullptr)
    {
        if (tempL1->gmail == enteredGmail && tempL1->password == enteredPassword)
        {
            cout << setw(65) << "LOGIN SUCCESSFUL !! " << setw(65) << endl;
            sleep(2);
            gmail = enteredGmail;
            password = enteredPassword;
            rank = tempL1->rank;
            id = tempL1->id;
            name = tempL1->name;
            group = tempL1->group;
            gpa = tempL1->gpa;
            hours = tempL1->hours;
            electronics = tempL1->electronics;
            linearAlgebra = tempL1->linearAlgebra;
            programming = tempL1->programming;
            discreteMath = tempL1->discreteMath;
            presentation = tempL1->presentation;
            english = tempL1->english;
            return true;
        }
        tempL1 = tempL1->next;
    }

    system("color 04");
    cout << setw(05) << "\aError !! " << endl;
    cout << "Login failed. Incorrect Gmail or password." << endl;
    cout << "Try Again !!" << endl;
    sleep(3);
    system("color 07");
    system("pause");
    cout << endl;
    return false;
}
void Student::dashboard()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        FrontEndline();
        cout << "\n\n\t\t\t\t        " << x << "             DASHBOARD              " << Y << "\n\n";
        cout << setw(00) << "Welcome back, " << name << "\n\n";
        cout << setw(05) << "[1] - My Courses" << endl;
        cout << setw(05) << "[2] - My Profile" << endl;
        cout << setw(05) << "[3] - Grades" << endl;
        cout << setw(05) << "[4] - Course Schedule" << endl;
        cout << setw(05) << "[5] - Change Password" << endl;
        cout << setw(05) << "[6] - Logout" << endl;

        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            myCourses();
            break;
        case 2:
            system("cls");
            myProfile();
            break;
        case 3:
            system("cls");
            myGrades();
            break;
        case 4:
            system("cls");
            mySchedule();
            break;
        case 5:
            system("cls");
            changePass();
            break;
        case 6:
            logout();
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}

void Student::myCourses()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        cout << "Your Courses : " << endl;
        cout << endl;
        cout << "[1] Electronics " << endl;
        cout << "[2] Linear Algebra II " << endl;
        cout << "[3] Fundamentals of Programming I " << endl;
        cout << "[4] Discrete Mathematics " << endl;
        cout << "[5] Presentation and Communication Skills " << endl;
        cout << "[6] English Language 100 " << endl;
        cout << endl;
        cout << "[0] Back to Dashboard" << endl;
        cout << endl;
        cout << "View Content of Courses" << endl;
        cout << "Enter Course Number : ";
        cin >> choice_fun;
        FrontEndline();
        switch (choice_fun)
        {
        case 1:
            system("cls");
            myCourses01();
            break;
        case 2:
            system("cls");
            myCourses02();
            break;
        case 3:
            system("cls");
            myCourses03();
            break;
        case 4:
            system("cls");
            myCourses04();
            break;
        case 5:
            system("cls");
            myCourses05();
            break;
        case 6:
            system("cls");
            myCourses06();
            break;
        case 0:
            flag = false;
            cout << "\n\n";
            cout << setw(75) << "GO BACK TO THE DASHBOARD" << setw(75) << endl;
            sleep(3);
            system("cls");
            dashboard();
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError!! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n\n";
            system("color 07");
            break;
        }
    }
}

void Student::changePass()
{
    cout << "Please Enter Old Password : ";
    string oldpassword;
    cin >> oldpassword;
    if (oldpassword == mystudent->password)
    {
        cout << "Please Enter New Password : ";
        cin >> mystudent->password;
        cout << "Password Changed Sucessfully !!\n";
        exportToCSVL1();
    }
    else
    {
        system("color 04");
        cout << setw(05) << "\aError!! " << endl;
        cout << "wrong password" << endl;
        system("color 07");
    }
    system("pause");
    system("cls");
}

void Student::myProfile()
{
    cout << "Your Profile : " << endl;
    cout << "\n\n";
    cout << ">> Personal information" << endl;
    cout << "Full Name: " << name << endl;
    cout << "ID : " << id << endl;
    cout << "Email Address : " << gmail << endl;
    cout << "Country : Egypt" << endl;
    cout << "Group : " << group << endl;
    cout << "GPA : " << gpa << endl;
    cout << "Total Hours : " << hours << endl;

    cout << "\n";
    cout << ">> Course Details" << endl;
    cout << "[1] Electronics " << endl;
    cout << "[2] Linear Algebra II " << endl;
    cout << "[3] Fundamentals of Programming I " << endl;
    cout << "[4] Discrete Mathematics " << endl;
    cout << "[5] Presentation and Communication Skills " << endl;
    cout << "[6] English Language 100 " << endl;
    cout << "\n";

    system("pause");
    system("cls");
}

void Student::myGrades()
{
    cout << "Your Grads : " << endl;
    cout << "\n";

    cout << "Name: " << name << endl;
    cout << "Id : " << id << endl;
    cout << "Group : " << group << endl;
    cout << "Rank : " << rank << endl;
    cout << "\n";

    cout << "+-----------------------------------------------+----------+-------+--------+\n";
    cout << "|                    Courses                    |   Code   | Grade | Credit |\n";
    cout << "+-----------------------------------------------+----------+-------+--------+\n";
    cout << "| Electronics                                   |  CNE101  |" << setw(4) << electronics << "   |   3H   |\n";
    cout << "| Linear Algebra II                             |  MAT201  |" << setw(4) << linearAlgebra << "   |   3H   |\n";
    cout << "| Fundamentals of Programming I                 |  CSC102  |" << setw(4) << programming << "   |   4H   |\n";
    cout << "| Discrete Mathematics                          |  MAT103  |" << setw(4) << discreteMath << "   |   3H   |\n";
    cout << "| Presentation and Communication Skills         |  UNI102  |" << setw(4) << presentation << "   |   2H   |\n";
    cout << "| English Language 100                          |  LAN100  |" << setw(4) << english << "   |   3H   |\n";
    cout << "+-----------------------------------------------+----------+-------+--------+\n";

    cout << "\nTotal GPA: " << gpa << endl;
    cout << "Total credit hours: " << hours << endl;
    cout << "\n";

    system("pause");
    system("cls");
}

void Student::mySchedule()
{
    string path = "start \"\" \".\\Source_Files\\Schedule\\" + group + ".pdf\"";
    system(path.c_str());
    sleep(1);
    cout << "\n\n\n";
    cout << "Back To The Dashboard . . ." << endl;
    system("pause");
    cout << "\n";
    system("cls");
}

void Student::myCourses01() // Electronics
{
    int courseNumber;
    string path;
    bool flag = true;

    while (flag)
    {
        cout << "Course : Electronics" << endl;
        cout << "\n";
        cout << "Instructor : Dr. Ahmed Abdel-Latif" << endl;
        cout << "Teaching Assistant : " << endl;
        cout << "\n";
        cout << ">> Lectures Available  " << endl;
        cout << "[01] Lecture 01" << endl;
        cout << "[02] Lecture 02" << endl;
        cout << "[03] Lecture 03" << endl;
        cout << "[04] Lecture 04" << endl;
        cout << "\n";
        cout << ">> Labs Available  " << endl;
        cout << "[05] Lab 01" << endl;
        cout << "[06] Lab 02" << endl;
        cout << "[07] Lab 03" << endl;
        cout << "[08] Lab 04" << endl;
        cout << "[09] Lab 05" << endl;
        cout << "[10] Lab 06" << endl;
        cout << "[11] Lab 07" << endl;
        cout << "[12] Lab 08" << endl;
        cout << "[13] Lab 09" << endl;
        cout << "\n";
        cout << "[00] Back to Dashboard" << endl;
        cout << "\n";

        cout << "Enter the number of the Lecture or Lab to view : ";
        cin >> courseNumber;
        if (courseNumber >= 1 && courseNumber <= 13)
        {
            string courseNumber_str = to_string(courseNumber).c_str();
            path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Level_01\\Semester_2\\Electronics\\" + courseNumber_str + ".pdf\"";
            cout << "Viewing Lecture/Lab " << courseNumber << endl;
            system(path.c_str());
            cout << "\n";
            system("pause");
            cout << "\n";
            system("cls");
        }
        else if (courseNumber == 0)
        {
            flag = false;
            cout << "Going Back To Your Courses . . ." << endl;
            sleep(3);
            system("cls");
        }
        else
        {
            system("color 04");
            cout << setw(05) << "\aError !! " << endl;
            cout << "Invalid number! Please enter a valid number " << endl;
            sleep(3);
            system("color 07");
            system("pause");
            cout << endl;
            system("cls");
        }
    }
}

void Student::myCourses02() // Linear Algebra II
{
    int courseNumber;
    string path;
    bool flag = true;

    while (flag)
    {
        cout << "Course : Linear Algebra II" << endl;
        cout << "\n";
        cout << "Instructor : Dr. Sherif Elshafei" << endl;
        cout << "Teaching Assistant : Eng. Mina Tawadros " << endl;
        cout << "\n";
        cout << ">> Lectures Available  " << endl;
        cout << "[01] Lecture 01" << endl;
        cout << "[02] Lecture 02" << endl;
        cout << "[03] Lecture 03" << endl;
        cout << "[04] Lecture 04" << endl;
        cout << "[05] Lecture 05" << endl;
        cout << "[06] Lecture 06" << endl;
        cout << "[07] Lecture 07" << endl;
        cout << "\n";
        cout << ">> Labs Available  " << endl;
        cout << "[08] Lab 01" << endl;
        cout << "[09] Lab 02" << endl;
        cout << "[10] Lab 03" << endl;
        cout << "[11] Lab 04" << endl;
        cout << "[12] Lab 05" << endl;
        cout << "[13] Lab 06" << endl;
        cout << "\n";
        cout << "[00] Back to Dashboard" << endl;
        cout << "\n";
        cout << "Enter the number of the Lecture or Lab to view : ";
        cin >> courseNumber;
        if (courseNumber >= 1 && courseNumber <= 13)
        {
            string courseNumber_str = to_string(courseNumber).c_str();
            path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Level_01\\Semester_2\\Linear_Algebra_ll\\" + courseNumber_str + ".pdf\"";
            cout << "Viewing Lecture/Lab " << courseNumber << endl;
            system(path.c_str());
            cout << "\n";
            system("pause");
            cout << "\n";
            system("cls");
        }
        else if (courseNumber == 0)
        {
            flag = false;
            cout << "Going Back To Your Courses . . ." << endl;
            sleep(3);
            system("cls");
        }
        else
        {
            system("color 04");
            cout << setw(05) << "\aError !! " << endl;
            cout << "Invalid number! Please enter a valid number " << endl;
            sleep(3);
            system("color 07");
            system("pause");
            cout << endl;
            system("cls");
        }
    }
}

void Student::myCourses03() // Fundamentals of Programming I
{
    int courseNumber;
    string path;
    bool flag = true;
    while (flag)
    {
        cout << "Course : Fundamentals of Programming I" << endl;
        cout << "\n";
        cout << "Instructor : Dr. Marian Wagdy" << endl;
        cout << "Teaching Assistant : Eng. Monica " << endl;
        cout << "\n";
        cout << ">> Lectures Available  " << endl;
        cout << "[01] Lecture 01" << endl;
        cout << "[02] Lecture 02" << endl;
        cout << "[03] Lecture 03" << endl;
        cout << "[04] Lecture 04" << endl;
        cout << "[05] Lecture 05" << endl;
        cout << "[06] Lecture 06" << endl;
        cout << "[07] Lecture 07" << endl;
        cout << "[08] Lecture 08" << endl;
        cout << "\n";
        cout << ">> Labs Available  " << endl;
        cout << "[09] Lab 01  X" << endl;
        cout << "[10] Lab 01  Y" << endl;
        cout << "[11] Lab 02  X" << endl;
        cout << "[12] Lab 02  Y" << endl;
        cout << "[13] Lab 03  X" << endl;
        cout << "[14] Lab 03  Y" << endl;
        cout << "[15] Lab 04  X" << endl;
        cout << "[16] Lab 04  Y" << endl;
        cout << "[17] Lab 05  X" << endl;
        cout << "[18] Lab 05  Y" << endl;
        cout << "[19] Lab 06  X" << endl;
        cout << "\n";
        cout << "[00] Back to Dashboard" << endl;
        cout << "\n";

        cout << "Enter the number of the Lecture or Lab to view : ";
        cin >> courseNumber;
        if (courseNumber >= 1 && courseNumber <= 19)
        {
            string courseNumber_str = to_string(courseNumber).c_str();
            path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Level_01\\Semester_2\\Fundamentals_of_Programming_l\\" + courseNumber_str + ".pdf\"";
            cout << "Viewing Lecture/Lab " << courseNumber << endl;
            system(path.c_str());
            cout << "\n";
            system("pause");
            cout << "\n";
            system("cls");
        }
        else if (courseNumber == 0)
        {
            flag = false;
            cout << "Going Back To Your Courses . . ." << endl;
            sleep(3);
            system("cls");
        }
        else
        {
            system("color 04");
            cout << setw(05) << "\aError !! " << endl;
            cout << "Invalid number! Please enter a valid number " << endl;
            sleep(3);
            system("color 07");
            system("pause");
            cout << endl;
            system("cls");
        }
    }
}

void Student::myCourses04() // Discrete Mathematics
{
    cout << "Course : Discrete Mathematics" << endl;
    cout << "\n";
    cout << "Instructor : Dr. Soha" << endl;
    cout << "Teaching Assistant : Eng. Fatma Hossam " << endl;
    cout << "\n";
    cout << ">> Lectures Available  " << endl;
    cout << "[01] Lecture 01" << endl;
    cout << "[02] Lecture 02" << endl;
    cout << "[03] Lecture 03" << endl;
    cout << "[04] Lecture 04" << endl;
    cout << "[05] Lecture 05" << endl;
    cout << "[06] Lecture 06" << endl;
    cout << "[07] Lecture 07" << endl;
    cout << "[08] Lecture 08" << endl;
    cout << "[09] Lecture 09" << endl;
    cout << "\n";
    cout << ">> Sec Available  " << endl;
    cout << "[10] Sec 01" << endl;
    cout << "[11] Sec 02" << endl;
    cout << "[12] Sec 03" << endl;
    cout << "[13] Sec 04" << endl;
    cout << "[14] Sec 05" << endl;
    cout << "[15] Sec 06" << endl;
    cout << "[16] Sec 07" << endl;
    cout << "\n";
    cout << "[00] Back to Dashboard" << endl;
    cout << "\n";

    int courseNumber;
    string path;
    bool flag = true;

    while (flag)
    {
        cout << "Enter the number of the Lecture or Lab to view : ";
        cin >> courseNumber;
        if (courseNumber >= 1 && courseNumber <= 16)
        {
            string courseNumber_str = to_string(courseNumber).c_str();
            path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Level_01\\Semester_2\\Discrete_Mathematics\\" + courseNumber_str + ".pdf\"";
            cout << "Viewing Lecture/Lab " << courseNumber << endl;
            system(path.c_str());
            cout << "\n";
            system("pause");
            cout << "\n";
            system("cls");
        }
        else if (courseNumber == 0)
        {
            flag = false;
            cout << "Going Back To Your Courses . . ." << endl;
            sleep(3);
            system("cls");
        }
        else
        {
            system("color 04");
            cout << setw(05) << "\aError !! " << endl;
            cout << "Invalid number! Please enter a valid number " << endl;
            sleep(3);
            system("color 07");
            system("pause");
            cout << endl;
            system("cls");
        }
    }
}

void Student::myCourses05() // Presentations and Communication Skills
{
    cout << "Course : Presentations and Communication Skills" << endl;
    cout << "\n";
    cout << "Instructor : Dr. Rawhy" << endl;
    cout << "Teaching Assistant : Eng. Mai El-Araby " << endl;
    cout << "\n";
    cout << ">> Lectures Available  " << endl;
    cout << "[01] Lecture 01" << endl;
    cout << "[02] Lecture 02" << endl;
    cout << "[03] Lecture 03" << endl;
    cout << "[04] Lecture 04" << endl;
    cout << "[05] Lecture 05" << endl;
    cout << "\n";
    cout << "[00] Back to Dashboard" << endl;
    cout << "\n";

    int courseNumber;
    string path;
    bool flag = true;

    while (flag)
    {
        cout << "Enter the number of the Lecture or Lab to view : ";
        cin >> courseNumber;
        if (courseNumber >= 1 && courseNumber <= 5)
        {
            string courseNumber_str = to_string(courseNumber).c_str();
            path = "start \"Foxit PDF Editor\" \".\\Source_Files\\Level_01\\Semester_2\\Presentations\\" + courseNumber_str + ".pdf\"";
            cout << "Viewing Lecture/Lab " << courseNumber << endl;
            system(path.c_str());
            cout << "\n";
            system("pause");
            cout << "\n";
            system("cls");
        }
        else if (courseNumber == 0)
        {
            flag = false;
            cout << "Going Back To Your Courses . . ." << endl;
            sleep(3);
            system("cls");
        }
        else
        {
            system("color 04");
            cout << setw(05) << "\aError !! " << endl;
            cout << "Invalid number! Please enter a valid number " << endl;
            sleep(3);
            system("color 07");
            system("pause");
            cout << endl;
            system("cls");
        }
    }
}

void Student::myCourses06() // English Language 100
{
    cout << "Course : English Language 100" << endl;
    cout << "\n";
    cout << "Instructor : " << endl;
    cout << "Teaching Assistant :  " << endl;
    cout << "\n";
    cout << ">> Lectures Not Available  " << endl;
    cout << "\n\n";

    system("pause");
    system("cls");
}

// Todo ================================================================================================================================================================
// Todo ------------------------------------------------->                           Class Doctor                           <-------------------------------------------
// Todo ================================================================================================================================================================

class Doctor : public Admin
{
public:
    void dashboard(); // todo @khaled
    void main();
    void login();
    void logout();
    bool search(string gmail, string password);
    void myCourses();
    void myProfile();
    void editstudent();
    void accessCourse(string codeCourse);

private:
    string email;
    string password;
    string name;
    string course1;
    string code1;
    string course2;
    string code2;
    string course3;
    string code3;
    string numOfCourses;
    string confirmGmail;
    string confirmPassword;
    DoctorNode *next;
};

void Doctor::main()
{
    bool doctorFlag = true;
    int doctorChoice;

    while (doctorFlag)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "          WELCOME TO DOCTOR PAGE           " << Y << "\n\n";

        cout << "[1] - Login" << endl;
        cout << "[2] - Exit" << endl;
        cout << "[0] - Go Back to Welcome Page" << endl;
        cout << "\n>> Enter your choice : ";
        if (!(cin >> doctorChoice))
        {
            cin.clear();                                                   // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            system("color 04");
            cout << "\aInvalid input. Please enter a number.\n";
            system("pause");
            system("color 07");
            system("cls");
            continue; // skip the rest of the loop and start over
        }

        switch (doctorChoice)
        {
        case 1:
            readCSVDr();
            system("cls");
            login();
            break;
        case 2:
            cout << "Exiting the program . . .\n";
            exit(0);
            break;
        case 0:
            doctorFlag = false;
            system("cls");
            welcomePage();
            break;
        default:
            system("color 04");
            cout << "\aInvalid choice. Please try again.\n";
            cout << "Try Again !!" << endl;
            sleep(2);
            system("pause");
            system("color 07");
            system("cls");
        }
    }
}

void Doctor::login()
{
    bool flag = true;

    while (flag)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "               LOGIN DOCTOR             " << Y << "\n\n";
        cout << "Enter Gmail    : ";
        getline(cin, confirmGmail);
        cout << "Enter Password : ";
        getline(cin, confirmPassword);
        if (search(confirmGmail, confirmPassword))
        {
            system("cls");
            readCSVL1();
            readCSVL2();
            readCSVL3();
            dashboard();
        }
        else
        {
            flag = false;
            system("cls");
        }
    }
}

void Doctor::logout()
{
    cout << setw(62) << "Logging out ";
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << ".";
    }
    email = "";
    password = "";
    name = "";
    course1 = "";
    code1 = "";
    course2 = "";
    code2 = "";
    course3 = "";
    code3 = "";
    numOfCourses = "";
    confirmGmail = "";
    confirmPassword = "";

    Student_nodeL1 *tempL1 = headL1;
    Student_nodeL2 *tempL2 = headL2;
    Student_nodeL3 *tempL3 = headL3;

    while (tempL1 != nullptr)
    {
        Student_nodeL1 *next = tempL1->next;
        delete tempL1;
        tempL1 = next;
    }
    while (tempL2 != nullptr)
    {
        Student_nodeL2 *next = tempL2->next;
        delete tempL2;
        tempL2 = next;
    }
    while (tempL3 != nullptr)
    {
        Student_nodeL3 *next = tempL3->next;
        delete tempL3;
        tempL3 = next;
    }

    headL1 = nullptr;
    headL2 = nullptr;
    headL3 = nullptr;
    system("cls");
    main();
}

bool Doctor::search(string enteredGmail, string enteredPassword)
{
    DoctorNode *tempDr = headDr;
    while (tempDr != nullptr)
    {
        if (tempDr->email == enteredGmail && tempDr->password == enteredPassword)
        {
            cout << setw(65) << "LOGIN SUCCESSFUL !! " << setw(65) << endl;
            sleep(2);
            email = enteredGmail;
            password = enteredPassword;
            name = tempDr->name;
            course1 = tempDr->course1;
            code1 = tempDr->code1;
            course2 = tempDr->course2;
            code2 = tempDr->code2;
            course3 = tempDr->course3;
            code3 = tempDr->code3;
            numOfCourses = tempDr->numOfCourses;
            return true;
        }
        tempDr = tempDr->next;
    }

    system("color 04");
    cout << setw(05) << "\aError !! " << endl;
    cout << "Login failed. Incorrect Gmail or password." << endl;
    cout << "Try Again !!" << endl;
    sleep(3);
    system("color 07");
    system("pause");
    cout << endl;
    return false;
}

void Doctor::dashboard()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        FrontEndline();
        cout << "\n\n\t\t\t\t        " << x << "             DASHBOARD              " << Y << "\n\n";
        cout << setw(00) << "Welcome back, " << name << "\n\n";
        cout << setw(5) << "[1] - My Courses" << endl;
        cout << setw(5) << "[2] - My Profile" << endl;
        cout << setw(5) << "[3] - Edit On Student " << endl;
        cout << setw(5) << "[4] - Logout" << endl;
        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        switch (choice_fun)
        {
        case 1:
            system("cls");
            myCourses();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            myProfile();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            editstudent();
            break;
        case 4:
            logout();
            break;
        default:
            system("color 04");
            cout << setw(5) << "\aError !! ";
            cout << setw(5) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}

void Doctor::myProfile()
{
    cout << "Your Profile : " << endl;
    cout << "\n\n";
    cout << ">> Personal information" << endl;
    cout << "Email Address : " << email << endl;
    cout << "Country : Egypt" << endl;

    // formatting
    cout
        << "\n";
    cout << ">> Course Details" << endl;
    if (course1 != "NULL")
    {
        cout << "[1] " << setw(40) << left << course1 << setw(10) << right << code1 << endl;
    }
    if (course2 != "NULL")
    {
        cout << "[2] " << setw(40) << left << course2 << setw(10) << right << code2 << endl;
    }
    if (course3 != "NULL")
    {
        cout << "[3] " << setw(40) << left << course3 << setw(10) << right << code3 << endl;
    }
    cout << "\n";
}

void Doctor::myCourses()
{
    cout << "Number of Courses : " << numOfCourses << endl;

    cout << "Your Courses : " << endl;
    cout << endl;
    if (course1 != "NULL")
    {
        cout << "[1] " << setw(40) << left << course1 << setw(10) << right << code1 << endl;
    }
    if (course2 != "NULL")
    {
        cout << "[2] " << setw(40) << left << course2 << setw(10) << right << code2 << endl;
    }
    if (course3 != "NULL")
    {
        cout << "[3] " << setw(40) << left << course3 << setw(10) << right << code3 << endl;
    }
}

void Doctor::editstudent()
{
    myCourses();

    bool flag = true;
    string choice;

    while (flag)
    {
        cout << "\n>> Enter code of course : ";
        cin >> choice;

        if (choice == code1 || choice == code2 || choice == code3)
        {
            accessCourse(choice);
            flag = false;
        }
        else
        {
            system("color 04");
            cout << "\aError: Invalid course code" << endl;
            system("pause");
            system("color 07");
            system("cls");
            flag = false;
        }
    }
}

void Doctor::accessCourse(string codeCourse)
{
    if (codeCourse == "CNE101" || codeCourse == "MAT201" || codeCourse == "CSC102" || codeCourse == "MAT103" || codeCourse == "UNI102")
    {
        Student_nodeL1 *tempL1 = checkL1();
        if (tempL1 != NULL)
        {
            cout << "Editing student in Level 1 ...\n";
            if (codeCourse == "CNE101")
            {
                if (tempL1->electronics != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL1->id << "\n";
                    cout << "GPA: " << tempL1->gpa << "\n";
                    cout << "Electronics : " << tempL1->electronics << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL1->electronics;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "MAT201")
            {
                if (tempL1->linearAlgebra != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL1->id << "\n";
                    cout << "GPA: " << tempL1->gpa << "\n";
                    cout << "Linear Algebra II : " << tempL1->linearAlgebra << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL1->linearAlgebra;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC102")
            {
                if (tempL1->programming != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL1->id << "\n";
                    cout << "GPA: " << tempL1->gpa << "\n";
                    cout << "Fundamentals of Programming I : " << tempL1->programming << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL1->programming;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "MAT103")
            {
                if (tempL1->discreteMath != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL1->id << "\n";
                    cout << "GPA: " << tempL1->gpa << "\n";
                    cout << "Discrete Mathematics : " << tempL1->discreteMath << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL1->discreteMath;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "UNI102")
            {
                if (tempL1->presentation != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL1->id << "\n";
                    cout << "GPA: " << tempL1->gpa << "\n";
                    cout << "Presentation and Communication Skill " << tempL1->presentation << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL1->presentation;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL1();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL1 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else if (codeCourse == "CSC207" || codeCourse == "MAT203" || codeCourse == "CSC204" || codeCourse == "CSC205" || codeCourse == "CNE203" || codeCourse == "SWE201")
    {
        Student_nodeL2 *tempL2 = checkL2();
        if (tempL2 != NULL)
        {
            cout << "Editing student in Level 2 ...\n";
            if (codeCourse == "CSC207")
            {
                if (tempL2->eventDriven != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Event-Driven : " << tempL2->eventDriven << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL2->eventDriven;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "MAT203")
            {
                if (tempL2->probability != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Probability : " << tempL2->probability << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL2->probability;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC204")
            {
                if (tempL2->principles != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Principles : " << tempL2->principles << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL2->principles;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC205")
            {
                if (tempL2->analysis != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Analysis " << tempL2->analysis << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL2->analysis;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CNE203")
            {
                cout << "Current Information:\n";
                if (tempL2->dataCommunications != "No R")
                {
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Data Communications " << tempL2->dataCommunications << endl;
                    cout
                        << "Enter new Score: ";
                    cin >> tempL2->dataCommunications;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "SWE201")
            {
                if (tempL2->informationSystems != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL2->id << "\n";
                    cout << "GPA: " << tempL2->gpa << "\n";
                    cout << "Information Systems " << tempL2->informationSystems << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL2->informationSystems;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL2();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL2 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else if (codeCourse == "CNE310" || codeCourse == "CSC309" || codeCourse == "AIN414" || codeCourse == "CSC303" || codeCourse == "CNE308" || codeCourse == "CSC302")
    {
        Student_nodeL3 *tempL3 = checkL3();
        if (tempL3 != NULL)
        {
            cout << "Editing student in Level 3 ...\n";
            if (codeCourse == "CNE310")
            {
                if (tempL3->sysModeling != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "System Modeling : " << tempL3->sysModeling << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->sysModeling;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC309")
            {
                if (tempL3->dataProgramming != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "Data Science Programming : " << tempL3->dataProgramming << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->dataProgramming;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "AIN414")
            {
                if (tempL3->faultTolerance != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "Fault Tolerance : " << tempL3->faultTolerance << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->faultTolerance;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC303")
            {
                if (tempL3->aiIntro != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "Introduction to Artificial Intelligence " << tempL3->aiIntro << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->aiIntro;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CNE308")
            {
                if (tempL3->infoSecurity != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "Information and Networks Security " << tempL3->infoSecurity << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->infoSecurity;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else if (codeCourse == "CSC302")
            {
                if (tempL3->computerGraphics != "No R")
                {
                    cout << "Current Information:\n";
                    cout << "ID: " << tempL3->id << "\n";
                    cout << "GPA: " << tempL3->gpa << "\n";
                    cout << "Computer Graphics " << tempL3->computerGraphics << endl;
                    cout << "Enter new Score: ";
                    cin >> tempL3->computerGraphics;
                }
                else
                {
                    system("color 04");
                    cout << "Permission Denied Can't Access Course !!" << endl;
                    system("pause");
                    system("color 07");
                    system("cls");
                }
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL3();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL3 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else
    {
        system("color 04");
        cout << "Not Valid or Permission Denied Can't Access Course !!" << endl;
        system("pause");
        system("color 07");
    }
}

// Todo ================================================================================================================================================================
// Todo ------------------------------------------------->                              Class TA                             <------------------------------------------
// Todo ================================================================================================================================================================

class TA : public Admin
{
public:
    void dashboard();
    void main();
    void login();
    void logout();
    bool search(string gmail, string password);
    void myCourses();
    void myProfile();
    void editstudent();
    void accessCourse(string codeCourse);

private:
    string gmail;
    string password;
    string name;
    string course1;
    string code1;
    string course2;
    string code2;
    string numOfCourses;

    string confirmGmail;
    string confirmPassword;
    TANode *next;
};

void TA::main()
{
    bool taFlag = true;

    while (taFlag)
    {
        int taChoice;
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "   WELCOME TO TEACHER ASSISTANT PAGE    " << Y << "\n\n";

        cout << "[1] - Login" << endl;
        cout << "[2] - Exit" << endl;
        cout << "[0] - Go Back to Welcome Page" << endl;
        cout << "\n>> Enter your choice : ";
        if (!(cin >> taChoice))
        {
            cin.clear();                                                   // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            system("color 04");
            cout << "\aInvalid input. Please enter a number.\n";
            system("pause");
            system("color 07");
            system("cls");
            continue; // skip the rest of the loop and start over
        }

        switch (taChoice)
        {
        case 1:
            readCSVL1();
            readCSVL2();
            readCSVL3();
            readCSVTA();
            system("cls");
            login();
            break;
        case 2:
            cout << "Exiting the program . . .\n";
            exit(0);
            break;
        case 0:
            taFlag = false;
            system("cls");
            welcomePage();
            break;
        default:
            system("color 04");
            cout << "\aInvalid choice. Please try again.\n";
            cout << "Try Again !!" << endl;
            sleep(2);
            system("pause");
            system("color 07");
            system("cls");
        }
    }
}

void TA::login()
{
    bool flag = true;

    while (flag)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "         LOGIN TEACHER ASSISTANT        " << Y << "\n\n";
        cout << "Enter Gmail    : ";
        getline(cin, confirmGmail);
        cout << "Enter Password : ";
        getline(cin, confirmPassword);
        if (search(confirmGmail, confirmPassword))
        {
            system("cls");
            dashboard();
        }
        else
        {
            flag = false;
            system("cls");
        }
    }
}

void TA::logout()
{
    cout << setw(62) << "Logging out ";
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << ".";
    }
    email = "";
    password = "";
    name = "";
    course1 = "";
    code1 = "";
    course2 = "";
    code2 = "";
    numOfCourses = "";
    confirmGmail = "";
    confirmPassword = "";

    Student_nodeL1 *tempL1 = headL1;
    Student_nodeL2 *tempL2 = headL2;
    Student_nodeL3 *tempL3 = headL3;

    while (tempL1 != nullptr)
    {
        Student_nodeL1 *next = tempL1->next;
        delete tempL1;
        tempL1 = next;
    }
    while (tempL2 != nullptr)
    {
        Student_nodeL2 *next = tempL2->next;
        delete tempL2;
        tempL2 = next;
    }
    while (tempL3 != nullptr)
    {
        Student_nodeL3 *next = tempL3->next;
        delete tempL3;
        tempL3 = next;
    }

    headL1 = nullptr;
    headL2 = nullptr;
    headL3 = nullptr;

    system("cls");
    main();
}

bool TA::search(string enteredGmail, string enteredPassword)
{
    TANode *tempTA = headTA;
    while (tempTA != nullptr)
    {
        if (tempTA->gmail == enteredGmail && tempTA->password == enteredPassword)
        {
            cout << setw(65) << "LOGIN SUCCESSFUL !! " << setw(65) << endl;
            sleep(2);
            email = enteredGmail;
            password = enteredPassword;
            name = tempTA->name;
            course1 = tempTA->course1;
            code1 = tempTA->code1;
            course2 = tempTA->course2;
            code2 = tempTA->code2;
            numOfCourses = tempTA->numOfCourses;
            return true;
        }
        tempTA = tempTA->next;
    }

    system("color 04");
    cout << setw(05) << "\aError !! " << endl;
    cout << "Login failed. Incorrect Gmail or password." << endl;
    cout << "Try Again !!" << endl;
    sleep(3);
    system("color 07");
    system("pause");
    cout << endl;
    return false;
}

void TA::dashboard()
{
    int choice_fun;
    bool flag = true;

    while (flag)
    {
        FrontEndline();
        cout << "\n\n\t\t\t\t        " << x << "             DASHBOARD              " << Y << "\n\n";
        cout << setw(00) << "Welcome back, " << name << "\n\n";
        cout << setw(05) << "[01] - My Courses" << endl;
        cout << setw(05) << "[02] - My Profile" << endl;
        cout << setw(05) << "[03] - Edit On Student " << endl;
        cout << setw(05) << "[04] - Logout" << endl;
        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        FrontEndline();
        switch (choice_fun)
        {
        case 1:
            system("cls");
            myCourses();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            myProfile();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            editstudent();
            break;
        case 4:
            logout();
            break;
        default:
            system("color 04");
            cout << setw(05) << "\aError !! ";
            cout << setw(05) << "\nPlease enter a valid choice.\n";
            sleep(3);
            system("color 07");
            system("cls");
            break;
        }
    }
}

void TA::myProfile()
{
    cout << "Your Profile : " << endl;
    cout << "\n\n";
    cout << ">> Personal information" << endl;
    cout << "Email Address : " << email << endl;
    cout << "Country : Egypt" << endl;

    cout << "\n";
    cout << ">> Course Details" << endl;
    if (course1 != "NULL")
    {
        cout << "[1] " << setw(40) << left << course1 << setw(10) << right << code1 << endl;
    }
    if (course2 != "NULL")
    {
        cout << "[2] " << setw(40) << left << course2 << setw(10) << right << code2 << endl;
    }

    cout << "\n";
}

void TA::myCourses()
{
    cout << "Number of Courses : " << numOfCourses << endl;

    cout << "Your Courses : " << endl;
    cout << endl;
    if (course1 != "NULL")
    {
        cout << "[1] " << setw(40) << left << course1 << setw(10) << right << code1 << endl;
    }
    if (course2 != "NULL")
    {
        cout << "[2] " << setw(40) << left << course2 << setw(10) << right << code2 << endl;
    }
    cout << "\n";
}
void TA::editstudent()
{
    myCourses();

    bool flag = true;
    string choice;

    while (flag)
    {
        cout << "\n>> Enter code of course : ";
        cin >> choice;

        if (choice == code1 || choice == code2)
        {
            accessCourse(choice);
            flag = false;
        }
        else
        {
            cout << "Error: Invalid course code" << endl;
            system("pause");
            system("cls");
            flag = false;
        }
    }
}
void TA::accessCourse(string codeCourse)
{
    if (codeCourse == "CNE101" || codeCourse == "MAT201" || codeCourse == "CSC102" || codeCourse == "MAT103" || codeCourse == "UNI102")
    {
        Student_nodeL1 *tempL1 = checkL1();
        if (tempL1 != NULL)
        {
            cout << "Editing student in Level 1 ...\n";
            if (codeCourse == "CNE101")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL1->id << "\n";
                cout << "GPA: " << tempL1->gpa << "\n";
                cout << "Electronics : " << tempL1->electronics << endl;
                cout << "Enter new Score: ";
                cin >> tempL1->electronics;
            }
            else if (codeCourse == "MAT201")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL1->id << "\n";
                cout << "GPA: " << tempL1->gpa << "\n";
                cout << "Linear Algebra II : " << tempL1->linearAlgebra << endl;
                cout << "Enter new Score: ";
                cin >> tempL1->linearAlgebra;
            }
            else if (codeCourse == "CSC102")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL1->id << "\n";
                cout << "GPA: " << tempL1->gpa << "\n";
                cout << "Fundamentals of Programming I : " << tempL1->programming << endl;
                cout << "Enter new Score: ";
                cin >> tempL1->programming;
            }
            else if (codeCourse == "MAT103")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL1->id << "\n";
                cout << "GPA: " << tempL1->gpa << "\n";
                cout << "Discrete Mathematics : " << tempL1->discreteMath << endl;
                cout << "Enter new Score: ";
                cin >> tempL1->discreteMath;
            }
            else if (codeCourse == "UNI102")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL1->id << "\n";
                cout << "GPA: " << tempL1->gpa << "\n";
                cout << "Presentation and Communication Skill " << tempL1->presentation << endl;
                cout << "Enter new Score: ";
                cin >> tempL1->presentation;
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL1();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL1 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else if (codeCourse == "CSC207" || codeCourse == "MAT203" || codeCourse == "CSC204" || codeCourse == "CSC205" || codeCourse == "CNE203" || codeCourse == "SWE201")
    {
        Student_nodeL2 *tempL2 = checkL2();
        if (tempL2 != NULL)
        {
            cout << "Editing student in Level 2 ...\n";
            if (codeCourse == "CSC207")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Event-Driven : " << tempL2->eventDriven << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL2->eventDriven;
            }
            else if (codeCourse == "MAT203")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Probability : " << tempL2->probability << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL2->probability;
            }
            else if (codeCourse == "CSC204")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Principles : " << tempL2->principles << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL2->principles;
            }
            else if (codeCourse == "CSC205")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Analysis " << tempL2->analysis << endl;
                cout << "Enter new Score: ";
                cin >> tempL2->analysis;
            }
            else if (codeCourse == "CNE203")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Data Communications " << tempL2->dataCommunications << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL2->dataCommunications;
            }
            else if (codeCourse == "SWE201")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL2->id << "\n";
                cout << "GPA: " << tempL2->gpa << "\n";
                cout << "Information Systems " << tempL2->informationSystems << endl;
                cout << "Enter new Score: ";
                cin >> tempL2->informationSystems;
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL2();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL2 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else if (codeCourse == "CNE310" || codeCourse == "CSC309" || codeCourse == "AIN414" || codeCourse == "CSC303" || codeCourse == "CNE308" || codeCourse == "CSC302")
    {
        Student_nodeL3 *tempL3 = checkL3();
        if (tempL3 != NULL)
        {
            cout << "Editing student in Level 3 ...\n";
            if (codeCourse == "CNE310")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "System Modeling : " << tempL3->sysModeling << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL3->sysModeling;
            }
            else if (codeCourse == "CSC309")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "Data Science Programming : " << tempL3->dataProgramming << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL3->dataProgramming;
            }
            else if (codeCourse == "AIN414")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "Fault Tolerance : " << tempL3->faultTolerance << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL3->faultTolerance;
            }
            else if (codeCourse == "CSC303")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "Introduction to Artificial Intelligence " << tempL3->aiIntro << endl;
                cout << "Enter new Score: ";
                cin >> tempL3->aiIntro;
            }
            else if (codeCourse == "CNE308")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "Information and Networks Security " << tempL3->infoSecurity << endl;
                cout
                    << "Enter new Score: ";
                cin >> tempL3->infoSecurity;
            }
            else if (codeCourse == "CSC302")
            {
                cout << "Current Information:\n";
                cout << "ID: " << tempL3->id << "\n";
                cout << "GPA: " << tempL3->gpa << "\n";
                cout << "Computer Graphics " << tempL3->computerGraphics << endl;
                cout << "Enter new Score: ";
                cin >> tempL3->computerGraphics;
            }
            else
            {
                system("color 04");
                cout << "Permission Denied Can't Access Course !!" << endl;
                system("pause");
                system("color 07");
                system("cls");
            }
            exportToCSVL3();
            system("pause");
            system("cls");
        }
        else
        {
            system("color 04");
            cout << "\aL3 Student Not Found." << endl;
            system("pause");
            system("color 07");
            system("cls");
        }
    }
    else
    {
        system("color 04");
        cout << "Not Valid or Permission Denied Can't Access Course !!" << endl;
        system("pause");
        system("color 07");
    }
}

// Todo ================================================================================================================================================================
// Todo ------------------------------------------------->                            Start Point                            <------------------------------------------
// Todo ================================================================================================================================================================
void FrontEndline()
{
    char u[15], ps[11], r1 = 201, r2 = 200, r3 = 188, r4 = 187, r5 = 205, r6 = 186, r7 = 220, r8 = 202, r9 = 204, r10 = 203, r11 = 206, r12 = 185;
    cout << "\n";
    for (int i = 0; i < 118; i++)
        cout << r7;
}
void welcomePage()
{
    bool flag = true;
    int choice01;

    Admin admin;
    Student student;
    Doctor doctor;
    TA ta;

    while (flag)
    {
        FrontEndline();
        cout << endl;
        cout << "\n\t\t\t\t        "
             << "           AHRAM CANADIAN UNIVERSITY       ";
        cout << "\n\t\t\t        "
             << "   FACULTY OF COMPUTER SCIENCE AND ARTIFICIAL INTELLIGENCE"
             << "\n";
        FrontEndline();
        cout << "\n\n\n\t\t\t\t        " << x << "  WELCOME TO LEARNING MANAGEMENT SYSTEM  " << Y << "\n\n";
        cout << setw(05) << "[1] - Admin" << endl;
        cout << setw(05) << "[2] - Doctor" << endl;
        cout << setw(05) << "[3] - Teaching Assistant" << endl;
        cout << setw(05) << "[4] - Student" << endl;
        cout << setw(05) << "[0] - Exit" << endl;
        cout << "\n";
        // DONE if enter string or any thing not number catch error and ignore value @0xMoataz
        cout << ">> Enter your choice : ";
        if (!(cin >> choice01))
        {
            cin.clear();                                                   // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            system("color 04");
            cout << "\aInvalid input. Please enter a number.\n";
            system("pause");
            system("color 07");
            system("cls");
            continue; // skip the rest of the loop and start over
        }

        switch (choice01)
        {
        case 1:
            system("cls");
            admin.main();
            break;
        case 2:
            system("cls");
            doctor.main();
            break;
        case 3:
            system("cls");
            ta.main();
            break;
        case 4:
            system("cls");
            student.main();
            break;
        case 0:
            system("cls");
            exit(0);
            break;
        default:
            cout << "\n";
            system("color 04");
            cout << setw(5) << "\aError !! " << endl;
            cout << setw(5) << "\nPlease enter a valid choice.\n\n";
            system("pause");
            cout << endl;
            system("color 07");
            system("cls");
            break;
        }
    }
}
int main()
{
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t        " << x << "  WELCOME TO LEARNING MANAGEMENT SYSTEM  \a" << Y << "\n\n";
    char u[15], ps[11], r1 = 201, r2 = 200, r3 = 188, r4 = 187, r5 = 205, r6 = 186, r7 = 220, r8 = 202, r9 = 204, r10 = 203, r11 = 206, r12 = 185;
    // system("color 0A");
    system("color 02");
    cout << "\n\n\t\t\t\t\t\t" << r1;
    for (int i = 1; i < 27; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t\t\t\t        " << r6 << "           START          " << r6 << endl;
    cout << "\t\t\t\t\t\t" << r2;
    for (int i = 1; i < 27; i++)
        cout << r5;
    cout << r3 << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
    system("color 07");
    welcomePage();
    return 0;
}