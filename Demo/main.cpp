#include <iostream>
#include <C:\Учеб\ТКИ-141-2\Stack\Solver\stack.h>

int main() {
    stack stack({ 1, 2, 3, 4, 5 });
    std::cout << "Начальный стек: " << stack.to_string() << std::endl;

    stack.push(6);
    std::cout << "После push(6): " << stack.to_string() << std::endl;

    stack.pop();
    std::cout << "После pop(): " << stack.to_string() << std::endl;

    std::cout << "Головной элемент (peek): " << stack.peek() << std::endl;
    std::cout << "Стек пуст? " << (stack.is_empty() ? "Yes" : "No") << std::endl;

    return 0;
}
