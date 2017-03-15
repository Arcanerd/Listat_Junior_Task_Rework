#include "stdafx.h"
#include "CppUnitTest.h"

#include "domParser.h"
#include "Writer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//unit tests should be named in accordance with some templates
// test name should be meaningful: developers have to gain from the name of a failed test as much as possible



namespace Listat_Junior_UnitTest
{		
	TEST_CLASS(TC_Cinterval)
	{
	public:
		TEST_METHOD(Cinterval_Test_1)//Cinterval_Constructors_Test
		{
			cinterval cint(0, 1);
			Assert::AreEqual(0, cint.low);
			Assert::AreEqual(1, cint.high);
		}

	};

	TEST_CLASS(TC_domNode)
	{
	public:
		TEST_METHOD(domNode_Test_1)
		{
			domNode dom_node1(std::string("tag"));
		}
	};

	TEST_CLASS(TC_domParser)
	{
	public:
		TEST_METHOD(domParser_Test_1)
		{
			
		}
	};

	TEST_CLASS(TC_primeThread)
	{
	public:
		TEST_METHOD(primeThread_Test_1)
		{
			primeThread thread;//pay attention to naming: it's strange for developers to find out that thread has method is_prime()
			/*
			Assert::AreEqual(false, thread.is_prime(0));
			Assert::AreEqual(true, thread.is_prime(1));
			Assert::AreEqual(true, thread.is_prime(2));
			Assert::AreEqual(true, thread.is_prime(3));
			Assert::AreEqual(true, thread.is_prime(5));
			Assert::AreEqual(true, thread.is_prime(7));
			*/
		}


		TEST_METHOD(primeThread_Test_2)//combine all these tests and pass input data as std::vector and name it e.g. primeThread_PrimesCalculation_Test
		{
			primeThread thread;
			/*
			Assert::AreEqual(true, thread.is_prime(101));
			Assert::AreEqual(true, thread.is_prime(17));
			Assert::AreEqual(true, thread.is_prime(29));
			Assert::AreEqual(true, thread.is_prime(53));
			Assert::AreEqual(true, thread.is_prime(337));
			*/
		}

		TEST_METHOD(primeThread_Test_3)
		{
			primeThread thread;
			/*
			Assert::AreEqual(false, thread.is_prime(1010));
			Assert::AreEqual(false, thread.is_prime(95));
			Assert::AreEqual(false, thread.is_prime(841));
			Assert::AreEqual(false, thread.is_prime(106));
			Assert::AreEqual(false, thread.is_prime(999));
			*/
		}

		TEST_METHOD(primeThread_Test_42)
		{
			primeThread thread;

			//Assert::AreEqual(true, thread.is_prime(2147483647));
		}
		
	};

	TEST_CLASS(TC_theQueue)
	{
	public:
		//TEST_METHOD(theQueue_Test_1){}

	};

	TEST_CLASS(TC_threadWriter) {
		/*
		TEST_METHOD(threadWriter_Test_1)
		{
			std::vector<std::vector<int>> data;
			std::string _filepath;
			threadWriter tw(_filepath, data);
		}

		TEST_METHOD(threadWriter_Test_2)
		{
			std::vector<std::vector<int>> data;
			std::string filepath("filepath");
			threadWriter tw(filepath, data);

			Assert::AreEqual(filepath, tw.get_filepath());
		}

		TEST_METHOD(threadWriter_Test_3)
		{
			std::vector<std::vector<int>> data;
			std::string filepath("filepath");
			threadWriter tw(filepath, data);
			filepath = "newfilepath";
			tw.set_filepath(filepath);

			Assert::AreEqual(filepath, tw.get_filepath());
		}
		*/
	};
}