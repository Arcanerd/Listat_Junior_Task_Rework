#include "stdafx.h"
#include "CppUnitTest.h"

#include "domParser.h"
#include "Writer.h"
#include "utilityFunctions.h"
#include "domNode.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//unit tests should be named in accordance with some templates
// test name should be meaningful: developers have to gain from the name of a failed test as much as possible



namespace Listat_Junior_UnitTest
{		
	TEST_CLASS(TC_Cinterval)
	{
	public:
		TEST_METHOD(Cinterval_Constructors_Test)
		{
			cinterval cint(0, 1);
			Assert::AreEqual(0, cint.low);
			Assert::AreEqual(1, cint.high);
		}

	};

	TEST_CLASS(TC_domNode)
	{
		typedef std::shared_ptr<domNode> spNode;

	public:
		TEST_METHOD(domNode_Constructors_Test)
		{
			std::string tag = "tag";			
			spNode nulshptr = nullptr;
			cinterval interval(0, 0);
				
			//global
			domNode(tag, nulshptr, nulshptr, nulshptr, interval);
			//for root
			domNode dom_node1(tag);
			//for noninterval basic
			domNode(tag, nulshptr);
			//for noninterval
			domNode(tag, nulshptr, nulshptr, nulshptr);
			//for interval
			domNode(tag, nulshptr, interval);
		}
	};

	TEST_CLASS(TC_domParser)
	{
	public:
		TEST_METHOD(domParser_Test_1)
		{
			
		}
	};

	TEST_CLASS(TC_utilityFunctions)
	{
	public:
		TEST_METHOD(PrimesCalculation_Test)
		{
			
			//pay attention to naming: it's strange for developers to find out that thread has method is_prime()
		 
			std::vector<int> primes_set1 = {1, 2, 3, 5, 7, 17, 29, 53, 101, 337, 2147483647};
			std::vector<int> not_primes_set1 = {0, 4, 6, 8, 9, 10, 95, 106, 841, 999, 1010 };

			for (int candidate : primes_set1)
				Assert::AreEqual(true, myUtilities::is_prime(candidate));
			
			for (int candidate : not_primes_set1)
				Assert::AreEqual(false, myUtilities::is_prime(candidate));
		}		
		TEST_METHOD(remove_insignificant_spaces_test)
		{
		}

		TEST_METHOD(extrcat_tag_test)
		{
			std::string expected_result = "<tag>";
			
			std::string input = "<tag> symbols";			
			Assert::AreEqual(expected_result, myUtilities::extrcat_tag(input));

			input = "<tag>symbols";
			Assert::AreEqual(expected_result, myUtilities::extrcat_tag(input));
		}

		TEST_METHOD(extract_bound_test_no_spaces)
		{
			int expected_result = 100;
			std::string input;
			
			//no spaces
			input = "<tag>100</tag>";
			Assert::AreEqual(expected_result, myUtilities::extract_bound(input));
			
		}

		TEST_METHOD(extract_bound_test_space_before)
		{
			int expected_result = 100;
			std::string input;

			//space before number
			input = "<tag> 100</tag>";
			Assert::AreEqual(expected_result, myUtilities::extract_bound(input));
		}

		TEST_METHOD(extract_bound_test_space_after)
		{
			int expected_result = 100;
			std::string input;

			//space after number
			input = "<tag>100 </tag>";
			Assert::AreEqual(expected_result, myUtilities::extract_bound(input));
		}

		TEST_METHOD(extract_bound_test_spaces_before_AND_after)
		{
			int expected_result = 100;
			std::string input;

			//space before AND after number
			input = "<tag> 100 </tag>";
			Assert::AreEqual(expected_result, myUtilities::extract_bound(input));
		}

		TEST_METHOD(extract_bound_test_disrupted_number)
		{
			int expected_result = 100;
			std::string input;

			//
			input = "<tag> 10f0 </tag>";
			Assert::AreNotEqual(expected_result, myUtilities::extract_bound(input));
		}
	};

	TEST_CLASS(TC_primeThread)
	{
	public:
		TEST_METHOD(primeThread_Constructors_Test)
		{


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