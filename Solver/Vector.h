#include <stdexcept>
#include <cstddef>


class vector
{
private:

    /*
    * @brief Массив
    */
    int* arr;

    /**
    * @brief Ёмкость массива.
    */
    size_t capacity;

    /**
    * @brief Текущий размер массива.
    */
    size_t size;

    /**
    * @brief Увеличивает ёмкость массива вдвое.
    */
    void resize();

public:

    /**
    * @brief Конструктор по умолчанию. Инициализирует вектор с ёмкостью 1.
    */
    vector();

    /**
    * @brief Деструктор. Освобождает выделенную память.
    */
    ~vector();

    /**
    * @brief Конструктор копирования.
    * @param other Другой вектор для копирования.
    */
    vector(const vector& other);

    /**
    * @brief Оператор присваивания копированием.
    * @param other Другой вектор для копирования.
    * @return Ссылка на текущий вектор.
    */
    vector& operator=(const vector& other);

    /**
    * @brief Конструктор перемещения.
    * @param other Другой вектор для перемещения.
    */
    vector(vector&& other) noexcept;

    /**
    * @brief Оператор присваивания перемещением.
    * @param other Другой вектор для перемещения.
    * @return Ссылка на текущий вектор.
    */
    vector& operator=(vector&& other) noexcept;

    /**
    * @brief Добавляет элемент в конец вектора.
    * @param value Значение для добавления.
    */
    void push_back(int value);

    /**
    * @brief Удаляет последний элемент вектора.
    * @throws std::out_of_range если вектор пуст.
    */
    void pop_back();

    /**
    * @brief Доступ к элементу по заданному индексу.
    * @param index Индекс элемента.
    * @return Ссылка на элемент по заданному индексу.
    * @throws std::out_of_range если индекс выходит за границы.
    */
    int& operator[](size_t index);

    /**
    * @brief Доступ к элементу по заданному индексу (константная версия).
    * @param index Индекс элемента.
    * @return Константная ссылка на элемент по заданному индексу.
    * @throws std::out_of_range если индекс выходит за границы
    */
    const int& operator[](size_t index) const;

    /**
    * @brief Возвращает текущий размер вектора.
    * @return Текущий размер вектора.
    */
    size_t get_size() const;

    /**
    * @brief Возвращает текущую ёмкость вектора.
    * @return Текущая ёмкость вектора.
    */
    size_t get_capacity() const;

    /**
    * @brief Проверяет, пуст ли вектор.
    * @return true, если вектор пуст, иначе false.
    */
    bool is_empty() const;
};
