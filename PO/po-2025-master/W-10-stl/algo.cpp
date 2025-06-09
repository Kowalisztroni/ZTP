#include <iostream>
#include <algorithm>
#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <fmt/std.h>


template <typename T>
std::ostream & operator << (std::ostream & str, const std::vector<T> & vec)
{
    for (auto & v: vec)
        str << v << " ";
    return str;
}

bool is_negative(int x)
{
    return x < 0;
}

class TesterParzystosci
{
    public:
    bool operator() (int x);
};

bool TesterParzystosci::operator() (int x)
{
    return (x%2) == 0;
}



void test1()
{
    std::vector<int> v1 {1,-4,7,5,2,1,0,-5};

    fmt::println("Wartość 2 występuje {} razy", 
        std::count(begin(v1), end(v1), 2)    
    );
    fmt::println("Wartość -7 występuje {} razy", 
        std::count(v1.begin(), v1.end(), -7)    
    );

    fmt::println("Wartość ujemna występuje {} razy", 
    std::count_if(begin(v1), end(v1),
        is_negative
    ));

    TesterParzystosci p;
    fmt::println("Wartość parzysta występuje {} razy", 
        std::count_if(begin(v1), end(v1),
            p
            // TesterParzystosci{}
        ));

    auto abs_eq_5 = [] ( int value ) -> bool {return abs(value) == 5; };
    // [ ] - capture group
    // [ & ] - "złap" wszytko przez referencję
    // ( ) - parametry wywołania naszej funkcji anonimowej
    // -> bool - typ zwracanej wartości (opcjonalny)
    // { } - "ciało" funkcji

    fmt::println("Wartość 5 lub -5 występuje {} razy", 
        std::count_if(begin(v1), end(v1),
            abs_eq_5
        ));

    fmt::println("Wartość dodatnia występuje {} razy", 
        std::count_if(begin(v1), end(v1),
            [] (auto v) { return v>0; }
        ));
    std::vector<std::string> v2 {"Ala", "ma", "kota"};  
    fmt::println("Słowo zaczynające się od wielkiej litery występuje {} razy", 
        std::count_if(begin(v2), end(v2),
            [] (auto elem) { return isupper(elem[0]); }
        ));      

}

void fun(int val)
{
    std::cout << val << std::endl;
}

void test2()
{
    std::vector<int> v1 {1,-4,7,5,2,1,0,-5};
    std::for_each(v1.begin(), v1.end(), fun);
}

void test3()
{
    std::vector<int> v1 {1,1,0,-5};
    std::vector<int> v2;

    v2.resize(v1.size());
    std::copy(v1.begin(), v1.end(), v2.begin());
    fmt::println("v2={}", v2);

    std::vector<int> v3 {1, 1, 1};
    std::copy(v1.begin(), v1.end(), std::back_inserter(v3));
    fmt::println("v3={}", v3);
}
   
struct Student
{
    std::string imie;
    int indeks;
    float srednia;
};

std::ostream & operator << (std::ostream & str, const Student & s)
{
    str << s.imie << "\t" << s.indeks << "\t" << s.srednia << std::endl;
    return str;
}

void test4()
{
    std::vector<int> v1 {1,-4,7,5,2,1,0,-5};
    std::sort(v1.begin(), v1.end());   // operator<
    fmt::println("v1={}", v1);

    std::sort(v1.begin(), v1.end(),
      [] (int a, int b) { return a>b; }
    );
    fmt::println("v1={}", v1);
    std::sort(v1.begin(), v1.end(),
     [] (int a, int b) { return a*a<b*b; }
    );
    fmt::println("v1={}", v1);

    std::vector<Student> vs {{"Jan", 12235, 3.0}, {"Ewa", 223344, 5.5}, {"Ala", 665544, 4.0}};
    std::cout << vs << std::endl;
    // fmt::println("vs={}", vs);
    std::sort(vs.begin(), vs.end(),
     [] (const Student & s1, const Student & s2) { return s1.indeks>s2.indeks; }
    );
    std::cout << vs << std::endl;


}


int main() 
{
    // std::vector<int> v1 {1,4,7,2,1,0,5};
    // std::cout << v1 << std::endl;
    // fmt::println("{}", v1);

    // test1();
    // test2();
    // test3();
    test4();
}