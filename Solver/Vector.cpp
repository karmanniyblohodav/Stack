#include "Vector.h"

vector::vector()
    : arr(new int[1]), capacity(1), size(0) {}

vector::~vector()
{
    delete[] arr;
}

vector::vector(const vector& other)
    : arr(new int[other.capacity]), capacity(other.capacity), size(other.size)
{
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

vector& vector::operator=(const vector& other)
{
    if (this != &other)
    {
        delete[] arr;
        arr = new int[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

vector::vector(vector&& other) noexcept
    : arr(other.arr), capacity(other.capacity), size(other.size)
{
    other.arr = nullptr;
    other.capacity = 0;
    other.size = 0;
}

vector& vector::operator=(vector&& other) noexcept
{
    if (this != &other)
    {
        delete[] arr;
        arr = other.arr;
        capacity = other.capacity;
        size = other.size;
        other.arr = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void vector::resize()
{
    size_t new_capacity = capacity * 2;
    int* new_arr = new int[new_capacity];
    for (size_t i = 0; i < size; ++i)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

void vector::push_back(int value)
{
    if (size == capacity)
    {
        resize();
    }
    arr[size++] = value;
}

void vector::pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("Vector is empty");
    }
    --size;
}

int& vector::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

const int& vector::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

size_t vector::get_size() const
{
    return size;
}

size_t vector::get_capacity() const
{
    return capacity;
}

bool vector::is_empty() const
{
    return size == 0;
}
