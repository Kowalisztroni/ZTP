#include <iostream>


void test1()
{

    std::cout << "test1" << std::endl;

}

void test2()
{
    std::cout << "test2" << std::endl;


}

void test3()
{

    std::cout << "test3" << std::endl;

}

void(*func[])() = {test1, test2, test3};


int main()
{
    func[1]();
    return 0;
}