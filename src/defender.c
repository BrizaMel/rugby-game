// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

bool equal_directions_defender(direction_t d1, direction_t d2) {
  return d1.i == d2.i && d1.j == d2.j;
}

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  
  direction_t direction[9] = { 
    DIR_DOWN, 
    DIR_DOWN_LEFT, 
    DIR_DOWN_RIGHT, 
    DIR_LEFT, 
    DIR_RIGHT, 
    DIR_STAY,
    DIR_UP, 
    DIR_UP_LEFT,
    DIR_UP_RIGHT};

    static position_t defender_previous_pos = { ULONG_MAX, ULONG_MAX };
    static direction_t defender_previous_dir = { 2, 2 };
    
    srand((unsigned) time(NULL));
    direction_t defender_next_dir = direction[rand() % 9]; 

    if (equal_positions(defender_previous_pos, defender_position)) {
      while (equal_directions_defender(defender_previous_dir, defender_next_dir)) {
        defender_next_dir = direction[rand() % 9]; 
      }
    }

    defender_previous_pos = defender_position;
    defender_previous_dir= defender_next_dir;

    UNUSED(attacker_spy);

  return defender_next_dir;
}

/*----------------------------------------------------------------------------*/
