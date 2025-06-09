//
// Created by kowal on 20.05.2025.
//

#ifndef LISTA6_STACK_STACK_H
#define LISTA6_STACK_STACK_H

#include <iostream>

template <typename T>
class Stack
{

    T data[100] = {0};
    int top = 0;

public:

    void push(T value);
    T pop();
    void display();


};

template<typename T>
void Stack<T>::display() {
    for(auto i = 0; i < 100;++i)
    {
        std::cout << data[i] << std::endl;
    }
}


template<typename T>
void Stack<T>::push(T value) {
    data[top++] = value;
}


template<typename T>
T Stack<T>::pop() {

    return data[--top];
}





#endif //LISTA6_STACK_STACK_H
