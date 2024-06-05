#include "CppUnitTest.h"
#include <C:\Учеб\ТКИ-141-2\Stack\Solver\stack.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(SolverTests)
    {
    public:

        TEST_METHOD(TestInitializerListConstructor)
        {
            stack stack({ 1, 2, 3 });
            Assert::AreEqual(std::string("1 2 3 "), stack.to_string(), L"Стек должен содержать '1 2 3 '.");
        }

        TEST_METHOD(TestPush)
        {
            stack stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);
            Assert::AreEqual(std::string("1 2 3 "), stack.to_string(), L"Стек должен содержать '1 2 3 '.");
        }

        TEST_METHOD(TestPop)
        {
            stack stack({ 1, 2, 3 });
            stack.pop();
            Assert::AreEqual(std::string("1 2 "), stack.to_string(), L"Стек должен содержать '1 2 ' после удаления верхнего элемента.");
        }

        TEST_METHOD(TestPeek)
        {
            stack stack({ 1, 2, 3 });
            Assert::AreEqual(3, stack.peek(), L"Головной элемент должен быть 3.");
        }

        TEST_METHOD(TestIsEmpty)
        {
            stack stack;
            Assert::IsTrue(stack.is_empty(), L"Стек должен быть пустым.");
            stack.push(1);
            Assert::IsFalse(stack.is_empty(), L"Стек не должен быть пустым.");
        }

        TEST_METHOD(TestPopEmptyStack)
        {
            stack stack;
            auto func = [&]() { stack.pop(); };
            Assert::ExpectException<std::out_of_range>(func, L"Должно выбрасываться исключение std::out_of_range при попытке pop на пустом стеке.");
        }

        TEST_METHOD(TestPeekEmptyStack)
        {
            stack stack;
            auto func = [&]() { stack.peek(); };
            Assert::ExpectException<std::out_of_range>(func, L"Должно выбрасываться исключение std::out_of_range при попытке peek на пустом стеке.");
        }
    };
}