#include "stdlib.h"
#include "stdio.h"
#include "tone.h"

FILE *period, *duty_cycle, *enable;

void error(char *msg) {
	perror(msg);
	exit(1);
}

void init() {
	if ( (period = fopen("/sys/class/pwm/pwmchip0/pwm0/period", "w+") ) == NULL)
		error("fopen:period");
	if ( (duty_cycle = fopen("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", "w+") ) == NULL)
		error("fopen:duty_cycle");
	if ( (enable = fopen("/sys/class/pwm/pwmchip0/pwm0/enable", "w+") ) == NULL)
		error("fopen:enable");

	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);
}

void cleanUp() {
	fclose(period);
	fclose(duty_cycle);
	fclose(enable);
}

void rest() {
	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);
}

void stopTone() {
	if ( (fprintf(enable, "0") ) < 0)
		error("fprintf");
	fflush(enable);
	usleep(75000);
}

void playTone(Tone tone) {
	if ( (fprintf(period, "%d", tone) ) < 0)
		error("fprintf");

	if ( (fprintf(duty_cycle, "%d", (tone)/2) ) < 0)
		error("fprintf");

	if ( (fprintf(enable, "1") ) < 0)
		error("fprintf");
	fflush(duty_cycle);
	fflush(period);
	fflush(enable);
}

void playNote(Note note) {
	if (note.tone != PASS) {
		if (note.tone == R)
			rest();
		else
			playTone(note.tone);
		
		usleep(note.beat);
	}
}

void playSong(Note *song, int arrSize) {
	int i = 0;
	while(i < arrSize / sizeof(Note) ) {
		stopTone();
		if (song[i].tone == END) 
			break;
		playNote(song[i++]);
	}
	printf("%d\r\n", i);
	stopTone();
}
