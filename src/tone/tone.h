#ifndef TONE_H
#define TONE_H

#include "tempo.h"

#define CPU_FREQ 1000000000

typedef enum tone {
	PASS = -1,
	R   = 0,
	C2  = CPU_FREQ/65,
	D2  = CPU_FREQ/73,
	E2  = CPU_FREQ/82,
	F2  = CPU_FREQ/87,
	G2  = CPU_FREQ/98,
	Gs2 = CPU_FREQ/104,
	A2  = CPU_FREQ/110,
	As2 = CPU_FREQ/117,
	C3  = CPU_FREQ/131,
	Ds3 = CPU_FREQ/155,
	D3  = CPU_FREQ/147,
	E3  = CPU_FREQ/165,
	F3  = CPU_FREQ/176,
	Fs3 = CPU_FREQ/185,
	G3  = CPU_FREQ/196,
	Gs3 = CPU_FREQ/207,
	A3  = CPU_FREQ/220,
	As3 = CPU_FREQ/233,
	B3  = CPU_FREQ/247,
	C4  = CPU_FREQ/261,
	Cs4 = CPU_FREQ/277,
	D4  = CPU_FREQ/294,
	Ds4 = CPU_FREQ/311,
	E4  = CPU_FREQ/330,
	F4  = CPU_FREQ/349,
	Fs4 = CPU_FREQ/369,
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
void playSong(Note *);
void playSongAt(int, Note *);

#endif
