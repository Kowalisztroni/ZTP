#include <iostream>

class Stack {
    int data[100];
    int top = 0;
public:
    void push(int value);
    int pop();
};

void Stack::push(int value) {
    data[top++] = value;
}

int Stack::pop() {
    return data[--top];
}

int main() 
{
    Stack s;
    
    for(int i=0; i<5; ++i)
        s.push(i);

    for(int i=0; i<5; ++i)  
        std::cout << s.pop() << std::endl;

}