#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class student
{
private:
  string name[100];
  float fees[100];
  int standard[100];
  int enroll_no[100];

public:
  void mainmenu()
  {
    cout << "1:add student" << endl;
    cout << "2:show record a students" << endl;
    cout << "3:delete a students" << endl;
  }

  void mainlogic(int);
};

void student::mainlogic(int size)
{
  int opt;

  cout << "enter option : " << endl;
  cin >> opt;

  if (opt == 1)
  {

    for (int i = 0; i < size; i++)
    {
      cout << "enter student detail: " << i + 1;
      cout << "enter a student  name: ";
      cin >> name[i];
      cout << "enter student total payable fess:";
      cin >> fees[i];
      cout << "enter student standard: ";
      cin >> standard[i];
      cout << "enter studnet id no: ";
      cin >> enroll_no[i];
      cout << endl;
    }
    cout << "student added successfully" << endl;
    cout << endl;
    mainlogic(size);
  }

  else if (opt == 2)
  {
    for (int i = 0; i < size; i++)
    {
      cout << "|----------------------------------------------------------------------------------------|" << endl;
      cout << setw(10) << "NAME" << setw(15) << "FEES" << setw(15) << "STANDARD" << setw(15) << "ENROLL NO" << setw(15) << endl;
      cout << setw(10) << name[i] << setw(15) << fees[i] << setw(10) << standard[i] << setw(15) << enroll_no[i] << setw(15) << endl;
      cout << endl;
      cout << "|------------------------------------------------------------------------------------------|" << endl;
      cout<<endl;
      mainlogic(size);
    }
  }
  else if (opt == 3)
  {
    string name_delete;
    bool flag = false;
    cout << "enter name you want to remove from this list:";
    cin >> name_delete;

    for (int i = 0; i < size; i++)
    {
      if (name_delete == name[i])
      {
        enroll_no[i] = 0;
        standard[i] = 0;
        fees[i] = 0;

        flag = true;
      }
    }

    if (flag == true)
    {

      cout << "student remove : " << endl;
      mainlogic(size);
    }
    else
    {
      cout << "student not remove" << endl;
    }
  }
}

int main()
{
  int size;

  student main;
  main.mainmenu();
  cout << "enter how many student you want to add: " << endl;
  cin >> size;
  main.mainlogic(size);
}