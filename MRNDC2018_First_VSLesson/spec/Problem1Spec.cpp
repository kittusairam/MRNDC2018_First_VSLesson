#include "stdafx.h"
#include "../src/Problem1.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem1Spec
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

		[TestMethod, Timeout(1000)]
		void P1_SimpleTestCase()
		{
			int actualAns = reverseNumber(123);
			int expectedAns = 321;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_NegativeCheck()
		{
			int actualAns = reverseNumber(-123);
			int expectedAns = -321;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_NullCheck()
		{
			int actualAns = reverseNumber(NULL);
			int expectedAns = NULL;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_TensMultipleCheck()
		{
			int actualAns = reverseNumber(1000);
			int expectedAns = 1;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_SingleDigitCheck()
		{
			int actualAns = reverseNumber(01);
			int expectedAns = 1;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_OverflowCheck()
		{
			int actualAns = reverseNumber(1123456789);
			int expectedAns = 0;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_MaxIntCheck()
		{
			int actualAns = reverseNumber(2147483647);
			int expectedAns = 0;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_PalindromeCheck()
		{
			int actualAns = reverseNumber(72700);
			int expectedAns = 727;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void P1_SingleDigitNegativeCheck()
		{
			int actualAns = reverseNumber(-1);
			int expectedAns = -1;
			Assert::AreEqual(expectedAns, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

	};
}
