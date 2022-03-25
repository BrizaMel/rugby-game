// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/
bool equal_directions_attacker(direction_t d1, direction_t d2) {
  return d1.i == d2.i && d1.j == d2.j;
}

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  
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

    static position_t attacker_previous_pos = { ULONG_MAX, ULONG_MAX };
    static direction_t attacker_previous_dir = { 2, 2 };
    
    srand((unsigned) time(NULL));
    direction_t attacker_next_dir = direction[rand() % 9]; 

    if (equal_positions(attacker_previous_pos, attacker_position)) {
      while (equal_directions_attacker(attacker_previous_dir, attacker_next_dir)) {
        attacker_next_dir = direction[rand() % 9]; 
      }
    }

    attacker_previous_pos = attacker_position;
    attacker_previous_dir = attacker_next_dir ;

    UNUSED(defender_spy);
  
  return attacker_next_dir;
}

/*----------------------------------------------------------------------------*/
