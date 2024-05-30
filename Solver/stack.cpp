#include "Stack.h"
#include <stdexcept>
#include <sstream>

Stack::Stack() : data() {}

Stack::Stack(std::initializer_list<int> initList) : data(initList) {}

Stack::Stack(const Stack& other) : data(other.data) {}

Stack::Stack(Stack&& other) noexcept : data(std::move(other.data)) {}

Stack::~Stack() {}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
    }
    return *this;
}

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    data.pop_back();
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}

std::string Stack::toString() const {
    std::ostringstream oss;
    for (const int& value : data) {
        oss << value << " ";
    }
    return oss.str();
}
