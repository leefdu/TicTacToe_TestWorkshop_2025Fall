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

		TEST_METHOD(VerifySomeCellsIsEmpty)
		{
			Logger::WriteMessage("Checking if cell 1,1 is empty");
			Assert::IsTrue(board.isSquareEmpty(1, 1)); 
		}

		TEST_METHOD(VerifyWriteACell)
		{
			Logger::WriteMessage("Checking if we can write/read"); 
			Assert::IsTrue(board.isSquareEmpty(1, 1)); 
			board.writeSquare(1, 1, TicTacToeBoard::X); 
			Assert::IsTrue(board.isSquareEmpty(1, 1));
			Assert::AreEqual('X',board.getSquareContents(1, 1)); 
			Assert::AreEqual('O', board.getSquareContents(1, 1));
		}

		TEST_METHOD(PlayerXWins)
		{
			Logger::WriteMessage("Testing if the game can identify a Win");
			Assert::IsFalse(board.isWinner(TicTacToeBoard::X));
			Assert::IsFalse(board.isWinner(TicTacToeBoard::O));
			Assert::IsFalse(board.isDraw());

			//Checking if the winning row is in the middle of the board
			board.writeSquare(1, 0, TicTacToeBoard::X);
			board.writeSquare(1, 1, TicTacToeBoard::X);
			board.writeSquare(1, 2, TicTacToeBoard::X);

			Assert::IsTrue(board.isWinner(TicTacToeBoard::X));
			Assert::IsFalse(board.isWinner(TicTacToeBoard::O));
			Assert::IsFalse(board.isDraw());


		}
	};
}
