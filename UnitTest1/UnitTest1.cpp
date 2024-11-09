#include "pch.h"
#include "CppUnitTest.h"
#include "../lb10.01/lb10.01.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFindHighestAverageSubject)
		{
			// ����������� ������� �������
			double avgPhysics = 4.6;
			double avgMath = 4.8;
			double avgInformatics = 4.7;

			// ������ ������� ��� ���������� �������� � �������� ������� �����
			string highestSubject = findHighestAverageSubject(avgPhysics, avgMath, avgInformatics);

			// �������� ����������
			Assert::AreEqual(string("Math"), highestSubject);
		}
	};
}
