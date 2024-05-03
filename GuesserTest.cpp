/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, CorrectGuess)
{
    Guesser guesser("hello");
    ASSERT_TRUE(guesser.match("hello"));
    ASSERT_EQ(guesser.remaining(), 3);
}

TEST(GuesserTest, IncorrectGuess)
{
    Guesser guesser("hello");
    ASSERT_FALSE(guesser.match("world"));
    ASSERT_EQ(guesser.remaining(), 2);
}

TEST(GuesserTest, BruteForce)
{
    Guesser guesser("hello");
    ASSERT_FALSE(guesser.match("z"));
    ASSERT_EQ(guesser.remaining(), 2);
}

TEST(GuesserTest, ExhaustRemainingGuesses)
{
    Guesser guesser("hello");
    guesser.match("world");
    guesser.match("earth");
    ASSERT_FALSE(guesser.match("moon"));
    ASSERT_EQ(guesser.remaining(), 0);
    ASSERT_FALSE(guesser.match("sun"));
    ASSERT_EQ(guesser.remaining(), 0);
}

TEST(GuesserTest, ResetGuessesOnCorrectGuess)
{
    Guesser guesser("hello");
    guesser.match("world");
    guesser.match("earth");
    ASSERT_TRUE(guesser.match("hello"));
    ASSERT_EQ(guesser.remaining(), 3);
}

TEST(GuesserTest, TruncateSecret)
{
    Guesser guesser("abcdefghijklmnopqrstuvwxyz1234567890");
    ASSERT_EQ(guesser.remaining(), 3);
}

TEST(GuesserTest, EmptySecret)
{
    Guesser guesser("");
    ASSERT_TRUE(guesser.match(""));
    ASSERT_EQ(guesser.remaining(), 3);
}