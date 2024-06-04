#include "CppUnitTest.h"
#include "Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(SolverTests)
    {
    public:

	TEST_METHOD(TestInitializerListConstructor)
        {
            Stack stack({ 1, 2, 3 });
            Assert::AreEqual(std::string("1 2 3 "), stack.toString(), L"Стек должен содержать '1 2 3 '.");
        }
	    
        TEST_METHOD(TestPush)
        {
            Stack stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);
            Assert::AreEqual(std::string("1 2 3 "), stack.toString(), L"Стек должен содержать '1 2 3 '.");
        }

        TEST_METHOD(TestPop)
        {
            Stack stack({ 1, 2, 3 });
            stack.pop();
            Assert::AreEqual(std::string("1 2 "), stack.toString(), L"Стек должен содержать '1 2 ' после удаления верхнего элемента.");
        }

        TEST_METHOD(TestPeek)
        {
            Stack stack({ 1, 2, 3 });
            Assert::AreEqual(3, stack.peek(), L"Головной элемент должен быть 3.");
        }

        TEST_METHOD(TestIsEmpty)
        {
            Stack stack;
            Assert::IsTrue(stack.isEmpty(), L"Стек должен быть пустым.");
            stack.push(1);
            Assert::IsFalse(stack.isEmpty(), L"Стек не должен быть пустым.");
        }

        TEST_METHOD(TestPopEmptyStack)
        {
            Stack stack;
            auto func = [&]() { stack.pop(); };
            Assert::ExpectException<std::out_of_range>(func, L"Должно выбрасываться исключение std::out_of_range при попытке pop на пустом стеке.");
        }

        TEST_METHOD(TestPeekEmptyStack)
        {
            Stack stack;
            auto func = [&]() { stack.peek(); };
            Assert::ExpectException<std::out_of_range>(func, L"Должно выбрасываться исключение std::out_of_range при попытке peek на пустом стеке.");
        }
    };
}
