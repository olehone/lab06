#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int size = 10;
			int test[size] = { 1, 0 , 2, 4, -2, 1, 4, 6, 0, 12 };
			int S = Sum(test, size);
			Assert::AreEqual(S, 15);
		}
	};
}
