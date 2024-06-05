#include "Vector.h"
#include <initializer_list>
#include <string>


class stack
{
private:
    vector data;

public:

    /**
    * @brief Конструктор по умолчанию.
    */
    stack();

    /**
    * @brief Конструктор с инициализатором списка.
    * @param initList Список значений для инициализации стека.
    */
    stack(std::initializer_list<int> initList);

    /**
    * @brief Добавляет элемент в стек.
    * @param value Значение для добавления.
    */
    void push(int value);

    /**
    * @brief Удаляет верхний элемент из стека.
    * @throws std::out_of_range если стек пуст.
    */
    void pop();

    /**
    * @brief Возвращает верхний элемент стека без удаления.
    * @return Верхний элемент стека.
    * @throws std::out_of_range если стек пуст.
    */
    int peek() const;

    /**
    * @brief Проверяет, пуст ли стек.
    * @return true, если стек пуст, иначе false.
    */
    bool is_empty() const;

    /**
    * @brief Возвращает строковое представление стека.
    * @return Строка, представляющая стек.
    */
    std::string to_string() const;
};