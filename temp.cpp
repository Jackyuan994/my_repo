#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void print(T& a) {
    std::cout << a << std::endl;
}

template<>
void print<bool>(bool& a) {
    std::cout << (a ? "true" : "false") << std::endl;
}

int main() {    
    int a = 10;
    print<int>(a);
    bool b = true;
    print(b);
    return 0;
}