#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Class to store the data
class student
{
     int University_RollNo,University_RegistrationNo,;
     char name[50];
     double average;
     char grade;
     double SGPA1;
     double SGPA2;
     double SGPA3;
     double SGPA4;
     double SGPA5;
     double SGPA6;
     double SGPA7;
     double SGPA8;

public:
     void FirstSem()
     {
          cin>>SGPA1;
     }
     void SecondSem()
     {
          cin>>SGPA2;
     }
     void ThirdSem()
     {
          cin>>SGPA3;
     }
     void FourthSem()
     {
          cin>>SGPA4;
     }
     void FifthSem()
     {
          cin>>SGPA5;
     }
     void SixthSem()
     {
          cin>>SGPA6;
     }
     void SeventhSem()
     {
          cin>>SGPA7;
     }
     void EighthSem()
     {
          cin>>SGPA8;
     }
     void getdata();
     void showdata() const;
     void calculate();
     int retrollno() const;
};

void student::calculate()
{
     average = ((SGPA1+SGPA2)+(SGPA3+SGPA4)+(SGPA5+SGPA6)*1.5+(SGPA7+SGPA8)*1.5) / 5.0;
     if (average >= 10)
          grade = 'O';
     else if (average >= 9)
          grade = 'E';
     else if (average >= 8)
          grade = 'A';
     else if (average >= 7)
          grade = 'B';
     else if (average >= 6)
          grade = 'C';
     else if (average >= 5)
          grade = 'D';
     else if (average >= 2)
          grade = 'F';
     else
          grade = 'I';
}

