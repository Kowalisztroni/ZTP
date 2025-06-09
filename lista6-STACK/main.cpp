#include <iostream>
#include "Stack.h"
#include <vector>

using namespace std;


int main() {


   vector<int> val (20);

    cout <<  val.size() << endl;
    cout << val.capacity() << endl;



    val.reserve(50);

    cout << val.size() << endl;
    cout << val.capacity() << endl;



    val.push_back(5);



    val.push_back(3);
    val.push_back(2);


    for(auto i = 0; i < 15; ++i)
    {
        val.push_back(i);
    }


    cout << val.size() << endl;
    cout << val.capacity() << endl;



  //  int d = 5;


 //   Stack<int> data;


 //   data.push(d);

 //   data.display();







    return 0;
}
