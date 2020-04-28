/* timer.h */

#ifndef _DEF_INC_TIMER
#define _DEF_INC_TIMER

#include <stdint.h>
#include "cpu.h"

// prototypes
void TimerInit( void );

static inline uint16_t TimerGetUsec( void )
{
   TimerRegs *tmr = (TimerRegs *)TIMER16_BASE;
   return tmr->counter;
}

static inline uint16_t UsecSince( uint16_t when )
{
   TimerRegs *tmr = (TimerRegs *)TIMER16_BASE;
   return tmr->counter - when;
}

static inline void BusyWait( uint16_t usec )
{
   while( usec > 1000 )
   {
      BusyWait(1000);
      usec -= 1000;
   }

   uint16_t start = TimerGetUsec();
   while( UsecSince( start ) < usec ){}
}

#endif
