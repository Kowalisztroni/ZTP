#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct Student
{
    std::string imie;
    int indeks;
};




void cw1() // copy , remove
{


    vector<int> val = {1,2,3,4,5};

    vector<int> val_copy;

    copy(val.begin(),val.end(), back_inserter(val_copy));


    for(auto i : val)
    {
        cout << i << " ";

    }
    cout << "\n";


    for(auto i : val_copy)
    {
        cout << i << " ";

    }
    cout << "\n";

    //   auto val_removed = remove(val.begin(),val.end(),);


    for(auto i : val)
    {
        cout << i << " ";

    }
    cout << "\n";
}

vector<Student> sortuj_stuednt(vector<Student> &s)
{

 //   sort(s.begin(),s.end());




    return s;
}




// sort
void cw2()
{
    Student s1 = {"Patryk",267671};

    Student s2 = {"Jony",3024};

    Student s3 = {"Jims",260213};

    vector<Student> students = {s1,s2,s3};




}


void cw3() // transform
{

}

// generate jescze


int main() {






    return 0;
}
