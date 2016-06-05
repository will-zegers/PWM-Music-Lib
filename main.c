#include "stdio.h"
#include "stdlib.h"

#define CPU_FREQ 1000000000
#define TEMPO 172

typedef enum note {
	WHOLE     = 60000000 / TEMPO,
	HALF      = 60000000 / (TEMPO*2),
	QUARTER   = 60000000 / (TEMPO*4),
	EIGHTH    = 60000000 / (TEMPO*8),
	SIXTEENTH = 60000000 / (TEMPO*16),
} Note;

typedef enum tone {
	R   = CPU_FREQ,
	C2  = CPU_FREQ/65,
	C3  = CPU_FREQ/131,
	C4  = CPU_FREQ/261,
	G4  = CPU_FREQ/392,
	A4  = CPU_FREQ/440,
	C5  = CPU_FREQ/523,
	Cs5 = CPU_FREQ/554,
	E5  = CPU_FREQ/659,
	F5  = CPU_FREQ/699,
	G5  = CPU_FREQ/785,
	A5  = CPU_FREQ/880,
} Tone;



FILE *period, *duty_cycle, *enable, *disable;

void error(char *msg) {
	perror(msg);
	exit(1);
}

void playSong(Tone song[], int tempo) {

}

void stopTone() {
	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);
	usleep(75000);
}
void rest(Note note) {
	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);
	usleep(note);
}

void playNote(Note note, Tone tone) {
	if ( (fprintf(period, "%d", tone) ) < 0)
		error("fprintf");

	if ( (fprintf(duty_cycle, "%d", tone/2) ) < 0)
		error("fprintf");

	if ( (fprintf(enable, "1") ) < 0)
		error("fprintf");
	fflush(duty_cycle);
	fflush(period);
	fflush(enable);
	printf("%d\r\n", note);
	usleep(note);
}

int main(int argc, char* argv[]) {

	if ( (period = fopen("/sys/class/pwm/pwmchip0/pwm0/period", "w+") ) == NULL)
		error("fopen:period");
	if ( (duty_cycle = fopen("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", "w+") ) == NULL)
		error("fopen:duty_cycle");
	if ( (enable = fopen("/sys/class/pwm/pwmchip0/pwm0/enable", "w+") ) == NULL)
		error("fopen:enable");

	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);

	playNote(QUARTER,E5);
	stopTone();
	playNote(QUARTER,E5);
	stopTone();
	rest(QUARTER);
	stopTone();
	playNote(QUARTER,E5);
	stopTone();
	rest(QUARTER);
	stopTone();
	playNote(QUARTER,C5);
	stopTone();
	playNote(QUARTER,E5);
	stopTone();
	rest(QUARTER);
	stopTone();
	playNote(QUARTER,G5);
	stopTone();
	rest(QUARTER);
	stopTone();
	rest(HALF);
	stopTone();
	playNote(QUARTER, G4);
	stopTone();

	fclose(period);
	fclose(duty_cycle);
	fclose(enable);
}
