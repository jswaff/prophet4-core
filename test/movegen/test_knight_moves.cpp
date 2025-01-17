#include "movegen/movegen_internal.h"

#include "prophet/move.h"
#include "prophet/position.h"

#include <gtest/gtest.h>


TEST(movegen_test, knight_moves_initial_pos)
{
    position_t pos;
    reset_pos(&pos);

    move_t moves[10];
    move_t* mp = gen_knight_moves(moves, &pos, true, true);

    EXPECT_EQ(mp - moves, 4);

    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, B1, A3), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, B1, C3), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, G1, F3), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, G1, H3), moves, mp));
}

TEST(movegen_test, knight_moves_captures)
{
    position_t pos;
    set_pos(&pos,"4k3/8/3P1p2/8/4N3/8/8/4K3 w - - 0 1");

    move_t moves[10];
    move_t* mp = gen_knight_moves(moves, &pos, true, false);

    EXPECT_EQ(mp - moves, 1);

    EXPECT_TRUE(move_list_contains(to_capture(KNIGHT, E4, F6, PAWN), moves, mp));
}

TEST(movegen_test, knight_moves_noncaptures)
{
    position_t pos;
    set_pos(&pos,"4k3/8/3P1p2/8/4N3/8/8/4K3 w - - 0 1");

    move_t moves[10];
    move_t* mp = gen_knight_moves(moves, &pos, false, true);

    EXPECT_EQ(mp - moves, 6);

    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, G5), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, G3), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, F2), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, D2), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, C3), moves, mp));
    EXPECT_TRUE(move_list_contains(to_move(KNIGHT, E4, C5), moves, mp));
}
