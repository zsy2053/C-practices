#include <string>
#include <iostream>
using namespace std;

class Student
{
  private:
    int age;
    string name;
    int id;
    int avgGrade;
  public:
    Student(int age, string name, int id, int firstGrade = 0, int secondGrade = 0, int thirdGrade = 0, int fourthGrade = 0);
    void printStudent();
    int getAge();
    string getName();
    int getId();
    int getAvg();
};

Student:: Student(int age, string name, int id, int firstGrade, int secondGrade, int thirdGrade, int fourthGrade)
{
  this -> age = age;
  this -> name = name;
  this -> id = id;
  this -> avgGrade = (firstGrade + secondGrade + thirdGrade + fourthGrade) / 4;
}
int Student:: getAge()
{
  return this -> age;
}
string Student:: getName()
{
  return this -> name;
}
int Student:: getId()
{
  return this -> id;
}
int Student:: getAvg()
{
  return this -> avgGrade;
}
void Student:: printStudent()
{
  cout<<getName()<<", "<<getAge()<<", "<<getId()<<","<<getAvg()<<endl;
}

int main() {
  Student s(15, "Tom", 7458, 80, 85, 90, 100);
  s.printStudent();
}
