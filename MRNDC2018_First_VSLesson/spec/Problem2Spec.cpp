#include "stdafx.h"
#include "../src/Problem2.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem2Spec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 

		int string_length(char *str){
			int i;
			for (i = 0; str[i] != '\0'; i++);
			return i;
		}

		bool string_compare(char *str1, char *str2){
			int i;

			if (str1 == NULL && str2 == NULL){
				return true;
			}

			if (str1 == NULL || str2 == NULL)
				return false;

			for (i = 0; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++);

			if (i != string_length(str1) || str1[i] != '\0' || str2[i] != '\0')
				return false;
			return true;	
		}

		[TestMethod, Timeout(1000)]
		void P2_SimpleTestCase1()
		{
			char *str1 = "123";
			char *str2 = "111";
			char *op = "234";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_SimpleTestCase2()
		{
			char *str1 = "111";
			char *str2 = "111";
			char *op = "222";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_LengthPlusOne()
		{
			char *str1 = "500";
			char *str2 = "500";
			char *op = "1000";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_NegativeSign()
		{
			char *str1 = "-111";
			char *str2 = "222";
			char *op = "111";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_PlusSign()
		{
			char *str1 = "+111";
			char *str2 = "+111";
			char *op = "222";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_NullCheck1()
		{
			char *str1 = NULL;
			char *str2 = NULL;
			char *op = NULL;
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_NullCheck2()
		{
			char *str1 = "111";
			char *str2 = NULL;
			char *op = "111";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_NullCheck3()
		{
			char *str1 = NULL;
			char *str2 = "222";
			char *op = "222";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_ZerosCheck()
		{
			char *str1 = "22222222222000";
			char *str2 = "22222222222111";
			char *op   = "44444444444111";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P2_LongNumberCheck()
		{
			char *str1 = "+01234567801234500000000000000000001";
			char *str2 = "+11111111111111100000000000000000001";
			char *op   =  "12345678912345600000000000000000002";
			Assert::AreEqual(string_compare(addNumberStrings(str1, str2), op), true, L"Failed for Invalid case P1", 1, 2);
		};

	};
}
