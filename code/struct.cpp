#include<iostream>
#include<string>
using namespace std;
struct student
{
    string name;
    int age;
    int noi;
    void exercise(int year);
};
void student::exercise(int year)
{
    name=this->name;
    age=this->age+year;
    for(int i=0;i<year;i++)
    {
        noi=this->noi*1.2;
        if(noi>600)
        {
            noi=600;
            break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        student stu;
        cin>>stu.name>>stu.age>>stu.noi;
        stu.exercise(1);
        cout<<stu.name<<" "<<stu.age<<" "<<stu.noi<<endl;
    }
}