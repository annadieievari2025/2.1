#include "pch.h"
#include "CppUnitTest.h"
#include "../2.1/IntRange.h"
#include "../2.1/IntRange.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestRangeCheck)
		{
			IntRange r(2, 10);

			bool result = r.rangeCheck(5);

			Assert::IsTrue(result);
		}

	};
}