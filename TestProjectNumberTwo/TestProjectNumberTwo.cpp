#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProjectNumberTwo
{
	TEST_CLASS(TestProjectNumberTwo)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Logger::WriteMessage("Hello From Test Project #2\n");
		}
	};
}
