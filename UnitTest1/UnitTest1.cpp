#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab14_PDS\Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestIrreflexiveTrue)
		{
			Graph g(3);
			g.addEdge(0, 1);
			g.addEdge(1, 2);
			Assert::IsTrue(g.isIrreflexive());
		}

		TEST_METHOD(TestIrreflexiveFalse)
		{
			Graph g(3);
			g.addEdge(0, 0);
			g.addEdge(1, 2);
			Assert::IsFalse(g.isIrreflexive());
		}

		TEST_METHOD(TestAsymmetricTrue)
		{
			Graph g(3);
			g.addEdge(0, 1);
			g.addEdge(1, 2);
			Assert::IsTrue(g.isAssymetric());
		}

		TEST_METHOD(TestAsymmetricFalse)
		{
			Graph g(3);
			g.addEdge(0, 1);
			g.addEdge(1, 0);
			Assert::IsFalse(g.isAssymetric());
		}
	};
}