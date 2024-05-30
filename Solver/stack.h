#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <initializer_list>

class Stack {
private:
    std::vector<int> data;

public:

    /**
    * @brief Конструктор по умолчанию.
    */
    Stack();

    /**
    * @brief Конструктор со списком инициализации.
    * @param initList Список инициализации элементов стека.
    */
    Stack(std::initializer_list<int> initList);

    /**
    * @brief Конструктор копирования.
    * @param other Другой объект Stack для копирования.
    */
    Stack(const Stack& other);

    /**
    * @brief Конструктор перемещения.
    * @param other Другой объект Stack для перемещения.
    */
    Stack(Stack&& other) noexcept;

    /**
    * @brief Деструктор
    */
    ~Stack();

    /**
    * @brief Оператор присваивания копированием.
    * @param other Другой объект Stack для копирования.
    * @return Ссылка на текущий объект Stack.
    */
    Stack& operator=(const Stack& other);

    /**
    * @brief Оператор присваивания перемещением.
    * @param other Другой объект Stack для перемещения.
    * @return Ссылка на текущий объект Stack.
    */
    Stack& operator=(Stack&& other) noexcept;

    /**
    * @brief Метод для добавления элемента в стек.
    * @param value Значение добавляемого элемента
    */
    void push(int value);

    /**
    * @brief Метод для удаления элемента из стека.
    * @throw std::out_of_range Если стек пуст.
    */
    void pop();

    /**
    * @brief Метод для чтения головного элемента стека.
    * @return Значение головного элемента.
    * @throw std::out_of_range Если стек пуст.
    */
    int peek() const;

    /**
    * @brief Метод для проверки, пуст ли стек.
    * @return true, если стек пуст, иначе false.
    */
    bool isEmpty() const;

    /**
     * @brief Метод для получения строки с содержимым стека.
     * @return Строка с элементами стека.
     */
    std::string toString() const;
};

#endif // STACK_H
