#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../TicTacToe_Fall2023/TicTacToeBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeStudentAutomatedTests)
	{
		TicTacToeBoard board;

	public:

		TEST_CLASS_INITIALIZE(_Setup_BoardClassTest)
		{
			// this method is run once for the TicTacToeTest class
			//    intentionally blank (other than the log message) - nothing to initialize at this time
			Logger::WriteMessage("Test class initialized\n");
		}

		TEST_METHOD_INITIALIZE(_Setup_MethodTest) {
			// this method is run prior to EVERY test case inside the class (ie this file)
			Logger::WriteMessage("Initializing Board object for additional tests.\n");
			board.resetBoard();          // reinitialize board via method, rather than creating a new board object
		}

		TEST_METHOD(HelloStudentTests) {
			Logger::WriteMessage("Running student tests on the Board object");
			Assert::IsTrue(true);
		}

		TEST_METHOD(VerifySomeCellIsEmpty)
		{
			Logger::WriteMessage("Checking if cell 1,1 is empty");
			Assert::IsTrue(board.isSquareEmpty(1, 1));
		}
		TEST_METHOD(VerifyWriteACell)
		{
			Logger::WriteMessage("Checking if write and read");
			Assert::IsTrue(board.isSquareEmpty(1, 1));
			board.writeSquare(1, 1, TicTacToeBoard::X);
			Assert::IsTrue(board.isSquareEmpty(1, 1));
		}
	};
}
