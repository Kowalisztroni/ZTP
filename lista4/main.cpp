#include <iostream>
#include <string>

class Osoba {
    std::string imie;

public:
    
    Osoba(std::string imie) {
        this->imie = imie;
    }

     virtual  void info() {
        std::cout << "imie: " << imie << std::endl;
    }
};

class Student : public Osoba {
    int index;

public:
    Student(std::string imie_n, int index_n) : Osoba(imie_n), index(index_n) {}

    void info() {
        Osoba::info(); 
        std::cout << "index: " << index << std::endl;
    }
};




void func(Osoba *o) { o ->info();}




int main() {
   

    

    Osoba o1{"patryk"};
    o1.info();
   
    std::cout << sizeof(o1) <<  std::endl;
   
    Student s1{"anna", 267671};
    s1.info();
    std::cout << sizeof(s1) <<  std::endl;

    func(&o1);
    func(&s1);



    return 0;
}