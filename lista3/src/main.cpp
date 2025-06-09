#include <iostream>
#include <cassert>



class Rectangle
{
    int width;
    int length;
public:
    Rectangle(int w , int h) : width{w} , length{h} {}
    int area() {return width * length;}

  virtual void set_width(int n_width ) { width = n_width; }
  virtual void set_length(int n_length) {length = n_length;}

};


class Square: public Rectangle
{
public:
   explicit Square(int size) : Rectangle(size, size) {}

    void set_length(int n_length)
     { Rectangle::set_length(n_length);
        Rectangle::set_width(n_length);
     }

    void set_width(int n_width) 
    { Rectangle::set_width(n_width);
      Rectangle::set_length(n_width);  
    }

};



void func(Square sqr)
{


}




void test()
{
    Rectangle prostokat{2,5};

    Square kwadrat{3};
    func(kwadrat);
    
    std::cout << "Pole prostokatu " << prostokat.area() << std::endl;
    prostokat.set_width(12);
    std::cout << "Pole prostokatu " << prostokat.area() << std::endl;
    std::cout << "Pole kwadratu " << kwadrat.area() << std::endl;
    kwadrat.set_length(4);
    std::cout << "Pole kwadratu " << kwadrat.area() << std::endl;
    
}




void test_func(Rectangle & rect)
{ 
    rect.set_width(12);

    std::cout << "Pole : " << rect.area() << std::endl;
}



void test_prostokata(Rectangle & rect)
{
    rect.set_length(10);
    rect.set_width(5);

    if(dynamic_cast<Square *>(&rect))
    {
        assert(rect.area() == 20*20);
    }
    else
    {
        assert(rect.area() == 10*20);
    }


   // assert(rect.area()==5*10);
    
}



int main()
{
    Rectangle prostokat{2,5};

    Square kwadrat{3};
    
    

   // test_func(kwadrat);


   test_prostokata(prostokat);



return 0;
}