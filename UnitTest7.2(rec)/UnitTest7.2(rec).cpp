#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { { 1, 2, 3 }, { 3, 2, 1 }, { 2, 1, 3 } };
			int* a1[3] = { a[0], a[1], a[2] };

			Sort(a1, 3, 0);

			Assert::AreEqual(3,a[0][0]);
			Assert::AreEqual(2,a[1][1]);
			Assert::AreEqual(1,a[2][2]);


		}
	};
}
