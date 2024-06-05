#include "Stack.h"
#include <stdexcept>
#include <sstream>


stack::stack(std::initializer_list<int> initList) : data()
{
    for (int value : initList)
    {
        data.push_back(value);
    }
}

void stack::push(int value)
{
    data.push_back(value);
}

void stack::pop()
{
    if (data.is_empty())
    {
        throw std::out_of_range("Стек пуст");
    }
    data.pop_back();
}

int stack::peek() const
{
    if (data.is_empty())
    {
        throw std::out_of_range("Стек пуст");
    }
    return data[data.get_size() - 1];
}

bool stack::is_empty() const
{
    return data.is_empty();
}

std::string stack::to_string() const
{
    std::ostringstream oss;
    for (size_t i = 0; i < data.get_size(); ++i)
    {
        oss << data[i] << " ";
    }
    return oss.str();
}
