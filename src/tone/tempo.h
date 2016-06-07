#ifndef TEMPO_H
#define TEMPO_H

#define CPU_FREQ 1000000000
#define TEMPO    120
#define PAUSE    50

typedef enum timing {
	THREEFOUR = 3,
	FOURFOUR = 4,
	SIXEIGHT = 6,
} Timing;

typedef enum beat {
	WHOLE      = (60000000 / (TEMPO/4) ) - PAUSE,
	HALFdot    = (60000000 / (TEMPO/3) ) - PAUSE,
	HALF       = (60000000 / (TEMPO/2) ) - PAUSE,
	QUARTERdot = (60000000 / (TEMPO*2/3) ) - PAUSE,
	QUARTER    = (60000000 / (TEMPO) ) - PAUSE,
	TRIP       = (60000000 / (TEMPO*3/2) ) - PAUSE,
	EIGHTH     = (60000000 / (TEMPO*2) ) - PAUSE,
	SIXTEENTH  = (60000000 / (TEMPO*4) ) - PAUSE,
} Beat;

#endif
