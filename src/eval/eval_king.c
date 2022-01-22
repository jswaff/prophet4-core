#include "eval_internal.h"

#include  <assert.h>

/**
 * \brief Evaluate a single king.
 * 
 * TODO: separate endgame evaluation to another method.  Do not scale king
 * safety in this function.  Instead, try to smooth the two scores based
 * on material on the board.
 *
 * \param pos           a pointer to a chess position
 * \param sq            the square the king is on
 * \param endgame       if the eval should be done in the endgame phase
 *
 * \return a score for the king.
 */
int32_t eval_king(const position_t* pos, square_t sq, bool endgame)
{
    assert(pos->piece[sq] == KING || pos->piece[sq] == -KING);
    assert(sq == pos->white_king || sq == pos->black_king);

    int32_t score = 0; 

    if (is_white_piece(pos->piece[sq]))
    {
        if (endgame)
        {
            score = king_endgame_pst[sq];
        }
        else
        {
            score = king_pst[sq];
            score += eval_king_safety(pos, true);
        }
    }
    else
    {
        if (endgame)
        {
            score = king_endgame_pst[flip_rank[sq]];
        }
        else
        {
            score = king_pst[flip_rank[sq]];
            score += eval_king_safety(pos, false);
        }
    }

  
    return score;    
}
