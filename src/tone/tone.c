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
	fprintf(enable, "0");
	fflush(enable);
}

void stopTone() {
	fprintf(enable, "0");
	fflush(enable);

	usleep(PAUSE);
}

void playTone(Tone tone) {
	fprintf(period, "%d", tone);
	fprintf(duty_cycle, "%d", (tone)/2);
	fprintf(enable, "1");

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
		stopTone();
	}
}

void playSong(Note *song) {
	playSongAt(0, song);
}

void playSongAt(int idx, Note *song) {
	while(1) {
		if (song[idx].tone == END) {
			break;
		}
		playNote(song[idx++]);
	}
	stopTone();
}
