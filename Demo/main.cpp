#include <iostream>
#include "..\Solver\stack.h"

int main() {
    Stack stack({ 1, 2, 3, 4, 5 });
    std::cout << "Начальный стек: " << stack.toString() << std::endl;

    stack.push(6);
    std::cout << "После push(6): " << stack.toString() << std::endl;

    stack.pop();
    std::cout << "После pop(): " << stack.toString() << std::endl;

    std::cout << "Головной элемент (peek): " << stack.peek() << std::endl;
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
