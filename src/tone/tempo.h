#ifndef TEMPO_H
#define TEMPO_H

#define CPU_FREQ 1000000000
#define TEMPO    300

typedef enum timing {
	THREEFOUR = 3,
	FOURFOUR = 4,
	SIXEIGHT = 6,
} Timing;

typedef enum beat {
	WHOLE      = 60000000 / (TEMPO/4),
	HALFdot    = 60000000 / (TEMPO/3),
	HALF       = 60000000 / (TEMPO/2),
	QUARTERdot = 60000000 / (TEMPO*2/3),
	QUARTER    = 60000000 / (TEMPO),
	TRIP       = 60000000 / (TEMPO*3/2),
	EIGHTH     = 60000000 / (TEMPO*2),
	SIXTEENTH = 60000000 / (TEMPO*4),
} Beat;

#endif
