#include <iostream>
#include <array>
#include "stack-t.h"

int main() 
{
    Stack<int> s;
    Stack<std::string> s2;
    
    for(int i=0; i<5; ++i)
        s.push(i/2.0);

    for(int i=0; i<5; ++i)  
        std::cout << s.pop() << std::endl;


    s2.push("Ala");
    s2.push("ma");
    s2.push("kota");

    for(int i=0; i<3; ++i)  
        std::cout << s2.pop() << std::endl;

    std::array<int, 10> arr;

}