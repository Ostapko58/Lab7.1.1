#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1.1/Lab7.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 4;
			const int colCount = 5;
			int s = 0;
			int k = 0;
			int a[rowCount][colCount]
			{
				{1,-1,-1,1,-1},
				{-1,1,1,1,-1},
				{1,1,-1,-1,1},
				{1,1,1,-1,1}
			};
			int b[rowCount][colCount]
			{
				{0,0, -1,0,-1},
				{0,0,0,0,0},
				{0,0,-1,0,0},
				{0,0,0,0,0}
			};
			int* pa[rowCount];
			for (int i = 0; i < rowCount; i++)
			{
				pa[i] = a[i];
			}
			CalcAndReplace(pa, rowCount, colCount, s, k);
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					Assert::AreEqual(a[i][j], b[i][j]);
				}
			}
		}
		
		TEST_METHOD(TestMethod2)
		{
			const int rowCount = 4;
			const int colCount = 5;
			int s = 0;
			int k = 0;
			int a[rowCount][colCount]
			{
				{1,-1,-1,1,-1},
				{-1,1,1,1,-1},
				{1,1,-1,-1,1},
				{1,1,1,-1,1}
			};
			int b[rowCount][colCount]
			{
				{0,0, -1,0,-1},
				{0,0,0,0,0},
				{0,0,-1,0,0},
				{0,0,0,0,0}
			};
			int* pa[rowCount];
			for (int i = 0; i < rowCount; i++)
			{
				pa[i] = a[i];
			}
			CalcAndReplace(pa, rowCount, colCount, s, k);
			Assert::AreEqual(s, 7);
			Assert::AreEqual(k, 17);
		}
	};
}