void student::getdata()
{
     cout << "\nEnter student's roll number: ";
     cin >> University_RollNo;
     cout<< "\nEnter student's registration number: ";
     cin>> University_RegistrationNo;
     cout << "\n\nEnter student name: ";
     cin.ignore();
     cin.getline(name, 50);
     cout << "\nAll SGPA should be out of 10";
     cout << "\nEnter SGPA of first Sem: ";
     FirstSem();
     cout << "\nEnter SGPA of second Sem:  ";
     SecondSem();
     cout << "\nEnter SGPA of third Sem:  ";
     ThirdSem();
     cout << "\nEnter SGPA of fourth Sem: ";
     FourthSem();
     cout << "\nEnter SGPA of fifth Sem:  ";
     FifthSem();
     cout << "\nEnter SGPA of sixth Sem:  ";
     SixthSem();
     cout << "\nEnter SGPA of seventh Sem: ";
     SeventhSem();
     cout << "\nEnter SGPA of eighth Sem:  ";
     EighthSem();
     calculate();
}
void student::showdata() const
{
     cout << "\nRoll number of student : " << University_RollNo;
     cout << "\nRegistration number of student : " << University_RegistrationNo;
     cout << "\nName of student : " << name;
     cout << "\nSGPA of First Sem : " << SGPA1;
     cout << "\nSGPA of Second Sem : " << SGPA2;
     cout << "\nSGPA of Third Sem : " << SGPA3;
     cout << "\nSGPA of Fourth Sem : " << SGPA4;
     cout << "\nSGPA of Fifth Sem : " << SGPA5;
     cout << "\nSGPA of Sixth Sem : " << SGPA6;
     cout << "\nSGPA of Seventh Sem : " << SGPA7;
     cout << "\nSGPA of Eighth Sem : " << SGPA8;
     cout << "\nAverage Marks :" << average;
     cout << "\nGrade of student is :" << grade;
}
int student::retrollno() const
{
     return University_RollNo;
}
// function declaration
void create_student();
void display_sp(int);     // display particular record
void display_all();       // display all records
void delete_student(int); // delete particular record
void change_student(int); // edit particular record
// MAIN
int main()
{
     char ch;
     cout << setprecision(2);
     do
     {
          char ch;
          int num;
          system("cls");
          cout << "\n\n\n\tMENU";
          cout << "\n\n\t1.Create student record";
          cout << "\n\n\t2.Search student record";
          cout << "\n\n\t3.Display all students records ";
          cout << "\n\n\t4.Delete student record";
          cout << "\n\n\t5.Modify student record";
          cout << "\n\n\t6.Exit";
          cout << "\n\n\What is your Choice (1/2/3/4/5/6) ";
          cin >> ch;
          system("cls");
          switch (ch)
          {
          case '1':
               create_student();
               break;
          case '2':
               cout << "\n\n\tEnter The roll number ";
               cin >> num;
               display_sp(num);
               break;
          case '3':
               display_all();
               break;
          case '4':
               cout << "\n\n\tEnter The roll number: ";
               cin >> num;
               delete_student(num);
               break;
          case '5':
               cout << "\n\n\tEnter The roll number ";
               cin >> num;
               change_student(num);
               break;
          case '6':
               cout << "Exiting, Thank you!";
               exit(0);
          }
     } while (ch != '6');
     return 0;
}
// write student details to file
void create_student()
{
     student stud;
     ofstream oFile;
     oFile.open("student.dat", ios::binary | ios::app);
     stud.getdata();
     oFile.write(reinterpret_cast<char *>(&stud), sizeof(student));
     oFile.close();
     cout << "\n\nStudent record Has Been Created ";
     cin.ignore();
     cin.get();
}
// read file records
void display_all()
{
     student stud;
     ifstream inFile;
     inFile.open("student.dat", ios::binary);
     if (!inFile)
     {
          cout << "File could not be opened !! Press any Key to exit";
          cin.ignore();
          cin.get();
          return;
     }
     cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
     while (inFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))
     {
          stud.showdata();
          cout << "\n\n====================================\n";
     }
     inFile.close();
     cin.ignore();
     cin.get();
}
// read specific record based on roll number
void display_sp(int n)
{
     student stud;
     ifstream iFile;
     iFile.open("student.dat", ios::binary);
     if (!iFile)
     {
          cout << "File could not be opened... Press any Key to exit";
          cin.ignore();
          cin.get();
          return;
     }
     bool flag = false;
     while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))
     {
          if (stud.retrollno() == n)
          {
               stud.showdata();
               flag = true;
          }
     }
     iFile.close();
     if (flag == false)
          cout << "\n\nrecord does not exist";
     cin.ignore();
     cin.get();
}
// modify record for specified roll number
void change_student(int n)
{
     bool found = false;
     student stud;
     fstream fl;
     fl.open("student.dat", ios::binary | ios::in | ios::out);
     if (!fl)
     {
          cout << "File could not be opened. Press any Key to exit...";
          cin.ignore();
          cin.get();
          return;
     }
     while (!fl.eof() && found == false)
     {
          fl.read(reinterpret_cast<char *>(&stud), sizeof(student));
          if (stud.retrollno() == n)
          {
               stud.showdata();
               cout << "\n\Enter new student details:" << endl;
               stud.getdata();
               int pos = (-1) * static_cast<int>(sizeof(stud));
               fl.seekp(pos, ios::cur);
               fl.write(reinterpret_cast<char *>(&stud), sizeof(student));
               cout << "\n\n\t Record Updated";
               found = true;
          }
     }
     fl.close();
     if (found == false)
          cout << "\n\n Record Not Found ";
     cin.ignore();
     cin.get();
}
// delete record with particular roll number
void delete_student(int n)
{
     student stud;
     ifstream iFile;
     iFile.open("student.dat", ios::binary);
     if (!iFile)
     {
          cout << "File could not be opened... Press any Key to exit...";
          cin.ignore();
          cin.get();
          return;
     }
     ofstream oFile;
     oFile.open("Temp.dat", ios::out);
     iFile.seekg(0, ios::beg);
     while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))
     {
          if (stud.retrollno() != n)
          {
               oFile.write(reinterpret_cast<char *>(&stud), sizeof(student));
          }
     }
     oFile.close();
     iFile.close();
     remove("student.dat");
     rename("Temp.dat", "student.dat");
     cout << "\n\n\tRecord Deleted ..";
     cin.ignore();
     cin.get();
}