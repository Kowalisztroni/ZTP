#ifndef STACK_T_H__
#define STACK_T_H__

template<typename T>
class Stack {
    T data[100];
    int top = 0;
public:
    Stack();
    void push(const T & value);
    T pop();
};

template<typename T>
Stack<T>::Stack() 
{

}

template<typename T>
void Stack<T>::push(const T & value) {
    data[top++] = value;
}

template<typename T>
T Stack<T>::pop() {
    return data[--top];
}



#endif