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
			int test[size] = { -11,1,-56,3,0,-4,8,13,27,58 };
			int S = Sum(test, size);
			Assert::AreEqual(S, 6);
		}
	};
}
