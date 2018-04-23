/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, turn_was_x)
{
	TicTacToeBoard obj;
	ASSERT_TRUE(obj.toggleTurn() == O);
}

TEST(TicTacToeBoardTest, turn_toggle_second)
{
	TicTacToeBoard obj;
    obj.toggleTurn();
	ASSERT_EQ(obj.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, set_piece_0_0_x)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, out_of_bounds_greater)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(3,3), Invalid);
}

TEST(TicTacToeBoardTest, out_of_bound_lower)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(-1, -1), Invalid);
}

TEST(TicTacToeBoardTest, same_position)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.placePiece(0,0), X);
}

TEST(TicTacToeBoardTest, get_blank)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(1,1), Blank);
}

TEST(TicTacToeBoardTest, invalid_get)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(-1,3), Invalid);
}

TEST(TicTacToeBoardTest, get_placed_value)
{
    TicTacToeBoard obj;
    obj.placePiece(0,0);
    ASSERT_EQ(obj.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, check_if_win_X)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,0);
	obj.placePiece(0,1);
	obj.placePiece(2,0);
	obj.placePiece(0,2);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, check_if_win_O)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(1,0);
	obj.placePiece(0,1);
	obj.placePiece(2,0);
	obj.placePiece(2,2);
	obj.placePiece(0,0);
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, check_invalid_win)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getWinner(), Invalid);
}
