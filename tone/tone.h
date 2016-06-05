#ifndef TONE_H
#define TONE_H

#define CPU_FREQ 1000000000
#define TEMPO    200

typedef enum beat {
	WHOLE     = 60000000 / TEMPO,
	HALF      = 60000000 / (TEMPO*2),
	TRIP      = 60000000 / (TEMPO*3),
	QUARTER   = 60000000 / (TEMPO*4),
	EIGHTH    = 60000000 / (TEMPO*8),
	SIXTEENTH = 60000000 / (TEMPO*16),
} Beat;

typedef enum tone {
	R   = 0,
	C2  = CPU_FREQ/65,
	C3  = CPU_FREQ/131,
	C4  = CPU_FREQ/261,
	E4  = CPU_FREQ/329,
	G4  = CPU_FREQ/392,
	Gs4 = CPU_FREQ/415,
	A4  = CPU_FREQ/440,
	As4 = CPU_FREQ/466,
	B4  = CPU_FREQ/493,
	C5  = CPU_FREQ/523,
	Cs5 = CPU_FREQ/554,
	D5  = CPU_FREQ/587,
	Ds5 = CPU_FREQ/622,
	E5  = CPU_FREQ/659,
	F5  = CPU_FREQ/699,
	Fs5 = CPU_FREQ/740,
	G5  = CPU_FREQ/785,
	A5  = CPU_FREQ/880,
	C6  = CPU_FREQ/1046,
	END = -42
} Tone;

typedef struct note {
	Tone tone;
	Beat beat;
} Note;

void error(char *msg);

void init();
void cleanUp();

void rest();
void stopTone();
void playTone(Tone);
void playNote(Note);
void playSong(Note *, int);

#endif
