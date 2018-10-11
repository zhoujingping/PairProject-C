#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int x= charcount("input1.txt",  "out.txt");
			Assert::AreEqual(sum, 527);
		}
		TEST_METHOD(TestMethod2)
		{
			int x=linecount("input1.txt", "out.txt");
			Assert::AreEqual(x, 6);
		}
		TEST_METHOD(TestMethod3)
		{
			int x=wordcount("input1.txt", "out.txt", 1);
			Assert::AreEqual(x, 19);
		}
		TEST_METHOD(TestMethod4)
		{
			char c = '9';
			int x=ifchar(c);
			Assert::AreEqual(x, 0);
		}
		TEST_METHOD(TestMethod5)
		{
			int x= charcount("input2.txt",  "out.txt");
			Assert::AreEqual(x, 122);
			
		}
		TEST_METHOD(TestMethod6)
		{
			int x = wordcount("input2.txt", "out.txt", 1);
			Assert::AreEqual(x, 23);
		}TEST_METHOD(TestMethod7)
		{
			int x = linecount("input3.txt", "out.txt");
			Assert::AreEqual(x, 4);
		}TEST_METHOD(TestMethod8)
		{
			
		}TEST_METHOD(TestMethod9)
		{
			int sum = 1;

			for (int i = 1; i <= 10; i++)
			{
				sum *= i;
			}
			Assert::AreEqual(sum, 3628800);
		}TEST_METHOD(TestMethod10)
		{
			int sum = 1;

			for (int i = 1; i <= 10; i++)
			{
				sum *= i;
			}
			Assert::AreEqual(sum, 3628800);
		}

	};
}