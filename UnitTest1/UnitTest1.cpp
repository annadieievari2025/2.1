#include "pch.h"
#include "CppUnitTest.h"
#include "../2.2/Vector.h"   
#include "../2.2/Vector.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestVectorAddition)
		{
			Vector v1(3, 2); // [2,2,2]
			Vector v2(3, 3); // [3,3,3]

			Vector result = v1 + v2;

			Assert::AreEqual(5.0f, result[0]);
			Assert::AreEqual(5.0f, result[1]);
			Assert::AreEqual(5.0f, result[2]);
		}
	};
}