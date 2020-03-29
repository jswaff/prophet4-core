#include "search_internal.h"

#include <string.h>

/**
 * \brief Initialize move ordering
 *
 * \param mo            pointer to the move ordering data structure
 * \param stackptr      pointer to move stack to place new moves on
 * \param killer1       killer move 1
 * \param killer2       killer move 2
 */
void initialize_move_ordering(move_order_dto* mo, move_t* stackptr,
    move_t killer1, move_t killer2)
{
    memset(mo, 0, sizeof(move_order_dto));
    mo->next_stage = GEN_CAPS;
    mo->start = stackptr;
    mo->killer1 = killer1;
    mo->killer2 = killer2;
}